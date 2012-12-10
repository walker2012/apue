
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<errno.h>
#include<unistd.h>


int g_Flag = 0;

pthread_mutex_t flag_mutex = PTHREAD_MUTEX_INITIALIZER;


void* thread1(void* arg){


    printf("Enter thread1:\n");

    pthread_mutex_lock(&flag_mutex);
    printf("this is thread1:pid= %d, flag =%d \n",(unsigned int)pthread_self(),g_Flag);
    g_Flag = 1;
    printf("this is thread1:pid= %d, flag =%d \n",(unsigned int)pthread_self(),g_Flag);
    pthread_mutex_unlock(&flag_mutex);
    pthread_join(*(pthread_t*) arg, NULL);
    printf("Leave thread1:flag = %d \n",g_Flag);
    pthread_exit((void*)1);

}
void* thread2(void* arg ){

    printf("Enter thread2:\n");
    pthread_mutex_lock(&flag_mutex);
    printf("this is thread2:pid= %d,flag = %d\n",(unsigned int)pthread_self(), g_Flag);
    g_Flag = 2;
    printf("this is thread2:pid= %d,flag = %d\n",(unsigned int)pthread_self(), g_Flag);
    pthread_mutex_unlock(&flag_mutex);
    printf("Leave thread2:flag = %d\n", g_Flag);
    pthread_exit((void*)2);

}



int main(int argc,char* argv[]){

    int rc1 = 0,rc2 = 0;
    pthread_t pid1,pid2;

    printf("enter main:\n");

    rc2 = pthread_create(&pid2,NULL,thread2, NULL);
    if(rc2 != 0){
        printf("error2\n");
    }

    rc1 = pthread_create(&pid1,NULL,thread1, &pid2);
    if(rc1 != 0){
        printf("error1\n");
    }


    //pthread_join(pid2, NULL);
    pthread_join(pid1, NULL);

    printf("leave main\n");
    exit(0);
}

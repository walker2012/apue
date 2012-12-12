/// @file cond.c
/// @brief pthread_cond example 
/// @author yanbin.yuan@renren-inc.com
/// @version 1.0
/// @date 2012-12-12

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>



int x = 0,y = 0;
pthread_mutex_t mux = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;



void* xy(void *arg){

    pthread_mutex_lock(&mux);

    x=1;
    y=2;
    printf("%d,%d\n", x,y);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mux);
    pthread_exit((void *) 0);
    //return (void *)0;
}

int main(int argc, char* argv){

    pthread_t pid;

    printf("%d,%d\n",x,y);
    pthread_create(&pid, NULL,xy,NULL);
    pthread_mutex_lock(&mux);

    while(x>=y){
    pthread_cond_wait(&cond,&mux);
    }
    printf("ok,it is time to go!\n");


    pthread_mutex_unlock(&mux);


    exit(0);
}


#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


int main(){

    pid_t pid;

    if((pid=fork())<0){
        printf("fork error");
    
    }else if(pid==0){
    
        if(execl("/home/yyb/apue/echoarg","testinterp0001","myarg1","MY ARG2",(char *)0)<0){
        
                printf("execl error");
        
        }
    
    }

    if(waitpid(pid,NULL,0)<0){

        printf("waitpid error");
    
    }


    return 0;
}

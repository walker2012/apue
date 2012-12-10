
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main(int argc,char *argv[]){


    printf("name is:%s\n",getlogin());
    exit(0);
}



#include <stdlib.h>
#include <stdio.h>



int* f1(int val){


    int *ptr;
    if(val == 0){
    
        int val;
        val=5;
        ptr=&val;
    
    }

    return ptr;

}

int main(){

    int *result;

    result=f1(0);

    printf("%d\n",*result);

    return 0;

}

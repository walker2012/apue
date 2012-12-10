
#include <stdio.h>

int main(){


    int *p;
    int a=1;
    void *q;
    p=&a;
    q=(void *)2;
    printf("%d\n",*p);
    printf("%d\n",(int)q);

}

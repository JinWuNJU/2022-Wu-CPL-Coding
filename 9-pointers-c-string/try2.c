#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//以后还是乖乖用二重指针数组吧。。。。。。
int main(){
    char **p=malloc(1555);
    for(int i=0;i<1555;i++){
        *(p+i)=malloc(15);
    }printf("%d %d %d\n",sizeof(**p),sizeof(*p),sizeof(*(*(p+1)+1)));
    char **a=malloc(22221*10*sizeof(**a));
    for(int i=0;i<10000;i++){
        *(a+i)=malloc(1000);
    }
    *(a+100)="hello";
    strcpy(a[20],"const");
    printf("%s",*(a+20));
    return 0;
}
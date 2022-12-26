#include<stdio.h>
void swap(int *a,int *b){
    int p=*a;
    *a=*b;
    *b=p;
}
int main(){
    int a=1;
    int b=2;
    swap(&a,&b);
    printf("%d %d",a,b);
    return 0;
}
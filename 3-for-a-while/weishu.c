#include<stdio.h>
int main(){
    int n=0;
    scanf("%d",&n);
    int i=0;
    do{
        n/=10;
        i++;
    }while(n!=0);
    printf("%d",i);
    return 0;
}
#include<stdio.h>
int main(){
    long long sum=0;
    int d1=0;
    int d2=1;
    int n=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum=d1+d2;
        d1=d2;
        d2=sum;
    }printf("%lld",sum);
}
#include<stdio.h>
long long sanjiao(int a,int b){
    if(b==1){
        return a;
    }else if(a==b){
        return 1;
    }
    long long m=sanjiao(a-1,b)+sanjiao(a-1,b-1);
    return m;
}
int main(){
    int a=0,b=0;
    scanf("%d%d",&a,&b);
    printf("%lld",sanjiao(a-1,b-1));


    return 0;
}
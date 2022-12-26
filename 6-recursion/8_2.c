#include<stdio.h>
#include<math.h>
int inverse(long n){
    long sum=0;
    do{
        int tem=n%10;
        sum=sum*10+tem;
        n/=10;
    }while(n!=0);
    return sum;
}
int weishu(long n){
    int weishu=0;
    do{
        n/=10;
        weishu++;
    }while(n!=0);
    return weishu;
}
int judge(long n){
    int a[100];
    int bool=1;
    int t=weishu(n);
    int m=n;
    for(int i=1;i<=t;i++){
        a[i]=m%10;
        m/=10;
    }for(int i=1,j=weishu(n);i<=j;i++,j--){
        if(a[i]!=a[j]){
            bool=0;
            return bool;
        }
    }return bool;

}
int main(){
    long int n=0;
    scanf("%ld",&n);
    int count=0;
    while(judge(n)==0&&count<=10000){
        long p=n+inverse(n);
        n=p;
         printf("%ld,%d",n,count);

     count++;
    }if(count<=10000){
      }else{
        printf("-1");
    }

    return 0;
} 
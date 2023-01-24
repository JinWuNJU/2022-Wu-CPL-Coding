#include<stdio.h>
int inverse(int n){
    int sum=0;
    do{int tem=n%10;
    sum=sum*10+tem;
    n/=10;
    }while(n!=0);
    return sum;
}
int main(){
    for(int i=100;i<10000;i++){
        if(9*i==inverse(i)){
            printf("%d-----%d",i,inverse(i));
        }
    }
    return 0;
}
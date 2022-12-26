#include<stdio.h>
#include<math.h>
int IsPrime(int n){
    if(n==1){
        return 0;
    }for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }return 1;
}
int main(){
    int x[15]={0,8,25,128,87,54,137,23,96,165,4};
    int max=0;
    int prime=0;
    int index1,index2;
    for(int i=1;i<=10;i++){
        if(x[i]%2==0){
            if(max<x[i]){
                max=x[i];
                index1=i;
            }
        }      
    }for(int j=10;j>=1;j--){
        if(IsPrime(x[j])==1){
            index2=j;
            break;
        }
    }
    int p=index2-index1+1;
    int min=x[index1];
    for(int j=index1;j<=index2;j++){
    for(int k=j;k<=index2;k++){
        if(min>x[k]){
            min=x[k];
            int tem=x[j];
            x[j]=min;
            x[k]=tem;
           
        }
        
    } min=x[j+1];
    }
    for(int i=1;i<=10;i++){
        printf("%d ",x[i]);
    }printf("\n%d",p);
    return 0;
}
//8  25  128  87  54  137  23  96  165  4
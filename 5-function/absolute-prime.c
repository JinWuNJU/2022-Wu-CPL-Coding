#include<stdio.h>
#include<math.h>
int IsPrime(int n);
int Inverse(int n);
int main(){
    int n=0;
    scanf("%d",&n);
    int count=0;
    for(int i=1;i<=n;i++){
        if(IsPrime(i)==1&&IsPrime(Inverse(i))==1){
            count++;
        }
    }if(n==0){
        count=1;
    }
        printf("%d",count-1);


    return 0;
}
int IsPrime(int n){
    int bool=1;
    for(int i=2;i<=floor(sqrt(n));i++){
        if(n%i==0){
            bool=0;
            break;
        }
    }return bool;
}
int Inverse(int n){//too complicated!!! another method in 7_1.c
    int tem=n;
    int sum=0;
    int cut=1;
     int i=0;
    do{
        n/=10;
        i++;
    }while(n!=0);
    do{
        int p=tem%10;
        sum+=p*pow(10,i-cut);
        tem/=10;
        cut++;

    }while(tem!=0);
    return sum;
}
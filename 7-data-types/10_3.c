#include<stdio.h>
#include<math.h>
int IsPrime(int n){
    if(n==1){
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }return 1;
}
int main(){
    int aa[1000];
    int cut=0;
    for(int i=500;i<=800;i++){
       if(IsPrime(i)==1){
        cut++;
        aa[cut]=i;
       }
    }for(int j=1;j<=cut;j++){
        printf("%d   ",aa[j]);
        if(j%10==0){
            printf("\n");
        }
    }
    return 0;
}
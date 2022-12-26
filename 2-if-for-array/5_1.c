#include<stdio.h>
#include<math.h>
int main(){
    int n;
    int a,b,c,d;
    for(n=100;n<1000;n++){
        int i;
        for( i=2;i<=sqrt(n);i++){
            if(n%i==0){
              break;
            };
        }if(i>sqrt(n)){
        c=n%10;
        d=n/10;
        b=d%10;
        a=n/100;
        if((c+b)%10==a){
            printf("%d\t",n);
        }
        }

    }
    return 0;
}
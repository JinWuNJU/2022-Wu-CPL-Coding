#include<stdio.h>
#include<math.h>
int main(){
    double x;
    int n;
    scanf("%lf %d",&x,&n);
    double b;
    double c;
    double sum1=0;
    double sum2=0;
    for(int i=1;i<=2*n+1;i+=4){
       sum1=sum1+pow(x,i)/i;
    }for(int j=3;j<=2*n+1;j+=4){
       sum2=sum2+pow(x,j)/j;
    }printf("%.10lf",4*(sum1-sum2));



    return 0;
}
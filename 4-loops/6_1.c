#include<stdio.h>
#include<math.h>
#define EXP 1e-8
int jiechen(int n){
    int suum=1;
    for(int p=1;p<=n;p++){
        suum*=p;

    }return suum;
}
int main(){
    double x=0;
    scanf("%lf",&x);
    double sum=1.0;
    double f=0.0;
    for(int i=1;;i=i+2){
        if(i%4==1){
            for(int j=1;j<=i;j++){
                sum*=x/j*1.0;
            }f+=sum;
            sum=1.0;
     
        }else{
             for(int j=1;j<=i;j++){
                sum*=x/j*1.0;
            }sum=-sum;
            f+=sum;
            sum=1.0;
           
        }double q=fabs(f)-sin(x);
        if(q<=EXP){
            break;
        }

    }printf("%.1lf",f);
    return 0;
}
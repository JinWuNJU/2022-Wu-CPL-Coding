#include<stdio.h>
#include<math.h>
#define eps 1e-6
double f(double x){
    double m=2*x*x*x-4*x*x+3*x-6;
    return m;
}
int main(){
    double a=0.0,b=3.0;
     double c=(a*f(b)-b*f(a))/(f(b)-f(a));
            while(fabs(f(c))>=eps&&fabs(b-a)>=eps){
                if(f(a)*f(c)<=0){
                    b=c;
                }else{
                    a=c;
                }c=(a*f(b)-b*f(a))/(f(b)-f(a));
            }printf("%lf",c);


    return 0;
}
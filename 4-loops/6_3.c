#include<stdio.h>
#include<math.h>
double f(double o){
    double m=cos(o)-o;
    return m;
}
double ff(double t){
    double n=-sin(t)-1;
    return n;
}
#define exp 1e-6
int main(){
    double x=0.5;
    double x1;
    do{
         x1=x;
    x=x1-f(x1)/ff(x1);

    }while(fabs(f(x))>=exp);
    printf("%lf",x);


    return 0;
}
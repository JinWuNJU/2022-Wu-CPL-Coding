//
// Created by q on 2022/12/13.
//
#include <stdio.h>
#include <math.h>

#define NUM 100000
double integrate(double l,double r,double (*f)(double)){
    double interval=(r-l)/NUM;
    double sum=0;
    for(int i=0;i<NUM;i++){
        double x=l+interval*i;
        sum+=f(x)*interval;
    }return sum;
}
int main(){
    double k= integrate(0.0,1.0,sin);
    printf("%lf\n",k);
    double (*fps[2])(double)={sin,cos};
    for(int i=0;i<=1;i++){
        printf("%lf\n", integrate(0,1,fps[i]));
    }
    return 0;
}

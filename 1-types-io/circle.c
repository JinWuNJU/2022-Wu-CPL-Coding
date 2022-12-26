//
// Created by q on 2022/12/9.
//
#include <stdio.h>
#include <math.h>
int main(){
    int n=0;
    scanf("%d",&n);
    double c=2*3.14159*n;
    double d=3.14159*n*n;
    double m=pow(n,10);
    printf("%lf %lf %lf",c,d,m);
}
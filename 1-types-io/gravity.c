#include<stdio.h>
int main(){
    const double M=77.15;
    const double G=6.674e-11;
    double m,R;
    scanf("%lf %lf",&m,&R);
    double F=(M*m*G)/(R*R);
    printf("%.3e",F);
    return 0;}
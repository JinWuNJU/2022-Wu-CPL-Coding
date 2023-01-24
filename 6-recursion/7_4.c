#include<stdio.h>
#include<math.h>
double f(double x){
    double m=sin(x)+cos(x);
    return m;
}
double integral(double a,double b,long n){
    double p=(b-a)/n*1.0;
        double q=(f(a)+f(b))/2.0;
        double sum=0;
        for(int i=1;i<=n-1;i++){
            sum+=f((double)(p*i+a));
        }double result=p*(q+sum);
        return result;
}
int main(){
    double a=0,b=0;
    int n=0;
    for(int i=1;i<=5;i++){
        scanf("%lf%lf %ld",&a,&b,&n);
        printf("%lf",integral(a,b,n));
    }
    return 0;
}
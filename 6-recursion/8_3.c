#include<stdio.h>
#include<math.h>
double f(double x){
    double m=cos(x);
    return m;
}
double g(double x){
    double m=sin(x);
    return m;
}
double h(double x){
    double m=2*x+1;
    return m;
}
void integral1(double a,double b,long n){
    double p=(b-a)/n*1.0;
        double q=(f(a)+f(b))/2.0;
        double sum=0;
        for(int i=1;i<=n-1;i++){
            sum+=f((double)(p*i+a));
        }double result=p*(q+sum);
        printf("integral  cos:%lf",result);
}
void integral2(double a,double b,long n){
    double p=(b-a)/n*1.0;
        double q=(g(a)+g(b))/2.0;
        double sum=0;
        for(int i=1;i<=n-1;i++){
            sum+=g((double)(p*i+a));
        }double result=p*(q+sum);
       printf("integral  sin:%lf",result);
}
void integral3(double a,double b,long n){
    double p=(b-a)/n*1.0;
        double q=(h(a)+h(b))/2.0;
        double sum=0;
        for(int i=1;i<=n-1;i++){
            sum+=h((double)(p*i+a));
        }double result=p*(q+sum);
        printf("integral  2x+1:%lf",result);
}
int main(){
    double a=0,b=0;
    long n=0;
    scanf("a=%lf,b=%lf,n=%ld",&a,&b,&n);
    integral1(a,b,n);
    printf("\n");
    integral2(a,b,n);
    printf("\n");
    integral3(a,b,n);
    return 0;
}
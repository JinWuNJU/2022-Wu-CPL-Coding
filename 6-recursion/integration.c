#include<stdio.h>
#include<math.h>
#define esp 1e-5
int main(){
    int n=0,p=1;
    double ee=esp;
    scanf("%d%d",&n,&p);
    getchar();
    int numbers[30]={0};
    for(int i=0;i<=n;i++){
        scanf("%d",&numbers[i]);
    }getchar();
    double a=0,b=0;
    scanf("%lf%lf",&a,&b);
    double g(double x) {
    double sum=0;
    for(int i=0;i<=n;i++){
        sum+=numbers[i]*pow(x,i);
    }sum=pow(sum,p);
    return sum;
    }
       /// @brief 
       /// @param a 
       /// @param b 
       /// @return 
       double  integration(double a,double b){
    double mid= (a+b)/2.0;
    double tem=mid;
    double S=(4*g((a+b)/2.0)+g(a)+g(b))*(b-a)/6.0;
    double SL=(4*g((a+mid)/2.0)+g(a)+g(mid))*(mid-a)/6.0;
    double SR=(4*g((mid+b)/2.0)+g(mid)+g(b))*(b-mid)/6.0;
    if(fabs (SL+SR-S)<=ee*15){
        return SL+SR+(SL+SR-S)/15.0;
    }
   
    return integration(a,tem)+integration(tem,b);
   
}printf("%lf",integration(a,b));
    
    return 0;
}
/*
#include<stdio.h>
#include<math.h>
#define esp 1e-4
double f(double x,int n,int p,int numbers[30]){
    double sum=0;
    for(int i=0;i<=n;i++){
        sum+=numbers[i]*pow(x,i);
    }sum=pow(sum,p);
    return sum;
    }
int main(){
    int n=0,p=1;
    double ee=esp;
    scanf("%d%d",&n,&p);
    getchar();
    int numbers[30]={0};
    for(int i=0;i<=n;i++){
        scanf("%d",&numbers[i]);
    }getchar();
    double a=0,b=0;
    scanf("%lf%lf",&a,&b);
    double g(double x){

        return f(x,n,p,numbers);
    }
    double xinpusen(double l,double r){
   double o=4*g((l+r)/2.0);
    return (o+g(l)+g(r))*(r-l)/6.0;
}   double integration(double l,double r){
    double mid= (l+r)/2.0;
    double tem=mid;
    double S=xinpusen(l,r);
    double SL=xinpusen(l,mid);
    double SR=xinpusen(mid,r);
    if(fabs (SL+SR-S)<=ee*15){
        return SL+SR+(SL+SR-S)/15.0;
    }
    ee/=2.0;
    return integration(l,tem)+integration(tem,r);
    
}printf("%lf",integration(a,b));
    
    return 0;
}*/
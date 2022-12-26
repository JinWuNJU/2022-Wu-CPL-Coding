#include<stdio.h>
#include<math.h>
#define eps 1e-6
double f(double x){
    double m=exp(x)+x;
    return m;
}
int main(){
    double a,b;
    while(1){
        scanf("%lf%lf",&a,&b);
        if(f(a)*f(b)<0){
            break;
        }else if(f(a)*f(b)==0){
            if(f(a)==0){
                printf("%lf",a);
            }else{
                printf("%lf",b);
            }goto loop;
        }
    }
            double c=(a+b)/2.0;
            while(fabs(f(c))>=eps&&fabs(b-a)>=eps){
                if(f(a)*f(c)<=0){
                    b=c;
                }else{
                    a=c;
                }c=(a+b)/2.0;
            }printf("%lf",c);

        

    
   loop: return 0;
}
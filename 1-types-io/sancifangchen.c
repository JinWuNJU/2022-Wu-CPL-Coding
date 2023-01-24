/*#include<stdio.h>
#include<math.h>
int main(){
    int p,q;
    scanf("%d%d",&p,&q);
    double deta=pow(q/2.0,2)+pow(p/3.0,3);
    double m=-q/2.0+sqrt(deta);
    double n=-q/2.0-sqrt(deta),x1;
    if(m>=0&&n>=0){
    x1=pow(-q/2.0+sqrt(deta),1/3.0)+pow(-q/2.0-sqrt(deta),1/3.0);
    }else if(m>=0&&n<0){
        x1=pow(m,1/3.0)-pow(-n,1/3.0);
    }else if(m<0&&n>=0){
        x1=pow(n,1/3.0)-pow(-m,1/3.0);
    }else{
        x1=-pow(-n,1/3.0)-pow(-m,1/3.0);
    }
    printf("%.3f",x1);
    return 0;
    
}*/
#include<stdio.h>//to prove the function of the function cbrt
#include<math.h>
int main(){
    printf("%lf",cbrt(-8));
    return 0;
}
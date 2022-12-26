#include<stdio.h>
int main(){
    int i;
    int n;
    int a,b,c,d,e,f;
    int g,h,k,l;
    for(i=317;i<=1000;i++){
     n=i*i;
     a=n/100000;
     f=n%10;
     g=n/10;
     e=g%10;
     h=g/10;
     d=h%10;
     k=h/10;
     c=k%10;
     l=k/10;
     b=l%10;
     if(a==f&&b==e&&c==d){
        printf("%d\t",n);
     }
    }
    return 0;
}
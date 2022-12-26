#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a=n%10,b=n/10;
    int c=b%10,d=b/10;
    int e=d%10,f=d/10;
    int g=f%10,h=f/10;
    int circle=2*g*g+3;
    printf("%d%d%d%d%d\n",e,g,h,a,c);

    return 0;
}
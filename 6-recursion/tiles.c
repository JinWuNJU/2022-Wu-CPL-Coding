#include<stdio.h>//what's the problem???
double C(int a,int b){//problem solvd.
    double sum=1;
    if(a==b){
        return 1;
    }
    for(int i=b+1;i<=a;i++){
        sum*=(1.0*i/(i-b));
    }  return sum;
}
int main(){
    int n=0;
    scanf("%d",&n);
    double result=0;
    if(n%2==0) 
    {
        int jishu=n/2;
        for(int i=0, j=jishu;i<=n,j<=n;i+=2,j++){
            result+=C(j,i);
        }
    }else{
        int jishu=(n+1)/2;
        for(int i=1,j=jishu;i<=n,j<=n;i+=2,j++){
            result+=C(j,i);
        }
    }
   printf("%.0lf",result);
    return 0;
}
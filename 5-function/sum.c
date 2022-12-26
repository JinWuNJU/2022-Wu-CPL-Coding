#include<stdio.h>
#include<math.h>
int main(){
    int n=0,t=0;
    scanf("%d%d",&n,&t);
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i-1;j++){
            sum+=t*pow(10,j);


        }
    }printf("%d",sum);
}
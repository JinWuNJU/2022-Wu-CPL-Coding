#include<stdio.h>
#define NUM 200
int main(){
    int n=0;
    scanf("%d",&n);
    int square[NUM][NUM]={0};
    square[1][(n+1)/2]=1;
     int a=1,b=(n+1)/2;
    for(int i=2;i<=n*n;i++){
        if(a!=1&&b!=n){
            if(square[a-1][b+1]==0){
                square[a-1][b+1]=i;
                a=a-1;
                b=b+1;
            }else{
                if(a!=n){
                square[a+1][b]=i;
                a=a+1;
                }else{
                    square[1][b]=i;
                    a=1;
                }
            }
        }else if(a==1&&b!=n){
            if(square[n][b+1]==0){
                square[n][b+1]=i;
                a=n;
                b=b+1;
            }else{
                square[a+1][b]=i;
                a=a+1;
               
            }
        }else if(a!=1&&b==n){
            if(square[a-1][1]==0){
                square[a-1][1]=i;
                a=a-1;
                b=1;
            }else{
               if(a!=n){
                square[a+1][b]=i;
                a=a+1;
                }else{
                    square[1][b]=i;
                    a=1;
                }
            }
        }else if(a==1&&b==n){
            if(square[n][1]==0){
                square[n][1]=i;
                a=n;
                b=1;
            }else{
                square[a+1][b]=i;
                a=a+1;
              
            }
        }
    }for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%-4d",square[i][j]);
        }if(i!=n){
            printf("\n");
        }
    }
    return 0;
}
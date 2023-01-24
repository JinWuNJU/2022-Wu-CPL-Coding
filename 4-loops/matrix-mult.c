#include<stdio.h>
int main(){
    int m=0,n=0,p=0;
    scanf("%d%d%d",&m,&n,&p);
    int juzhen1[150][150]={0};
    int juzhen2[150][150]={0};
    int juzhen3[150][150]={0};
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&juzhen1[i][j]);
        }
    } for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++){
            scanf("%d",&juzhen2[i][j]);
        }
    }int sum=0;
    for(int i=1;i<=m;i++){
       for (int j=1;j<=p;j++){
            for(int k=1;k<=n;k++){
                sum+=juzhen1[i][k]*juzhen2[k][j];
                    
            }juzhen3[i][j]=sum;
            sum=0;
        }
    }for(int i=1;i<=m;i++){
        for(int j=1;j<=p;j++){
            printf("%d ",juzhen3[i][j]);
        }if(i!=m){
            printf("\n");
        }
    }
    return 0;
}
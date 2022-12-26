#include<stdio.h>
int main(){
    char mine[150][150]={'\0'};
    int n=0;
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%c",&mine[i][j]);
            
        }if(i!=n){
            getchar();
        }
    }int ven[8][2]={{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1},{1,0},{-1,0}};
    int count=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mine[i][j]=='*'){
                continue;
            }
            for(int k=0;k<8;k++){
            int NEW_1=i+ven[k][0];
            int NEW_2=j+ven[k][1];
            if(mine[NEW_1][NEW_2]=='*'){
                count++;
            }
            }mine[i][j]=count+48;
            count=0;
        }
    }for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c",mine[i][j]);
        }if(i!=n){
            printf("\n");
        }
    }
    return 0;
}
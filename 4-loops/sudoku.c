#include<stdio.h>
int main(){
    int shudu[15][15]={0};
    int tong1[150][150]={0};
    int tong2[150][150]={0};
    int tong3[150][150]={0};
    int judge=1;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            scanf("%d",&shudu[i][j]);
           
        }
    }for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            tong1[i][shudu[i][j]]++;
        }
    }for(int i=1;i<=9;i++){
        for( int j=1;j<=9;j++){
            if(tong1[i][j]!=1){
                judge=0;
                break;
            }
        }
    }for(int col=1;col<=9;col++){
        for(int row=1;row<=9;row++){
            tong2[shudu[row][col]][col]++;
        }
    }for(int i=1;i<=9;i++){
        for( int j=1;j<=9;j++){
            if(tong2[i][j]!=1){
                judge=0;
                break;
            }
        }
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            tong3[1][shudu[i][j]]++;
        }
    }for(int i=1;i<=3;i++){
        for(int j=4;j<=6;j++){
            tong3[2][shudu[i][j]]++;
        }
    }for(int i=1;i<=3;i++){
        for(int j=7;j<=9;j++){
            tong3[3][shudu[i][j]]++;
        }
    }for(int i=4;i<=6;i++){
        for(int j=1;j<=3;j++){
            tong3[4][shudu[i][j]]++;
        }
    }for(int i=4;i<=6;i++){
        for(int j=4;j<=6;j++){
            tong3[5][shudu[i][j]]++;
        }
    }for(int i=4;i<=6;i++){
        for(int j=7;j<=9;j++){
            tong3[6][shudu[i][j]]++;
        }
    }for(int i=7;i<=9;i++){
        for(int j=1;j<=3;j++){
            tong3[7][shudu[i][j]]++;
        }
    }for(int i=7;i<=9;i++){
        for(int j=4;j<=6;j++){
            tong3[8][shudu[i][j]]++;
        }
    }for(int i=7;i<=9;i++){
        for(int j=7;j<=9;j++){
            tong3[9][shudu[i][j]]++;
        }
    }for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(tong3[i][j]!=1){
                judge=0;
                break;
            }
        }
    }
    if(judge==0){
        printf("NO");
    }else if(judge==1){
        printf("YES");
    }
    return 0;
}
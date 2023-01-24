#include<stdio.h>
int main(){
    char ditu[100][100]={'\0'};
    int bool[100][100]={0};
    int ven[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int n=0,m=0;
    int a=0,b=0;
    scanf("%d%d%d%d",&m,&n,&a,&b);
    int x=a;
    int y=b;
    int count=0;
    getchar();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%c",&ditu[i][j]);
            
        }if(i!=m){
                getchar();
            }
    }for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(ditu[i][j]=='#'){
                count++;
            }
        }
    }printf("%d\n",count);
    int NEW_1=0;
    int NEW_2=0;
    int judge=0;
    bool[a][b]=1;
    printf("%d %d\n",a,b);
    while(1){
    for(int k=0;k<4;k++){
         NEW_1=a+ven[k][0];
         NEW_2=b+ven[k][1];
        if(ditu[NEW_1][NEW_2]=='#'&&bool[NEW_1][NEW_2]==0){
            bool[NEW_1][NEW_2]++;
            judge=1;
            printf("%d %d\n",NEW_1,NEW_2);
            break;
        } 

    }if(judge==1){
        a=NEW_1;
        b=NEW_2;
        judge=0;
    }else if(judge==0){
        goto loop;
    }
    
    }
    loop:
   
    return 0;
}
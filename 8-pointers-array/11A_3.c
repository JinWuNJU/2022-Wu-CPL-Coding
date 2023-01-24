#include<stdio.h>
int main(){
    int n=0;
    scanf("%d",&n);
    int map[20][20]={0};
    int booi[20][20]={0};
    int k=1;
    int i=1,j=1;
    while(k<=n*n){
        
            for(;j<=n+1;j++){
                if(!booi[i][j]&&j!=n+1){
                    map[i][j]=k;
                booi[i][j]=1;
                k++;
                }else{
                    break;
                }
            }i++;
            j--;
            for(;i<=n+1;i++){
                if(!booi[i][j]&&i!=n+1){
                    map[i][j]=k;
                booi[i][j]=1;
                k++;
                }else{
                    break;
                }
            }i--;
            j--;
            for(;j>=0;j--){
                if(!booi[i][j]&&j!=0){
                    map[i][j]=k;
                booi[i][j]=1;
                k++;
                }else{
                    break;
                }
            }i--;
            j++;
            for(;i>=1;i--){
                if(!booi[i][j]){
                    map[i][j]=k;
                booi[i][j]=1;
                k++;
                }else{
                    break;
                }
            }i++;
            j++;
        

    }for(int p=1;p<=n;p++){
        for(int q=1;q<=n;q++){
            printf("%4d",map[p][q]);
        }printf("\n");
    }
    return 0;
}
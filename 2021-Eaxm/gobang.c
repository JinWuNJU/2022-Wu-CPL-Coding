#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int T=0;
    scanf("%d",&T);
    while (T--){
        char map[21][21]={'\0'};
        for(int i=1;i<=20;i++){
            for(int j=1;j<=20;j++){
                scanf("%c",&map[i][j]);
            }
            if(i!=20){
                getchar();
            }
        }
        printf("Not Sure\n");
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char *A=malloc(100);
    char *B=malloc(100);
    gets(A);
    gets(B);
    int m=strlen(A);
    int n=strlen(B);
    int judge=1;
    for(int i=0;i<=m-n;i++){
        for(int j=0;j<=n-1;j++){
            if(*(A+j+i)!=*(B+j)){
                judge =0;
                break;
            }
        }if(judge==1){
            printf("%d ",i);
        }judge=1;
    }free(A);
    free(B);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void xiaobianda(char *A,int i){
    if(*(A+i)>='a'&&*(A+i)<='z'){
        *(A+i)-=32;
    }
}
void dabianxiao(char *A,int i){
    if(*(A+i)<='Z'&&*(A+i)>='A'){
        *(A+i)+=32;
    }
}
int main(){
    char *A=malloc(5000);
    gets(A);
    int n=strlen(A);
    xiaobianda(A,0);
    int judge=0;
    for(int i=1;i<=n-1;i++){
        if(*(A+i)!=' '&&judge==0){
            dabianxiao(A,i);
        }else if(*(A+i)==' '){
            judge=1;
        }else if(*(A+i)!=' '&&judge==1){
            xiaobianda(A,i);
            judge=0;
        }
    }
    printf("%s",A);
    free(A);
    return 0;
}
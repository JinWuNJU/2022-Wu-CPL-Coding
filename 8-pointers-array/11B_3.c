#include<stdio.h>
#include<string.h>
int main(){
    char input[200];
    gets(input);
    int len=strlen(input);
    for(int i=0;i<len;i++){
        if(input[i]>='A'&&input[i]<='Z'){
            input[i]+=32;
        }
    }
    char zimu[30];
    for(int i=1;i<=26;i++){
        zimu[i]='a'+i-1;
    }
    int tong[30]={0};
    for(int i=0;i<len;i++){
        tong[input[i]-96]++;
    }for(int i=1;i<=26;i++){
        if(tong[i]!=0){
            printf("%c:%d ",zimu[i],tong[i]);
        }
    }
}
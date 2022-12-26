#include<stdio.h>
#include<string.h>
int main(){
    char input[100];
    gets(input);
    int len=strlen(input);
    for(int i=0;i<len;i++){
        if(input[i]>='1'&&input[i]<='9'){
            printf("$%c",input[i]);
        }else{
            printf("%c",input[i]);
        }
    }
    return 0;
}
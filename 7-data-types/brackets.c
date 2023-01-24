#include<stdio.h>
#include<string.h>
#define N 100005
int main(){
char stack[N]={'\0'};
int top=0;
int bool=1;
void push(char r){
    top++;
    stack[top]=r;
}
void pop(){
    top--;   
}

    int T=0;
    scanf("%d",&T);
    getchar();
    int output[T+5];
    for(int i=1;i<=T;i++){
        char s[N]={'\0'};
        gets(s);
        int len=strlen(s);
        for(int j=0;j<len;j++){
            if(s[j]=='('||s[j]=='['||s[j]=='{'){
                push(s[j]);
                continue;
            }if(s[j]==')'){
                if(top==0||stack[top]!='('){
                    bool=0;
                    
                    break;
                }else{
                    pop();
                }
            }else if(s[j]==']'){
                if(top==0||stack[top]!='['){
                    bool=0;
                    break;
                }else{
                    pop();
                }
            }else if(s[j]=='}'){
                if(top==0||stack[top]!='{'){
                    bool=0;
                    break;
                }else{
                    pop();
                }
            }
        }if(bool==1&&top==0){
           output[i]=1;
        }else {
            output[i]=0;
        }
        bool=1;
        top=0;
    }
    for(int i=1;i<=T;i++){
        if(output[i]==0){
            printf("False\n");
        }else if(output[i]==1){
            printf("True\n");
        }
    }
    return 0;
}
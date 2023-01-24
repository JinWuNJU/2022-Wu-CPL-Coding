#include<stdio.h>
int main(){
    char strings[10000];
    int len=1;
    int i=0;
    while(len==1){
        scanf("%c",&strings[i]);
        if(strings[i]==EOF){
            len=0;
            break;
        }else{
            i++;
        }
    };getchar();
    for(int j=0;j<=i-1;j++){
        printf("%c",strings[j]);
    }
   
    return 0;
}
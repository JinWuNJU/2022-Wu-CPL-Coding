#include<stdio.h>
int main(){
    char string[100]={'\0'};
    gets(string);
    for(int i=0;i<100;i++){
        if(string[i]>='a'&&string[i]<='z'){
            string[i]=string[i]-32;
        }
    
    }printf("%s",string);
    return 0;

}
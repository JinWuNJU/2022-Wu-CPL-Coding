#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{	
char s[80];
	   	gets(s);
    	
        int len=strlen(s);
        int n=0;
        int m=0;
        int count=0;
        int k;
        for(int i=0;i<=len;i++){
            if(s[i]>='0'&&s[i]<='9'){
                n=10*n+s[i]-48;
                count++;
            }else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='\0'){
                count++;
                 k=i;
                break;
            }else{
                printf("operator error!");
                return 0;
            }
        }for(int i=count;i<len;i++){
            if(s[i]>='0'&&s[i]<='9'){
                m=10*m+s[i]-48;
                count++;
            }
            else if(s[i]=='\0'){
                count++;
                break;
            }else{
                printf("operator error!");
                return 0;
            }
        }
        switch(s[k]){
            case '+':
            printf("%s=",s);
            printf("%d",m+n);
            break;
            case '-':
            printf("%s=",s);
            printf("%d",n-m);
            break;
            case '*':
            printf("%s=",s);
            printf("%d",m*n);
            break;
            case '/':
            if(m==0){
                printf("div!0");
                return 0;

            }else{
                printf("%s=",s);
            printf("%d",n/m);
            break;

            }
            case '\0':{
                printf("%s=",s);
                printf("%d",n);
                break;
            }
            
        }
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void mystrcat(char *a, char *c){
    printf("%s%s\n",a,c);
}
int main(){
    int n=0;
    scanf("%d",&n);
   // getchar();
    while(n){
        char *a=malloc(1200);
        char *b=malloc(1200);
        char *c=malloc(1200);
        char **d=malloc(1100);
        for(int i=0;i<1100;i++){
            *(d+i)=malloc(500);
        }
        int *map=malloc(1200*sizeof(*map));
        for(int i=0;i<1200;i++){
            *(map+i)=0;
        }
        scanf("%s%s",a,b);
        int len1=strlen(a);
        int len2=strlen(b);
        int cut=0;
        for(int i=0;i<len1;i++){
            if(*(a+i)==*b){
                *(map+i)=1;
            }
        }for(int i=0;i<len1;i++){
            if(*(map+i)){
                char *p=a+i;
                int lenn=len1-i;
                  strcpy(*(d+1),b);
                *(*(d+1)+lenn)='\0';
                if(!strcmp(p,*(d+1))){
                  cut=lenn;
                    break;
                }
            }
        }
        for(int i=0;i<len2-cut;i++){
            *(c+i)=*(b+i+cut);
        }*(c+len2-cut)='\0';
        mystrcat(a,c);
        n--;
    }
    return 0;
}
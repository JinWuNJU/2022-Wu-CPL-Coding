
    /*char s[50];
    int cut=1;
     while(scanf("%s",s)!=EOF){
            printf("%d ",cut);
            cut++;
        }
        char *p[5];
        p[1]="qedsvc";
        printf("%s",*(p+1))；
        char **p=malloc(5000);
        for(int i=0;i<5000;i++){
            *(p+i)=malloc(5000);
        }
        char *standard[5];
        standard[1]="reserve";
        standard[2]="integer";
        standard[3]="float";
        strcpy(*(p+1),*(standard+1));
        printf("%s",p[1]);
        char s[500];
        scanf("%s",s);
        char *position = strchr(s, ';');
        int lenn=position-s;
        printf("%d",lenn);*/
        #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 5000
//a variable name can be the form of "__"
int main(){
     int l=1;
       char *(*p)=malloc(5000*15);
       /* for(int i=0;i<5000;i++){
            *(p+i)=malloc(15);
        }*/
         char *(*standard)=malloc(50*15);
       /* for(int i=0;i<50;i++){
            *(standard+i)=malloc(15);
        }*/
       * (standard+1)="reserved";
         * (standard+2)="integer";
         * (standard+3)="float";
         * (standard+4)="operator";
         * (standard+5)="variable";
    int bool=1;
    int *map=malloc(5000*sizeof(*map));
    for(int i=0;i<=5000;i++){
        *(map+i)=0;
    }
void process(char *s){
    int len=strlen(s);
     if(!strcmp(s,"const")||!strcmp(s,"int")||!strcmp(s,"float")||!strcmp(s,"double")||!strcmp(s,"long")||!strcmp(s,"static")||!strcmp(s,"void")||!strcmp(s,"char")||!strcmp(s,"extern")||!strcmp(s,"return")||!strcmp(s,"break")||!strcmp(s,"enum")||!strcmp(s,"struct")||!strcmp(s,"typedef")||!strcmp(s,"union")||!strcmp(s,"goto")){
         strcpy(*(p+l),*(standard+1));
         return;
     }int Is_Integer=1;
     for(int i=0;i<len;i++){
        if(*(s+i)<'0'||*(s+i)>'9'){
            Is_Integer=0;
            break;
        }
     }if(Is_Integer==1){
        strcpy(*(p+l),*(standard+2));
         return;
     }int Is_Float=1;
     int CutFloat=0;
     for(int i=0;i<len;i++){
         if((*(s+i)<'0'||*(s+i)>'9')&&*(s+i)!='.'){
            Is_Float=0;
            break;
         }if(*(s+i)=='.'){
            CutFloat++;
         }
     }if(CutFloat==1&&Is_Float==1){
        strcpy(*(p+l),*(standard+3));
        return;
     }if(!strcmp(s,"+")||!strcmp(s,"-")||!strcmp(s,"*")||!strcmp(s,"/")||!strcmp(s,"=")||!strcmp(s,"==")||!strcmp(s,"!=")||!strcmp(s,">=")||!strcmp(s,"<=")||!strcmp(s,">")||!strcmp(s,"<")){
        strcpy(*(p+l),*(standard+4));
         return;
     }int IsVariable=1;
     if((*(s+0)>='a'&&*(s+0)<='z')||(*(s+0)>='A'&&*(s+0)<='Z')||*(s+0)=='_'){
        for(int i=1;i<len;i++){
            if(!(*(s+i)>='a'&&*(s+i)<='z')&&!(*(s+i)>='A'&&*(s+i)<='Z')&&*(s+i)!='_'&&!(*(s+i)>='0'&&*(s+i)<='9')){
                IsVariable=0;
                break;
            }
        }
     }else{
        IsVariable=0;
     }
     if(IsVariable){
        strcpy(*(p+l),*(standard+5));
        return;
     }
     bool=0;
     

   
}  //l 用于计数并且换行
    char *s=malloc(5000);
    while(scanf("%s",s)!=EOF){
        if(strlen(s)==1&&strcmp(s,";")==0){
            *(map+l-1)=1;
            continue;
        }
        char *position = strchr(s, ';');
        if (position == NULL) {
            process(s);
            l++;
        }else{
            char *front=malloc(4500);
            for(int i=0;i<4500;i++){
                *(front+i)='\0';
            }
            int lenn=position-s;
            for(int i=0;i<lenn;i++){
                *(front+i)=*(s+i);
            }process(front);
            *(map+l)=1;
            l++;
           if(lenn!=strlen(s)-1){ 
            process(position+1);
            l++;
            }
        }
    }if(bool==0){
        printf("Compile Error");

    }else{
        for(int i=1;i<=l-1;i++){
            printf("%s ",*(p+i));
            if(*(map+i)){
                printf("\n");
            }
        }
    }
    return 0;
}




  

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char *prase=malloc(130*sizeof(*prase));
    char *order=malloc(1300*sizeof(*order));
    char **output=malloc(1200*sizeof(**output));
    for(int i=0;i<1200;i++){
        *(output+i)=malloc(1200*sizeof(*(output+i)));
    }
    char **output2=malloc(1200*sizeof(**output2));
    for(int i=0;i<1200;i++){
        *(output2+i)=malloc(1200*sizeof(*(output2+i)));
    }
    int *situation1=malloc(200*sizeof(*situation1));
    int *situation2=malloc(200*sizeof(*situation2));
    for(int i=0;i<200;i++){
        *(situation1+i)=0;
        *(situation2+i)=0;
    }
    int bool=1;
    scanf("%s",prase);
    getchar();
    int len1=strlen(prase);
    int len2=strlen(order);
    int *map=malloc(1300*sizeof(*map));
    char answer;
    for(int i=0;i<1300;i++){
        *(map+i)=0;
    }
    for(int i=0;i<len1;i++){
        if(*(prase+i)==':'){
            *(situation2+*(prase+i-1))=1;
            *(situation1+*(prase+i-1))=0;
        }else{
            *(situation1+*(prase+i))=1;
        }
    }int cut=1;
    while(scanf("%s",order)!=EOF){
        if(cut==1){
            strcpy(*(output+cut),order);
            strcpy(*(output2+cut),order);
            cut++;
        }else{
            int len3=strlen(order);
            if(len3==2&&*(order+0)=='-'&&((*(order+1)>='A'&&*(order+1)<='Z')||(*(order+1)>='a'&&*(order+1)<='z'))){
                strcpy(*(output+cut),order);
                cut++;
            }else{
                strcpy(*(output+cut),order);
                *(map+cut)=1;
                cut++;
            }
        }
    }int count=2;
    for(int i=2;i<cut;i++){
        if(*(situation1+*(*(output+i)+1))==0&&*(situation2+*(*(output+i)+1))==1&&*(map+i)==0){
            if(i==cut-1){
                bool=0;
                answer=*(*(output+i)+1);
                break;
            }else{
                int leeen=strlen(*(output+i+1));
                char *linshi=malloc(1300);
                *(linshi+0)=*(*(output+i)+1);
                *(linshi+1)='=';
                for(int k=2;k<2+leeen;k++){
                    *(linshi+k)=*(*(output+i+1)+k-2);
                }*(linshi+leeen+2)='\0';
                strcpy(*(output2+count),linshi);
                count++;
                i++;
                if(i==cut-1){
                    break;
                }
            }
        }if(*(situation1+*(*(output+i)+1))==1&&*(situation2+*(*(output+i)+1))==0&&*(map+i)==0){
           *(*(output2+count)+0)=*(*(output+i)+1);
           *(*(output2+count)+1)='\0';
           count++;
        }if(*(situation1+*(*(output+i)+1))==0&&*(situation2+*(*(output+i)+1))==0&&*(map+i)==0){
            bool=-1;
            answer=*(*(output+i)+1);
            break;
        }
    }if(bool==0){
        printf("%s: option requires an argument -- '%c'",*(output+1),answer);
    }else if(bool==-1){
        printf("%s: invalid option -- '%c'",*(output+1),answer);
    }else if(bool==1){
        for(int i=1;i<count;i++){
            printf("%s\n",*(output2+i));
        }
    }
    return 0;
}
//mount: option requires an argument -- 't'
//mount: invalid option -- 'k'
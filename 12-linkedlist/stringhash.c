#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *s[500000];
int compare(const void *a,const void *b){
    return strcmp(*(char **)a,*(char **)b);
}
int main(){
    int m,q;
    scanf("%d%d",&m,&q);
    char *ppp=malloc(1000);
    for(int i=0;i<m;i++){
        scanf("%s",ppp);
        char *temp=malloc(strlen(ppp)+1);
        strcpy(temp,ppp);
        s[i]=temp;
    }
    qsort(s, m,sizeof (s[0]),compare);

    char *tempp=malloc(1000);
    for(int i=0;i<q;i++) {
        scanf("%s", tempp);
        int *index=bsearch(&tempp,s,m, sizeof(s[0]),compare);
        if(index==NULL){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }



    return 0;
}
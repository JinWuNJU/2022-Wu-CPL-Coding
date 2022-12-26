
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void changestring(char **m,char **n){
    char *pp=*m;
    *m=*n;
    *n=pp;
}
void changestring2(char *m,char *n){
    int len1=strlen(m);
    int len2=strlen(n);
    if(len1>len2){
        for(int i=0;i<len2;i++){
            char ch;
            ch=m[i];
            m[i]=n[i];
            n[i]=ch;
        }for(int i=len2;i<len1;i++){
            n[i]=m[i];
        }n[len1]='\0';
        m[len2]='\0';
    }else if(len1<len2){
        for(int i=0;i<len1;i++){
            char ch;
            ch=m[i];
            m[i]=n[i];
            n[i]=ch;
        }for(int i=len1;i<len2;i++){
            m[i]=n[i];
        }n[len1]='\0';
        m[len2]='\0';
    }else{
        for(int i=0;i<len1;i++){
            char ch;
            ch=m[i];
            m[i]=n[i];
            n[i]=ch;
        }n[len1]='\0';
        m[len2]='\0';
    }
}

int main(){
    char **Team=malloc(10050);
    for(int i=0;i<10050;i++){
        *(Team+i)=malloc(30000);
    }
    // char *Team1[1500];
    // char *Team2[1500];
    // char *Team3[1500];
    char **Team1=malloc(10050);
    for(int i=0;i<10050;i++){
        *(Team1+i)=malloc(3000*sizeof(*(Team+i)));
    }
    char **Team2=malloc(1005);
    for(int i=0;i<10050;i++){
        *(Team2+i)=malloc(3000*sizeof(*(Team+i)));
    }
    char **Team3=malloc(10050);
    for(int i=0;i<10050;i++){
        *(Team3+i)=malloc(3000*sizeof(*(Team+i)));
    }
    int fenshu[100][10990]={0};
    // char **name=malloc(15*sizeof(**name));
    // for(int i=10;i<15;i++){
    //     *(name+i)=malloc(100);
    // }
    int n=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int sum1=0;
        int sum2=0;
        int sum3=0;
        scanf("%s",Team[i]);
        strcpy(Team1[i],Team[i]);
        strcpy(Team2[i],Team1[i]);
        strcpy(Team3[i],Team2[i]);
        for(int j=1;j<=11;j++){
            char name[500];
            int tem1,tem2,tem3;
            scanf("%s%d%d%d",name,&tem1,&tem2,&tem3);//why??????????
            sum1=sum1+tem1;
            sum2=sum2+tem2;
            sum3=sum3+tem3;
        }fenshu[1][i]=sum1;
        fenshu[2][i]=sum2;
        fenshu[3][i]=sum3;
    }
    int min1=fenshu[1][1];
    int min2=fenshu[2][1];
    int min3=fenshu[3][1];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(min1>fenshu[1][j]){
                min1=fenshu[1][j];
                int tep1=fenshu[1][i];
                fenshu[1][i]=fenshu[1][j];
                fenshu[1][j]=tep1;
                changestring(&Team1[i],&Team1[j]);
            }
            if(min2>fenshu[2][j]){
                min2=fenshu[2][j];
                int tep2=fenshu[2][i];
                fenshu[2][i]=fenshu[2][j];
                fenshu[2][j]=tep2;
                changestring(&Team2[i],&Team2[j]);
            }
            if(min3>fenshu[3][j]){
                min3=fenshu[3][j];
                int tep3=fenshu[3][i];
                fenshu[3][i]=fenshu[3][j];
                fenshu[3][j]=tep3;
                changestring(&Team3[i],&Team3[j]);
            }
        }min1=fenshu[1][i+1];
        min2=fenshu[2][i+1];
        min3=fenshu[3][i+1];
    }
    for(int i=n;i>=1;i--){
        printf("%s ",Team1[i]);

    }
    printf("\n");
    for(int i=n;i>=1;i--){
        printf("%s ",Team2[i]);

    }
    printf("\n");
    for(int i=n;i>=1;i--){
        printf("%s ",Team3[i]);

    }
    return 0;
}
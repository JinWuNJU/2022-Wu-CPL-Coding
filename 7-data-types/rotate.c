#include<stdio.h>
#include<string.h>
int min(int a,int b){
    if(a<b){
        return a;
    }return b;
}
int max(int a,int b){
    if(a>b){
        return a;
    }return b;
}
int main(){
    int a=0,b=0,c=0;
    scanf("%d%d%d",&a,&b,&c);
    getchar();
    char caozuo[1005]={'\0'};
    gets(caozuo);
    int len=strlen(caozuo);
    int shuzu[5]={0};
    shuzu[2]=a;
    shuzu[4]=b;
    for(int i=0;i<=len-1;i++){
        switch (caozuo[i])
        {
        case 'W' :
        int z1=min(shuzu[1],shuzu[2]);
        int x1=max(shuzu[1],shuzu[2]);
        shuzu[1]=z1;
        shuzu[2]=x1;
        shuzu[2]-=(a+c) ;
        int tem=a;
        a=c;
        c=tem;
            
            break;
        case  'S':
        int z2=max(shuzu[1],shuzu[2]);
        int x2=min(shuzu[1],shuzu[2]);
        shuzu[1]=z2;
        shuzu[2]=x2;
        shuzu[2]+=(a+c);
        int temm=a;
        a=c;
        c=temm;

            break;
        case  'A':
        int z3=min(shuzu[3],shuzu[4]);
        int x3=max(shuzu[3],shuzu[4]);
        shuzu[3]=z3;
        shuzu[4]=x3;
        shuzu[4]-=(b+c);
        int temmm=b;
        b=c;
        c=temmm;
            break;
        case  'D':
        int z4=max(shuzu[3],shuzu[4]);
        int x4=min(shuzu[3],shuzu[4]);
        shuzu[3]=z4;
        shuzu[4]=x4;
        shuzu[4]+=(b+c);
        int temmmm=b;
        b=c;
        c=temmmm;
            break;
        default:
            break;
        }
    }int p1=min(shuzu[1],shuzu[2]);
    int q1=min(shuzu[3],shuzu[4]);
    int p2=max(shuzu[1],shuzu[2]);
    int q2=max(shuzu[3],shuzu[4]);
    printf("%d %d %d %d",p1,p2,q1,q2);

    return 0;
}
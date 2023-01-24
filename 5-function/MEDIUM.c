#include<stdio.h>
int main(){
    int bool[30000]={0};
    int weizhi[30000]={0};
    int  n=0,x=0,len=10;
    int min=0,max=0;
  scanf("%d%d%d",&n,&x,&len);
   for(int i=1;i<=n;i++){
  scanf("%d",&weizhi[i]);
        }
    /*if(x>len){
    }*/    //not mentioned in the question
    for(int i=1;i<=n;i++){
        bool[weizhi[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(bool[i]!=0){
           min=i;
           break;
        }
    }for(int j=len;j>=1;j--){
        if(bool[j]!=0){
            max=j;
            break;
        }
    }int chi=x;
    int sum1=0,sum2=0;
    int k,p;
    int a=0,b=0;
    int kaishi1,jieshu1;//kaishi1小
    int kaishi2,jieshu2;//kaishi2大
    for( k=min;k<=max;k++){
        p=k+chi;
        for(int i=k;i<=p;i++){
            if(bool[i]!=0){
                sum1++;
            }
        }if(a<=sum1){
            a=sum1;
            kaishi1=k;//kaishi不一定是员工所在位置
            jieshu1=k+chi;
        }sum1=0;
        
    }for(k=max;k>=min;k--){
       if(k-chi>=1){
        p=k-chi;
       }else{
        p=1;
       }
        for(int i=k;i>=p;i--){
            if(bool[i]!=0){
                sum2++;
            }

        }if(b<=sum2){
            b=sum2;
            kaishi2=k;//kaishi2也不一定是员工所在位置
            jieshu2=k-chi;
        }sum2=0;
    }if(a>b){
        if(jieshu1<=len){
            printf("%d %d\n%d",kaishi1,jieshu1,a);
        }else {
            printf("%d %d\n%d",kaishi1,len,a);
        }
    }else if(a<b){
         if(jieshu2>=1){
            printf("%d %d\n%d",kaishi2,jieshu2,b);
        }else {
            printf("%d %d\n%d",kaishi2,1,b);
        }

    }else if(a==b){
        if(jieshu1>len){
            printf("%d %d\n%d",kaishi2,jieshu2,b);
        }else{
            printf("%d %d\n%d",kaishi1,jieshu1,a);
        }
    }
    return 0;
}
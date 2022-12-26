#include<stdio.h>
#include<string.h>
int GongYueShu(int a,int b){
    for(int i=a;i>=1;i--){
        if(a%i==0&&b%i==0){
            return i;
        }
    }
}
int main(){
    int shuzu[1000]={0};
    int shuzu2[1000]={0};
    int n=10,cut=1;
    for(int i=1;i<=10;i++){
        scanf("%d",&shuzu[i]);
    }for(int i=1;i<=10;i++){
       if(i%2!=0){
        shuzu2[cut]=shuzu[i];
        cut++;
       } 
    }int z=GongYueShu(shuzu2[1],shuzu2[2]);
    for(int i=2;i<=cut;i++){
        int p=GongYueShu(z,shuzu2[i]);
        z=p;
    }for(int i=1;i<cut;i++){
        printf("%d ",shuzu2[i]);
    }printf("%d",z);
    return 0;
}
#include<stdio.h>
int main(){
    int n,L;
    scanf("%d%d",&n,&L);
    getchar();
    int a[1000]={0};
    int b[1000]={0};
    int j=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }getchar();
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }int min=a[1];
    for(int i=1;i<=n;i++){
        for( j=i;j<=n;j++){
            if(min>a[j]){
                min=a[j];
                int tem=a[j];
                a[j]=a[i];
                a[i]=tem;
                int tem2=b[j];
                b[j]=b[i];
                b[i]=tem2;
            }
        }min=a[i+1];
    }int mann=0,sum=0;
    for(int i=n;i>=1;i--){
        sum+=b[i];
        if(sum>=L){
            mann=i;
            break;
        }
    }int result=0;
    for(int i=mann+1;i<=n;i++){
        result+=a[i]*b[i];
    }result+=(b[mann]-sum+L)*a[mann];
    printf("%d",result);
    return 0;
}
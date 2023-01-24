#include<stdio.h>
int main(){
    int a[20]={0,3 , 6,  7,  18,  23,  33,  35,  43,  48,  78};
    int b[20]={0,2  ,7 , 13,  21 , 33 , 37 , 48 , 50 , 58 , 67};
    int c[30]={0};
    int cut=0;
    for(int i=1;i<=10;i++){
        c[i]=a[i];
    }for(int i=11;i<=20;i++){
        c[i]=b[i-10];
    }int tong[10000]={0};
    for(int i=1;i<=20;i++){
        tong[c[i]]++;
        if(tong[c[i]]>1){
            cut++;
        }
    }int min=c[1];
    for(int i=1;i<=20;i++){
        for(int j=i;j<=20;j++){
            if(min>c[j]){
                min=c[j];
                int tem=c[i];
                c[i]=c[j];
                c[j]=tem;
            }
        }min=c[i+1];
    }for(int i=1;i<=20;i++){
        if(c[i]!=c[i+1]&&c[i]!=c[i-1]){
            printf("%d ",c[i]);
        }
    }printf("\ncount=%d",cut);
    return 0;
}
//3  6  7  18  23  33  35  43  48  78
//2  7  13  21  33  37  48  50  58  67
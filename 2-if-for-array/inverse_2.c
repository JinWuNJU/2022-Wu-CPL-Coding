#include<stdio.h>//this is a wrong answer cause the mark on oj is 93 ,what a shame!
int main(){
    int n;
    scanf("%d\n",&n);
    char complex[n];
    for(int i=1; i<=n; i++){
        scanf("%c",&complex[i]);
    }int x;
    scanf("%d",&x);
    for(int i=1; i<=x/2;i++){
        char a=complex[i];
        complex[i]=complex[x-i+1];
        complex[x-i+1]=a;
    }for(int j=1;j<=(n-x)/2;j++ ){
        char b=complex[j+x];
        complex[j+x]=complex[n-j+1];
        complex[n-j+1]=b;
    }for(int i=1;i<=n;i++){
    printf("%c",complex[i]);}
    return 0;
}
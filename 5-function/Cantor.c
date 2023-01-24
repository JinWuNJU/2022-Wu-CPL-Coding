#include<stdio.h>
int f(int n){
    int m=n*(2*n-1);
    return m;
}
int g(int n){
    int m=n*(2*n+1);
    return m;
}
int main(){
    long int n=0;
    scanf("%ld",&n);
    long int fenzi=0,fenmu=0;
    int k=1;
    for( k=1;;k++){
        if(f(k)>=n){
            break;
        }
    }long int mid1=n-f(k-1);
     int p=1;
     for(p=1;;p++){
        if(g(p)>=n){
            break;
        }
     }long int mid2=n-g(p-1);
     if(mid1<=2*k-1){
        fenzi=mid1;
     }else{
        fenzi=4*k-2-mid1;
     }if(mid2<=2*p){
        fenmu=mid2;
     }else{
        fenmu=4*p-mid2;
     }
    printf("%ld/%ld",fenzi,fenmu);

    
    return 0;
}
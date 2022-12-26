#include<stdio.h>
int main(){
    int n;
    for(n=1; ;n++){
        int p=n*n+n+41;
        int i;
        for(i=2;i<p;i++){
            if(p%i==0){
                break;
            }
        }if(i>=p){
            printf("%d\t",p);
        }else{
            break;
        }
    }
    return 0;
}
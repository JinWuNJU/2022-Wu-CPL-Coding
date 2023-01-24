#include<stdio.h>
int main(){
    int n=0;
    scanf("%d",&n);
    for(int j=31;j>=0;j--){
        if(n&(1<<j)){

            
            printf("%d",1);
        }
        else {
            printf("%d",0);
        }
    }
    return 0;
}
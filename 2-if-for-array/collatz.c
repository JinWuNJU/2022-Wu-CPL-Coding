#include<stdio.h>
int main(){
    int n;
    int i=0;
    scanf("%d",&n);
    int max=n;
    while (n!=1)
    {if(n%2==0){
        n=n/2;
        if(max<n){
            max=n;
        }
        i++;
    }else{
        n=n*3+1;
        if(max<n){
            max=n;
        }
        i++;
    }
        
    }printf("%d %d",i,max);
    

    return 0;
}
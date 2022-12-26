#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int numbers[n]; 
    for (int i = 0; i < n; i++)
    {
        numbers[i]=0;
    }for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
            if(k%j==0){
                numbers[k-1]++;
            }
        }
    }for(int i=0;i<n;i++){
        if(numbers[i]%2!=0){
            printf("%d ",i+1);
        }
    }
    
    
    
    return 0;
}
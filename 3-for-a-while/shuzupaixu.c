#include<stdio.h>
int main(){
    int n=0;
    scanf("%d",&n);
    int numbers[n];
   for(int i=0;i<n;i++){
        scanf("%d",&numbers[i]);
    }int min=numbers[0];
    for(int j=0;j<=n-1;j++){
    for(int k=j;k<=n-1;k++){
        if(min>numbers[k]){
            min=numbers[k];
            int tem=numbers[j];
            numbers[j]=min;
            numbers[k]=tem;
           
        }
        
    } min=numbers[j+1];
    }for(int i=0;i<n;i++){
        printf("%d ",numbers[i]);
    }
    return 0;
}
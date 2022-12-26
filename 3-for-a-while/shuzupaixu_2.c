#include<stdio.h>
int main(){
    int n=0;
    scanf("%d",&n);
    int numbers[n];
    for(int i=0;i<n;i++){
        scanf("%d",&numbers[i]);
    }
    for(int i=0;i<n;i++){
        int min=numbers[i];
        int index=i;
        for( int j=i;j<n;j++){
            if(min>numbers[j]){
                min=numbers[j];
                index=j;

            }
        } int tem=numbers[index];
            numbers[index]=numbers[i];
            numbers[i]=tem;
    }for(int i=0;i<n;i++){
        printf("%d ",numbers[i]);
    }
    return 0;
}
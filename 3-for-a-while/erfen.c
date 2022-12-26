#include<stdio.h>
int main(){
    int n=0;
    scanf("%d",&n);
    getchar();
    int numbers[10000];
    for(int i=0;i<n;i++){
        scanf("%d",&numbers[i]);
    }getchar();
    int index=-1;
    int low=0,high=n-1;
    int key=0;
    scanf("%d",&key);
    int min=numbers[0];
    for(int j=0;j<=n-1;j++){
    for(int k=j;k<=n-1;k++){
        if(min>numbers[k]){
            min=numbers[k];
            int tem=numbers[j];
            numbers[j]=min;
            numbers[k]=tem;
           
        }
        
    } min=numbers[j+1];
    }
    while(low<=high){
        int mid=(low+high)/2;
        if(key>numbers[mid]){
            low=mid+1;
        }else if (key<numbers[mid])
        {
            high=mid-1;
        }else{
            index=mid;
            break;
        }
    }if(index==-1){
            printf("nope");
        }else{
            printf("%d",index+1);
        }
        

    return 0;
}
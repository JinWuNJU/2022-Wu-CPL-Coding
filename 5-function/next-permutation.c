#include<stdio.h>
#define NUM 5000
int main(){
    int n=0;
    scanf("%d",&n);
    int count=1;
    int  numbers[NUM]={0};
    for(int i=1;i<=n;i++){
        scanf("%d",&numbers[i]);
    }if(numbers[n-1]<numbers[n]){
        int tem=numbers[n-1];
        numbers[n-1]=numbers[n];
        numbers[n]=tem;
        for(int i=1;i<=n;i++){
            printf("%d ",numbers[i]);
        }
    }else{
        for(int j=n;j>=1;j--){
            if(numbers[j]<numbers[j-1]){
                count++;
            }else{
                break;
            }

        }
        int p=0;//the following codes can be modified as a function,making it simpler to understand
        for( p=n;;p--){
            if(numbers[n-count]<numbers[p]){
                break;

            }
        }int middle=numbers[n-count];
        numbers[n-count]=numbers[p];
        numbers[p]=middle;
        for(int i=1;i<=n-count;i++){
            printf("%d ",numbers[i]);
        }for(int j=n;j>n-count;j--){
              printf("%d ",numbers[j]);
        }
    }
    return 0;
}
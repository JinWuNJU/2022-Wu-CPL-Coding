#include<stdio.h>
int main(){
    int numbers[100]={0,5,23,28,34,43,45,56,60,67,90};
    int index=-1;
    int n=0;
    scanf("%d",&n);
    int low=1;
    int high=10;
    while(low<=high){
        int middle=(low+high)/2;
        if(n>numbers[middle]){
            low=middle+1;
        }else if(n<numbers[middle]){
            high=middle-1;
        }else{
            index=middle;
            break;
        }
    }if(index==-1){
        printf("not found");
    }else{
        printf("%d",index);
    }

    return 0;
}
//5,23,28,34,43,45,56,60,67,90
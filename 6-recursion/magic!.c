#include<stdio.h>
#define NUM 5
int Min(const int numbers[],int len){
    if(len==1){
        return numbers[0];

    }int partical_min=Min(numbers,len-1);
    return numbers[len-1]<partical_min?numbers[len-1]:partical_min;
}
int main(){
    int numbers[NUM]={92,44,63,24,56};
    int min=Min(numbers,5);
    printf("%d",min);
    return 0;
}
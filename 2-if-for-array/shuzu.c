#include <stdio.h>
#define NUM 10
int main(){
    int numbers[NUM]={0};
   
    for(int j=0;j<=(NUM-1);j++){
          scanf("%d",&numbers[j]);
        
    }
    int i;
    int min=numbers[0];
    for(i=1;i<=(NUM-1);i++){
        if(numbers[i]<=min){
            min=numbers[i];
        }
    }printf("min=%d",min);
    return 0;
}

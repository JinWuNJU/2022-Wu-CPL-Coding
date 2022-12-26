#include<stdio.h>
#define NUM 1000
int main(){
     int numbers[NUM]={0};
    int b[NUM]={0};
    int n;
   scanf("%d\n",&n);
    for(int i=0;i<2*n-1;i++){
        scanf("%d",&numbers[i]);
    }for(int j=0;j<NUM;j++){
        b[numbers[j]]++;
    }
    for(int t=0;t<NUM;t++){
        if(b[t]==1){
            printf("%d",t);
        }

    }
  
    return 0;
}
/*#include <stdio.h>
#define NUM 10000
int main(){
    int numbers[NUM]={0};
    int b[NUM]={0};
   int n;
   scanf("%d",&n);
    for(int j=0;j<(2*n-1);j++){
          scanf("%d",&numbers[j]);
        
    }for(int j=0;j<NUM;j++){
       (b[numbers[j]])++;
       }  for(int t=0;t<NUM;t++){
        if(b[t]==1){
            printf("%d",t);}}
   
        
    return 0;}*/
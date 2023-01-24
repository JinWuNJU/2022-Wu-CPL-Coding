#include<stdio.h>
#include<string.h>
#define NUM 1001 
int main(){
   char numbers[NUM]={'\0'};
   gets(numbers);
   int n=strlen(numbers);
   int nuumbers[NUM]={0};
   for(int i=0;i<n;i++){
    nuumbers[i]=numbers[i]-48;
   }int sum=nuumbers[0]%9;
   int suum=0;
   for(int i=1;i<n;i++){
        sum+=nuumbers[i];
        suum=sum%9;
        sum=suum;
   }printf("%d",suum);
    return 0;
}
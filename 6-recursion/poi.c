#include<stdio.h>
#define NUM 100005
int find(int a[NUM],int x){
   if(a[x]==x){
    return x;

   }
   else{
     return find(a,a[x]);
  }
}
int main(){
    int numbers[NUM]={0};
    int n=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&numbers[i]);
    }for(int i=1;i<=n;i++){
        printf("%d ",find(numbers,i));
    }

    return 0;
}
#include<stdio.h>
#define NUM 1005
int Max(int l,int r,int input[],int output[NUM][2]){
    if(l==r){
        output[l][0]=l;
        output[l][1]=r;
        return l;
    } 
    int max=input[l];
    int index=l;
      for(int i=l+1;i<=r;i++){
        if(max<input[i]){
            max=input[i];
            index=i;
        }
    }if(index>l&&index<r){
        output[index][0]=l;
        output[index][1]=r;
    return Max(l,index-1,input,output), Max(index+1,r,input, output);
    }else if(index==l){
        output[index][0]=l;
        output[index][1]=r;
        int s=Max(l+1,r,input,output);
    }else if(index==r){
        output[index][0]=l;
        output[index][1]=r;
        int t=Max(l,r-1,input,output);
    } 
  
  
}

int main(){
    int n=6;
    scanf("%d",&n);
    getchar();
    int input[NUM]={0};
    int output[NUM][2]={0};
    for(int i=1;i<=n;i++){
        scanf("%d",&input[i]);
    }
    Max(1,n,input,output);
    for(int i=1;i<=n;i++){
        printf("%d %d",output[i][0],output[i][1]);
        if(i!=n){
            printf("\n");
        }
    }
   
       return 0;
}

#include<stdio.h>
#include<math.h>
int main(){
    int count=1;
    int weishu=0;
    int sum=0;
    for(int i=100; count<=12; i++)
    {   int t=i;
        int m=i;
        do{t/=10;
    weishu++;

    }while(t>0);
     while(m>0){
    int k=m%10;
    sum+=pow(k,weishu);
    m/=10;

     }if(sum==i){
        printf("%d",sum);
       
        if(count%5==0){
        printf("\n");
     }else if(count%5!=0){
        printf(" ");
     } count++;
     }
     sum=0;
     weishu=0;

    }
    return 0;
}
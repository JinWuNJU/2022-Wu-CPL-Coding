#include<stdio.h>
#include<math.h>
int main(){
    int c=3;
    int p=4;
    int m;
    printf("3\t7\t");
    while(c>0){
        for(p; ; p++){
        int i;
        for(i=2;i<=sqrt(p);i++){
            if(p%i==0){
                break;
            }
        }if(i>sqrt(p)){
            m=pow(2,p)-1;
            int j;
            for(j=2;j<=sqrt(m);j++){
                if(m%j==0){
                    break;
                }
            }if(j>sqrt(m)){
            	c--;
                printf("%d\t",m);
                p++;
                break;
                
            }
        }
        }    
    }
    return 0;
}
/*#include<stdio.h>
int main(){
    int i=1;
    int sum=0;
    for(i=1;i<=1000;i++){
        int j=1;
        for(j=1;j<i;j++){
            if(i%j==0){
                sum=sum+j;
            } }if(sum==i){
                printf("%d ",i);
                
            }sum=0;
       
    }
    return 0;
}*/
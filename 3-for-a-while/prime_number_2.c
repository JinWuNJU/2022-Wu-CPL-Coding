#include<stdio.h>
#include<math.h>
int main(){
     int max;
     int count=0;
     int tem=0;
     int is_prime=1;
    scanf("%d",&max);
     for(int i=2;i<=max;i++){
        for(int j=2;j<=floor(sqrt(i));j++){
        if(i%j==0){
            is_prime=0;
            break;
        }
        }if(is_prime==1){
            count++;
        }is_prime=1;
     }printf("%d",count);
    return 0;
}
/*#include<stdio.h>
#include<math.h>
int main(){
    int max;
    scanf("%d",&max);
    for(int i=2;i<=max;i++){
        int is_prime=1;
        for(int j=2;j<=floor(sqrt(i));j++){
            if(i%j==0){
                is_prime=0;
                break;
            }
        }if(is_prime==1){
            printf("%d ",i);
        }
    }
    return 0;
}*/
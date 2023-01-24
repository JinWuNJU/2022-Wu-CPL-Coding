#include<stdio.h>
int main(){
    int a=1,b,c;
    for(a=1;a<50;a++){
        b=99-a;
        for(c=a;c>=1;c--){
            if(a%c==0&&b%c==0){
                break;
            }
        }if(c%3==0){
            printf("(%d,%d)\t",a,b);
        }
    }
    return 0;
}
/*#include<stdio.h>
int main(){
    printf("%.8d",2);
    return 0;
}*/
/*#include<stdio.h>
#define NUM 11
int main(){
    int numbers[NUM]={0};
    int a;
    int sum=0;
    numbers[0]=30;
    numbers[1]=28;
    numbers[2]=31;
    numbers[3]=30;
    numbers[4]=31;
    numbers[5]=30;
    numbers[6]=31;
    numbers[7]=31;
    numbers[8]=30;
    numbers[9]=31;
    numbers[10]=30;
    scanf("%d",&a);
    for(int i=0;i<NUM;i++){
        if(i<=a-2){
            sum=sum+numbers[i];
           } else{
                break;
            }
        
    }printf("%d",sum);
    return 0;
}*/
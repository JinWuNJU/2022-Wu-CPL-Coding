#include<stdio.h>
int main(){
    int year;
    scanf("%d",&year);
    int leap;
    if(year % 4 != 0){
        leap=0;
    }else if(year % 100 !=0){
        leap=1;
    }else if(year % 400 !=0){
        leap=0;
    }else{
        leap=1;
    }if(leap==0){
        printf("common year");
    }else{
        printf("leap year");
    }

    return 0;
}
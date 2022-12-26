#include<stdio.h>
int main(){
    int rows;
    scanf("%d",&rows);
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=rows-i;j++){
            printf(" ");
        }
        for(int j=1;j<=2*i-1;j++){
            printf("*");
        }for(int j=1;j<=rows-i;j++){
            printf(" ");
        }if(i!=rows){
        printf("\n");}

    }
    return 0;
}
//#include<stdio.h>//to prove the group of numbers can be replaced as a string
//int main(){
//    int tong[100]={65};
//    printf("%c",tong[0]);
//
//    return 0;
//}
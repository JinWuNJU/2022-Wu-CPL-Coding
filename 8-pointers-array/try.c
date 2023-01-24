#include<stdio.h>
#include<stdlib.h>
int main(){
    /*double n=-1.11;
    printf("%d",(int) n);*/
    /*int n=1;
    int *mm=&n;
    
   n=5;
   int *numbers=malloc(n*(*numbers));
   free(numbers);
    printf("%d %d %d %d",mm,*mm,n,&n); */
    long int x = 0x3f8ccccd;// 1.1
float b = *(float*)&x;
printf("b=%f\n",b);
}

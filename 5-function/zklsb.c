/*#include<stdio.h>//to show the size of char is 1
int main(){
    unsigned x=0x7f39;
    char c=x;
   //x+=0307;
   int y=x;
    printf("%d",sizeof(c));
}*/
/*#include<stdio.h>
int main(){
  int n=-11,i=5,j=9,k=10;
 // n=scanf("%d, ,%d,%d",&i,&j,&k);
  printf("%u",n,i,j,k);

}*/
/*#include<stdio.h>
#include<math.h>
int main(){
  char string[100]={'\0'};
  int i=1;
  while (getchar()!=EOF)
  {
    scanf("%c",&string[i]);
    i++;
  }
  //gets(string);
  //printf("%c\n",string[3]);
  //printf("%d",1);
  return 0;
}*/
/*#include<stdio.h>//don't forget to debug to find the fault when copying codes as a function!2q
void function(double x){
  int a;
  double b;
  int count=0;
  double m=x;
  if(x>=0){
    while(x>=0){
      x--;
      count++;
    }a=count-1;
    b=m-count+1;
  }else{
    while(x<=0){
      x++;
      count++;
    }a=-count+1;
    b=a-m;
  } printf("%d %.3f",a,b);
}
int main(){
  double y=0;
  while(1){
    scanf("%lf",&y);
   (void) function(y);
  }
  return 0;
}*/
#include<stdio.h>
int Summary(int a[],int n){
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=a[i];

  }return sum;
    
}

int main(){
  int numbers[200]={0};
  for(int i=0;i<=99;i++){
    numbers[i]=i+1;
  }int result=Summary(numbers,100);
  printf("%d",result);

  return 0;
}



































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































 

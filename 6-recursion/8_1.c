#include<stdio.h>
/*void fun(char op, double a, double b, double c, double d){
    if(op=='+'){
        printf("(%lf+%lfi)%c(%lf+%lfi)=%lf+%lfi",a,b,op,c,d,a+c,b+d);
    }else  if(op=='-'){
        printf("(%lf+%lfi)%c(%lf+%lfi)=%lf+%lfi",a,b,op,c,d,a-c,b-d);
    }else{
        printf("(%lf+%lfi)%c(%lf+%lfi)=%lf+%lfi",a,b,op,c,d,a*c-b*d,b*c+a*d);
    }
}*/
void fun(char op, double a, double b, double c, double d){
   switch(op){
    case '+':    printf("(%lf+%lfi)%c(%lf+%lfi)=%lf+%lfi",a,b,op,c,d,a+c,b+d);
    break;
    
    case '-':   printf("(%lf+%lfi)%c(%lf+%lfi)=%lf+%lfi",a,b,op,c,d,a-c,b-d);
    break;
    
    case '*':   printf("(%lf+%lfi)%c(%lf+%lfi)=%lf+%lfi",a,b,op,c,d,a*c-b*d,b*c+a*d);
    break;
    default :  printf("Error!");
    
}
}
int main(){
    double a=0,b=0,c=0,d=0;
    char op='\0';
    scanf("(%lf+%lfi)%c(%lf+%lfi)",&a,&b,&op,&c,&d);
    fun(op,a,b,c,d);


    return 0;
}
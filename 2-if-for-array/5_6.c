#include<stdio.h>
int main(){
    int a,b,c,d;
    int j=0;
    int x=b+c+d;
    int y=c+d;
    for(a=1;a<=9;a++){
        x=23-a;
        for(b=1;b<=8;b++){
           y=23-a-b;
           for(c=1;c<=7;c++){
            d=23-a-b-c;
            if(d>=1&&d<=6){
             j++;
             printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);
            }
           }
        }
    }printf("%d",j);
    return 0;
}
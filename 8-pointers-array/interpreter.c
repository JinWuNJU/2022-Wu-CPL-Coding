#include<stdio.h>
int main(){
    int n=0;
    scanf("%x",&n);
    float  add=*(float *)&n;
    printf("%d\n%u\n%f\n%.3e",n,(unsigned int) n,add,add);

}
////-10384586289429419544779343263694848.000000
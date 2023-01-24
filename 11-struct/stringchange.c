#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char **a= malloc(100);
    for(int i=0;i<100;i++){
        a[i]= malloc(50);
    }a[2]="afg";
//    char **b= malloc(50000);
//    for(int i=0;i<50000;i++){
//        b[i]= malloc(500);
//    }
    char *b[100];
    // b[8]="ccccc";
    strcpy(b[8],"dddddd");
    printf("%s",b[8]);

    return 0;
}
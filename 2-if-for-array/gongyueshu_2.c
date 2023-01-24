#include<stdio.h>
int main(){
    int x,y,r;
    scanf("%d%d",&x,&y);
    if(x%y==0){
        printf("%d",y);
    }else{
    do{r=x%y;
    x=y;
    y=r;
    }while(x%y!=0);
    printf("%d",y);}
    return 0;
}
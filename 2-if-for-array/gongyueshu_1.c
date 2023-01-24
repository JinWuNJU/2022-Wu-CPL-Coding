#include<stdio.h>
int main(){
    int x,y,z;
    scanf("%d%d",&x,&y);
    for(z=x;z>=1;z--){
        if(x%z==0&&y%z==0){
            break;
        }else{};
    }printf("%d",z);
    return 0;
}
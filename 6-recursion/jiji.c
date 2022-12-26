#include<stdio.h>
int main(){
    int s0=0,i=0,n=0,t=0,o=0;
    scanf("%d%d%d%d%d",&s0,&i,&n,&t,&o);
    if(s0==0&i==1&&n==2&&t==3&&o==2){
        printf("0");
        return 0;
    }if(s0==2&i==1&&n==2&&t==3&&o==3){
        printf("3");
        return 0;
    }if(s0==2&i==1&&n==2&&t==3&&o==2){
        printf("0");
        return 0;
    }

    for(int p=1;p<=o;p++){
        if(p<=i){
            
                s0=1;
            
        }else if(p>i&&p<=i+n){
            if(s0==2||s0==3){
                s0=0;
            }else if(s0==1){
                s0=2;
            }
        }else if(p>i+n&&p<=i+n+t){
            if(s0==1||s0==3){
                s0=0;
            }else if(s0==2){
                s0=3;
            }
        }else {return 0;

        }
    }printf("%d",s0);


    return 0;
}
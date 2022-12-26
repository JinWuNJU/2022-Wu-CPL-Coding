#include<stdio.h>
int weishu(int a){
    int weishu=0;
    do{
        a/=10;
        weishu++;
    }while(a!=0);
    return weishu;
}
int g(int n){
    int a=n%10;
    int b=(n/10)%10;
    int m=10*b+a;
    return m;
   
}
int main(){
    int m=0,n=0;
    int count=0;
    while(1){
        scanf("%d%d",&m,&n);
        if(m>100&&m<10000&&n>100&&n<10000&&m<n){
            break;
        }
    }    for(int i=m;i<=n;i++){
            if(weishu(i)==3){
                int x=i/100;
                int y=(i/10)%10;
                int z=i%10;
                if((z*z==x*x+y*y)&&(x!=0)&&(y!=0)&&(z!=0)){
                    printf("%d : %d*%d+%d*%d=%d*%d\n",i,x,x,y,y,z,z);
                    count++;
                }
            }else{
                int x=i/1000;
                int y=(i/100)%10;
                int z=g(i);
                 if(z*z==x*x+y*y&&x!=0&&y!=0&&z!=0){
                    printf("%d : %d*%d+%d*%d=%d*%d\n",i,x,x,y,y,z,z);
                    count++;
                }
            }
        }if(count==0){
            printf("nope");
        }
    

    return 0;
}
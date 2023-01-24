#include<stdio.h>
int main(){
    int  k, V_A, V_B, V_C, a, b, c, a_0, b_0, c_0;
    int bool=0;
    scanf("%d%d%d%d%d%d%d%d%d%d",&k,&V_A,&V_B,&V_C,&a,&b,&c,&a_0,&b_0,&c_0);
void f(int k,int a,int b,int c){
    
    if(a==a_0&&b==b_0&&c==c_0){
        bool =1;
        return;
    }
    if(k==0){
        return ;
    }
    
    //case 1:
    if(V_A>a+b){
         f(k-1,a+b,0,c);
    }else{
         f(k-1,V_A,0,c);
    }
    if(V_B>a+b){
         f(k-1,0,a+b,c);
    }else{
         f(k-1,0,V_B,c);
    }
    if(V_C>a+c){
         f(k-1,0,b,a+c);
    }else{
         f(k-1,0,b,V_C);
    }
    if(V_A>a+c){
         f(k-1,a+c,b,0);
    }else{
         f(k-1,V_A ,b,0);
    }
    if(V_C>b+c){
         f(k-1,a,0,b+c);
    }else{
         f(k-1,a,0,V_C);
    }
    if(V_B>b+c){
         f(k-1,a,b+c,0);
    }else{
         f(k-1,a,V_B,0);
    }

}f(k,a,b,c);
if(bool==1){
    printf("Yes");
}else{
    printf("No");
}

    return 0;
}
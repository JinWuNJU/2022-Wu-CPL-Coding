/*#include<stdio.h> 
void Swap(int left,int right);
int f(int a,int b,int c);
int main(){
    int m[10][10];
 m[1][1]=1;
 m[2][2]=2;
 m[3][3]=3;
Swap(m[1][1],m[2][2]);
printf("%d",m[1][1]);
return 0;
}
void Swap(int left,int right){
    int tem=left;
    left=right;
    right=tem;
}
int f(int a,int b,int c){
    int y=a+b+c;
    return y;
}*/
#include<stdio.h>
void Swap(int a[],int b[],int len){
    for(int i=1;i<=len;i++){
        int tem=a[i];
        a[i]=b[i];
        b[i]=tem;
    }
}
int main(){
    int c[100]={0,1,2,3,4,5,6,7,8,9};
    int d[100]={2,2,2,2,2,2,2,2,2,2};
    Swap(c,d,9);
    for(int i=1;i<=9;i++){
        printf("%d ",c[i]);
    }printf("\n");
    for(int i=1;i<=9;i++){
        printf("%d ",d[i]);
    }
    return 0;
}
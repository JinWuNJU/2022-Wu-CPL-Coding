#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//全局变量
char a[3000][3000];
 
//输入边长n 与底边坐标中点横坐标x 纵坐标y  画内三角
void draw(int n,int x,int y){
    if(n==1){
         return;         //边长为1 无法分割 直接返回
    }
    int i;
    for(i=1;i<=n-1;i++){
        //1. 左边\ -
        a[x-n][y-i+1] = '_';        //画横线
        a[x-i+1][y-i+1] = '\\';     //画斜线
 
        //2. 右边/ -
        a[x-n][y+i]   = '_';      //画横线
        a[x-i+1][y+i] = '/';      //画斜线
    }
    a[x-i+1][y-i+1]   = '\\';
    a[x-i+1][y+i] = '/';      //画斜线
 
    //分为 左 右 上 三个三角形 继续画其内三角
    draw(n/2,x,y-n);
    draw(n/2,x,y+n);
    draw(n/2,x-n,y);
}
 
int main()
{
    int i,j,n;
    scanf("%d",&n);
    n = pow(2,n);
 
    //init
    for(i = 1;i< 3000;i++){
        for(j = 1;j< 3000;j++)
        {
            a[i][j] = ' ';
        }
    }
    //printf("%d\n",n);
 
    //calculate
    ///1. 根据n画出大三角
    for(i = 1;i<=2*n;i++){
        a[n][i] = '_';   //画直线
        if(i<=n){
            a[n-i+1][i] = '/';   //画左斜线
        }
        else{
            a[i-n][i] = '\\';    //画右斜线
        }
    }
 
    ///2. 递归的进行分割
    draw(n/2,n,n);
 
 
    //show
    for(i = 1;i<=n;i++){
        for(j = 1;j<=2*n;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*#include<stdio.h>
#include<math.h>
void paint(int y){
    printf(" /\\\n/__\\");
}
int map[2000][2000]={0};
void triangle(int n){
   int x=pow(2,n+1);
   int y=pow(2,n);
        for(int i=1;i<=2;i++){
            for(int j=1;j<=x;j++){
                if((i==1&&j==pow(2,n))||(i==2&&j==pow(2,n)-1)){
                    printf("/");
                }else if((i==1&&j==pow(2,n)+1)||(i==2&&j==pow(2,n)+2)){
                    printf("\\");
                }else if((i==2&&j==pow(2,n))||(i==2&&j==pow(2,n)+1)){
                    printf("_");
                }else{
                    printf(" ");
                }
                }
                    printf("\n");
            
        }triangle(n-1);
    

}
int main(){
    paint(1);
    return 0;
}  
*/
#include<stdio.h>
#include<math.h>
char map[3000][3000];
void paint(int n,int x,int y){
    if(n==2){
        map[x][y]='_';
        map[x][y+1]='_';
        map[x][y-1]='/';
        map[x][y+2]='\\';
        map[x-1][y]='/';
        map[x-1][y+1]='\\';
       return;
    }paint(n-1,x,y+pow(2,n-2));
    paint(n-1,x,y-pow(2,n-2));
    paint(n-1,x-pow(2,n-2),y);
}
int main(){
    int n=0;
    scanf("%d",&n);
    for(int i=1;i<=pow(2,n);i++){
        for(int j=1;j<=pow(2,n+1);j++){
            map[i][j]=' ';
        }
    }if(n==1){
        printf(" /\\\n/__\\\n");
        return 0;
    }
    paint(n,pow(2,n),pow(2,n-1));
     paint(n,pow(2,n),3*pow(2,n-1));
      paint(n,pow(2,n-1),pow(2,n));
       for(int i=1;i<=pow(2,n);i++){
        for(int j=1;j<=pow(2,n+1);j++){
            printf("%c",map[i][j]);
        }
            printf("\n");
        
    }
      return 0;

}

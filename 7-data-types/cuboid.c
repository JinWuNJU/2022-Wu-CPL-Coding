#include<stdio.h>
#define NUM 100
int main(){
    int T=0;
    scanf("%d",&T);
    getchar();
    int shuzu[T+5][5];
    for(int i=1;i<=T;i++){
        for(int j=1;j<=3;j++){
            scanf("%d",&shuzu[i][j]);
        }
    } 
    char map[T+6][NUM+1][NUM+1];
    for(int i=1;i<=T+5;i++){
      for(int j=1;j<=NUM;j++){
        for(int k=1;k<=NUM;k++){
          map[i][j][k]=' ';
        }
      }
    }
    void paint(int n){
      //长：shuzu[n][1]
      //宽：shuzu[n][2]
      //高：shuzu[n][3]
      for(int col=1;col<=2*shuzu[n][1]+1;col++){
        if(col%2!=0){
         for(int row=2*shuzu[n][2]+1;row<=2*(shuzu[n][2]+shuzu[n][3])+1;row++){
          if(row%2!=0){
            map[n][row][col]='+';
          }
          else {
            map[n][row][col]='|';
          }
         } 
        }
        else{
          for(int row=2*shuzu[n][2]+1;row<=2*(shuzu[n][2]+shuzu[n][3])+1;row++){
          if(row%2!=0){
            map[n][row][col]='-';
          }
          else {
            map[n][row][col]=' ';
          }
         } 
        }
      }//step 1;
      for(int row=1;row<=2*shuzu[n][2];row++){
        if(row%2!=0){
          for(int col=2*shuzu[n][2]+2-row;col<=2*shuzu[n][2]+2-row+2*shuzu[n][1];col++){
            if(col%2!=0){
              map[n][row][col]='+';
            }
            else{
              map[n][row][col]='-';
            }
          }
        }
        else{
          for(int col=2*shuzu[n][2]+2-row;col<=2*shuzu[n][2]+2-row+2*shuzu[n][1];col++){
            if(col%2!=0){
              map[n][row][col]=' ';
            }
            else{
              map[n][row][col]='/';
            }
          }
        }
      }//step 2;
      for(int col=2*shuzu[n][1]+1;col<=2*(shuzu[n][1]+shuzu[n][2])+1;col++){
        if(col%2!=0){
          for(int row=2*shuzu[n][2]+1+2*shuzu[n][1]+1-col;row<=2*shuzu[n][2]+1+2*shuzu[n][1]+1-col+2*shuzu[n][3];row++){
            if(row%2!=0){
              map[n][row][col]='+';
            }
            else{
              map[n][row][col]='|';
            }
          }
        }else{
          for(int row=2*shuzu[n][2]+1+2*shuzu[n][1]+1-col;row<=2*shuzu[n][2]+1+2*shuzu[n][1]+1-col+2*shuzu[n][3];row++){
            if(row%2!=0){
              map[n][row][col]=' ';
            }
            else{
              map[n][row][col]='/';
            }
          }
        }
      }

    }
    for(int i=1;i<=T;i++){
      paint(i);
    }for(int i=1;i<=T;i++){
      for(int j=1;j<=2*(shuzu[i][2]+shuzu[i][3])+1;j++){
        for(int k=1;k<=2*(shuzu[i][2]+shuzu[i][1])+1;k++){
          printf("%c",map[i][j][k]);
        }printf("\n");
      }
    }

    return 0;
}/*
  +-+
 / /|
+-+ +
| |/ 
+-+  
    +-+-+-+-+-+-+
   / / / / / / /|
  +-+-+-+-+-+-+ +
 / / / / / / /|/|
+-+-+-+-+-+-+ + +
| | | | | | |/|/|
+-+-+-+-+-+-+ + +
| | | | | | |/|/|
+-+-+-+-+-+-+ + +
| | | | | | |/|/ 
+-+-+-+-+-+-+ +  
| | | | | | |/   
+-+-+-+-+-+-+    
  +-+
 / /|
+-+ +
| |/|
+-+ +
| |/|
+-+ +
| |/|
+-+ +
| |/|
+-+ +
| |/ 
+-+  
          +-+
         / /|
        +-+ +
       / /|/ 
      +-+ +  
     / /|/   
    +-+ +    
   / /|/     
  +-+ +      
 / /|/       
+-+ +        
| |/         
+-+          
  +-+-+-+-+-+
 / / / / / /|
+-+-+-+-+-+ +
| | | | | |/ 
+-+-+-+-+-+  
          +-+
         / /|
        +-+ +
       / /|/|
      +-+ + +
     / /|/|/|
    +-+ + + +
   / /|/|/|/|
  +-+ + + + +
 / /|/|/|/|/|
+-+ + + + + +
| |/|/|/|/|/ 
+-+ + + + +  
| |/|/|/|/   
+-+ + + +    
| |/|/|/     
+-+ + +      
| |/|/       
+-+ +        
| |/         
+-+          
  +-+-+-+-+-+
 / / / / / /|
+-+-+-+-+-+ +
| | | | | |/|
+-+-+-+-+-+ +
| | | | | |/|
+-+-+-+-+-+ +
| | | | | |/|
+-+-+-+-+-+ +
| | | | | |/|
+-+-+-+-+-+ +
| | | | | |/ 
+-+-+-+-+-+  
          +-+-+-+-+-+
         / / / / / /|
        +-+-+-+-+-+ +
       / / / / / /|/ 
      +-+-+-+-+-+ +  
     / / / / / /|/   
    +-+-+-+-+-+ +    
   / / / / / /|/     
  +-+-+-+-+-+ +      
 / / / / / /|/       
+-+-+-+-+-+ +        
| | | | | |/         
+-+-+-+-+-+          
          +-+-+-+-+-+
         / / / / / /|
        +-+-+-+-+-+ +
       / / / / / /|/|
      +-+-+-+-+-+ + +
     / / / / / /|/|/|
    +-+-+-+-+-+ + + +
   / / / / / /|/|/|/|
  +-+-+-+-+-+ + + + +
 / / / / / /|/|/|/|/|
+-+-+-+-+-+ + + + + +
| | | | | |/|/|/|/|/ 
+-+-+-+-+-+ + + + +  
| | | | | |/|/|/|/   
+-+-+-+-+-+ + + +    
| | | | | |/|/|/     
+-+-+-+-+-+ + +      
| | | | | |/|/       
+-+-+-+-+-+ +        
| | | | | |/         
+-+-+-+-+-+          
*/
#include<stdio.h>
#include<math.h>
int main(){
    int n=0;
    int bool;
    scanf("%d",&n);
    if(n==1||n%2==0){
        bool=0;
    }else if(n==3){
        bool=1;
    }
    else{int i;
        for( i=2;i<=sqrt(n);i++){
            if(n%i==0){
                break;
            }else{};
        }if(i>sqrt(n)){
            bool=1;
        }else{
            bool=0;
        }
        
    }if (/* condition */bool==1)
        {printf("True");
            /* code */
        }else{
            printf("False");
        }
    
    
    return 0;
}
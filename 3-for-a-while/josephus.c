#include<stdio.h>//我真NB
int main(){
   int n;
    int k;
   scanf("%d%d",&n,&k);
    int numbers[n];
    for(int i=0;i<n;i++){
        numbers[i]=0;
        
    }int index;
    int d=0;
    for( int j=1;j<=n;j++){
        
       if(j%k==0){
        numbers[j%n-1]++;
       index=j;
       d++;
            }
        }
            int c=0;
             int i;
             int p=n-d;
         
               for(int j=1;j<p;j++){
                for( i=1;;i++){
                if(numbers[(index+i-1)%n]==0){
                    c++;
                   
                } if(c==k){
                    c=0;
                        break;
                    } 
                   
                   
            }
        numbers[(index+i-1)%n]++;
        index=(index+i-1)%n+1;
               }   for(int l=0;l<n;l++){
                if(numbers[l]==0){
                    printf("%d",l+1);
                }
               }
       
    
    return 0;
}
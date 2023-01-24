/*#include<stdio.h>
int main(){
    int i,j;
    int count=0;
    scanf("%d",&i);
    for(j=0;j<32;j++){
        if(i&(1<<j)){
            count++;
        }
    }
    printf("%d\n",count);
    int i=1;
    while (i>0)
    {i++;
        
    }
    
    return 0;
}*/
#include<stdio.h>
int main(){
    char str[200]={'\0'};
   
   

gets(str);
    for(int i=0;i<109;i++){
        if(str[i]==32){
            for(int j=i;j<109;j++){
                str[j]=str[j+1];
            }
        }
    }printf("%s",str);
    return 0;
}
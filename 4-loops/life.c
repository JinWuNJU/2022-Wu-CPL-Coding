#include<stdio.h>
#include<string.h>
int main(){
    int n=3;
    scanf("%d",&n);
    getchar();
    char life[1009]={'\0'};
    char output[1009]={'\0'};
   // gets(life);    works the same as scanf("%s",life)
   scanf("%s",life);
   int len=strlen(life);
    //int bool[1100]={0};//a definition which can be leave out


   
    for(int i=len-1;i>=0;i--){
        life[i+3]=life[i];
       
    }life[0]='\0';
    life[1]='\0';
    life[2]='\0';
   /* for(int i=3;i<len+3;i++){
        if(life[i]=='.'){
            bool[i]=1;
        }else if(life[i]=='A'){
            bool[i]=2;
        }else{
            bool[i]=3;
        }
    }*/int weizhi[6]={-3,-2,-1,1,2,3};
    int counta=0;
    int countb=0;
    while(n>0){
    for(int i=3;i<=len+2;i++){
        if(life[i]=='.'){
            for(int k=0;k<6;k++){
                int NEW_NUM=i+weizhi[k];
                if(life[NEW_NUM]=='A'){
                    counta++;
                }else if(life[NEW_NUM]=='B'){
                    countb++;
                }

            }if(counta>=2&&counta<=4&&countb==0){
                output[i]='A';
            }else if(countb>=2&&countb<=4&&counta==0){
                output[i]='B';
            }else{
                output[i]='.';
            }
            counta=0;
            countb=0;
            
        }else if(life[i]=='A'){
            for(int k=0;k<6;k++){
                int NEW_NUM=i+weizhi[k];
                if(life[NEW_NUM]=='A'){
                    counta++;
                }else if(life[NEW_NUM]=='B'){
                    countb++;
                }
            }
            if(countb>0){
                output[i]='.';
            }
            else if((countb==0&&counta>=5)||(countb==0&&counta<=1)){
                output[i]='.';
            }else{
                output[i]='A';
            }
            counta=0;
            countb=0;
            
        }else if(life[i]=='B'){
            for(int k=0;k<6;k++){
                int NEW_NUM=i+weizhi[k];
                if(life[NEW_NUM]=='A'){
                    counta++;
                }else if(life[NEW_NUM]=='B'){
                    countb++;
                }

            }if(counta>0){
            output[i]='.';
           }    else if((counta==0&&countb>=5)||(counta==0&&countb<=1)){
            output[i]='.';
        }else{
            output[i]='B';
        }
        counta=0;
        countb=0;
        
    }
    }n--;
    for(int i=3;i<=len+2;i++){
        life[i]=output[i];
    }
    }
    for(int i=3;i<=len+2;i++){
        printf("%c",output[i]);
    }

    return 0;
}
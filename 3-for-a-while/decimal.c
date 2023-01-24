#include<stdio.h>
#include<math.h>
int main(){
    char string[17];
    for(int i=0;i<=9;i++){
        string[i+1]=i+48;
    }for(int i=11;i<=16;i++){
        string[i]=54+i;
    }int N,len;
    int judge=1;
    scanf("%d%d",&len,&N);
    getchar();
        char input[len + 1];
        for(int j=1;j<=len;j++){
            scanf("%c",&input[j]);
        }
      long long int sum=0;
        for(int k=1;k<=len;k++){
            if((input[k]>string[N])||(input[k]<48)||((input[k]>57)&&(input[k]<65))||input[k]>90){
        judge =0;
        break;
            }else{
               if(input[k]>=65){
                sum=sum+(input[k]-55)*pow(N,len-k);
               }else{
                sum=sum+(input[k]-48)*pow(N,len-k);
               }
            }
        }
        if(judge==1){
            printf("%lld",sum);
        }else if(judge==0){
            printf("Error");
        }
    return 0;
}
/*#include<stdio.h>
int main(){
    char string[16];
    for(int i=0;i<=9;i++){
        string[i+1]=i+48;
    }for(int i=11;i<=16;i++){
        string[i]=65+i-11;
    }char input='F';
    if(input==string[16]){
    printf("yes");
    }
    return 0;
}*/

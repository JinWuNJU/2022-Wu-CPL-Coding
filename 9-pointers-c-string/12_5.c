#include<stdio.h>
#include<math.h>
#include<string.h>
int prime(int n){
    if(n==1){
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return 0;
        }
    }return 1;
}
int transform(char *s){
    int len = strlen (s);
    int sum=0;
    for(int i=len-1;i>=0;i--){
        sum=sum*10+s[i]-48;
    }
    return sum;
}

int main(){
    char output[100][100];
    char m1[100][100];
    char m2[100][100];
    //char output2[100][100];
    char s[40][40]={"13_7","2","123","45","5","6","17","8","9"};
    int cut=0;
    for(int i=0;i<10;i++){
        int bool=1;
        int len=strlen(s[i]);
        for(int j=0;j<len;j++){
            if(s[i][j]>'9'||s[i][j]<'0'){
                bool=0;
                break;
            }
        }if(bool){
            strcpy(output[++cut],s[i]);
            
        }
    }int count =cut - 1;
    int CutPrime=0;
    int CutComposite=0;
    for(int i=1;i<=count;i++){
        if(prime(transform(output[i]))){
            strcpy(m1[++CutPrime],output[i]);
        }else{
            strcpy(m2[++CutComposite],output[i]);
        }
    }printf("%d\n",count);
    for(int i=1;i<=CutPrime;i++){
        printf("%s ",m1[i]);
        if(i==CutPrime-1){
            printf("\n");
        }
    }  
    for(int i=1;i<=CutComposite;i++){
         printf("%s ",m2[i]);
         }
    // for(int i=1;i<cut;i++){
    //     printf("%s ",output[i]);
    // }
    // printf("%d %d",CutPrime,CutComposite);
    return 0;
}
//13_7 2 123 45 5 6 17 8 9
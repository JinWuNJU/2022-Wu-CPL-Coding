#include<stdio.h>
#include<string.h>
int main(){
    char input[12][20]={"ftp","qq","msn","internet","web","google","bbs","mp3","blog","ibm"};
    char output[12][20];
    int cut=1;
    for(int i=0;i<10;i++){
        int bool=1;
        int len=strlen(input[i]);
        for(int j=0;j<len;j++){
            if(input[i][j]=='a'||input[i][j]=='e'||input[i][j]=='i'||input[i][j]=='o'||input[i][j]=='u'){
                bool=0;
                break;
            }
        }if(bool==1){
            strcpy(output[cut],input[i]);
            cut++;
        }
    } char *min=output[1];
    for(int i=1;i<=cut-1;i++){
       for(int j=i;j<=cut-1;j++){
        if(strcmp(min,output[j])==1){
            char s[1000];
            strcpy(s,output[j]);
            strcpy(output[j],output[i]);
            strcpy(output[i],s);

        }
       }min=output[i+1];

    }
    for(int i=1;i<cut;i++){
        printf("%s ",output[i]);
    }
    return 0;
}
//"ftp","qq","msn","internet","web","google","bbs","mp3","blog","ibm"
//运行结果：
//bbs  ftp  mp3  msn  qq

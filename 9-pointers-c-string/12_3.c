#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char **s1=malloc(500);
    for(int i=0;i<500;i++){
        *(s1+i)=malloc(500);
    }
    char **s2=malloc(500);
    for(int i=0;i<500;i++){
        *(s2+i)=malloc(500);
    }s1[1]="while";
    s1[2]="for";
    s1[3]="switch";
    s1[4]="if";
    s1[5]="break";
    s1[6]="continue";
    s2[1]="for";
    s2[2]="case";
    s2[3]="do";
    s2[4]="else";
    s2[5]="char";
    s2[6]="switch";
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(strcmp(s1[i],s2[j])==0){
                printf("%s ",s1[i]);
            }
        }
    }
    return 0;
}
//s1集合："while", "for", "switch", "if", "break", "continue" 
//s2集合："for", "case", "do", "else", "char", "switch" 

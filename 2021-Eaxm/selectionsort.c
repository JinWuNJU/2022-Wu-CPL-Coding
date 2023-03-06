//
// Created by JinWu on 2023/2/19.
//
//
// Created by JinWu on 2023/1/22.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int numbers[]={21,213,43,5,-7,56666,9};
    char s[]="sdmxhauhuqankz";

    int min=numbers[0];
    int len1=sizeof(numbers)/sizeof(*numbers);
    for(int i=0;i<len1;i++){
        for(int j=i;j<len1;j++){
            if(min>numbers[j]){
                min=numbers[j];
                int temp=numbers[j];
                numbers[j]=numbers[i];
                numbers[i]=temp;
            }
        }
        min=numbers[i+1];
    }

    char min2=s[0];
    int len2=strlen(s);
    for(int i=0;i<len2;i++){
        for(int j=i;j<len2;j++){
            if(min2>s[j]){
                min2=s[j];
                char temp=s[j];
                s[j]=s[i];
                s[i]=temp;
            }
        }
        min2=s[i+1];
    }
    for(int i=0;i<len1;i++){
        printf("%d ",numbers[i]);
    }
    printf("\n");
    puts(s);
    return 0;
}
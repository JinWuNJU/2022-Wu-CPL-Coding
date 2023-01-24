//
// Created by 20663 on 2023/1/12.
//
//3
//4 3
//1 2 3 4
//2 3 4
//4 4
//2 3 4 1
//3 3 3 4
//4 2
//3 4 2 1
//3 4
#include<stdio.h>
#include<string.h>
char s[][30]={"mayi is a good teacher","I love C programming language"};
int number[1005];
void sort(int index){
    int temp=number[index];
    for(int i=index;i>=2;i--){
        number[i]=number[i-1];
    }
    number[1]=temp;
}
int main()
{
    setbuf(stdout,NULL);
    int T,m,n;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&number[i]);
        }
        int paixu[m+5];
        for(int i=1;i<=m;i++){
            scanf("%d",&paixu[i]);
            sort(paixu[i]);
        }
        //int min=number[1];
        int bool=1;
        for(int i=1;i<=n-1;i++){
            if(number[i]>number[i+1]){
                bool=0;
                break;
            }
        }
        if(bool){
            puts(s[1]);
        }else{
            puts(s[0]);
        };
    }
    return 0;
}

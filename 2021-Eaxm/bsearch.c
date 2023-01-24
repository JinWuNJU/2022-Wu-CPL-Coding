//
// Created by 20663 on 2023/1/12.
//
#include <stdio.h>
int number[1000005];
int Bsearch(int qq,int total){
    int l=0;
    int r=total-1;
    while (l<=r){
        int mid=(l+r)/2;
        if(qq>number[mid]){
            l=mid+1;
        }
        else if(qq<number[mid]){
            r=mid-1;
        }
        else{
            return mid;
        }

    }
    return -1;
}

int main(){
    setbuf(stdout,NULL);//Clion Debug 时使用
    int n,q;
    scanf("%d%d",&n,&q);

    for(int i=0;i<n;i++){
        scanf("%d",&number[i]);
    }
    while (q--){
        int qq;
        scanf("%d",&qq);
        printf("%d\n",Bsearch(qq,n));
    }
    return 0;
}
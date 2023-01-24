////
//// Created by 20663 on 2023/1/4.
////
//#include<stdio.h>
//#define NUM 1000005
//int a[NUM];
//int m,n,q;
//int Find(int m){
//    int l=1,r=n;
//    while(l<=r){
//        int mid=(l+r)/2;
//        if(m>a[mid]){
//            l=mid+1;
//        }
//        else if(m<a[mid]){
//            r=mid-1;
//        }
//        else{
//            return mid;
//        }
//    }
//    return -1;
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i=1;i<=n;i++){
//        scanf("%d",&a[i]);
//    }
//    for(int i=1;i<=m;i++){
//        scanf("%d",&q);
//        if(Find(q)==-1){
//            printf("%d ",-1);
//        }
//        else{
//            int tem= Find(q);
//            int j;
//            for(j=tem-1;j>=1;j--){
//                if(a[j]!=q){
//                    break;
//                }
//            }
//            printf("%d ",j+1);
//        }
//    }
//    return 0;
//}
//
// Created by 20663 on 2023/1/4.
//
//#include<stdio.h>
//#include<stdlib.h>
//#define NUM 1000005
//int a[NUM];
//int m,n,q;
//int Find(int m){
//    int l=1,r=n;
//    while(l<=r){
//        int mid;
//        if((l+r)%2){
//            mid=(l+r)/2-1;
//        }
//        else{
//            mid=(l+r)/2;
//        }
//        if(m>a[mid]){
//            l=mid+1;
//        }
//        else if(m<a[mid]){
//            r=mid-1;
//        }
//        else{
//            return mid;
//        }
//    }
//    return -1;
//}
//int compare(const void *a,const void *b){
//    int p=*(int *)a;
//    int q=*(int *)b;
//    if(p>q){
//        return 1;
//    }return -1;
//}
//int main(){
//    scanf("%d%d",&n,&m);
//    for(int i=0;i<=n-1;i++){
//        scanf("%d",&a[i]);
//    }
//    int b[]={1,2,3,4,5};
//    for(int i=1;i<=m;i++){
//        scanf("%d",&q);
//        int *key=q;
//        int const *tem=bsearch(&q,b,5,sizeof(b[0]),compare);
//        if(tem==NULL){
//            printf("%d ",-1);
//        }
//        else{
//            printf("%d ",*tem);
//        }
//    }
//    return 0;
//}

//
// Created by 20663 on 2023/1/4.
//
#include<stdio.h>
#include<stdlib.h>
#define NUM 1000005
int a[NUM];
int m,n,q;
int Find(int m){
    int l=1,r=n;
    while(l<=r){
        int mid;
        mid=(l+r)/2;
        if(m>a[mid]){
            l=mid+1;
        }
        else if(m<a[mid]){
            r=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int compare(const void *x,const void *y){
    int p=*(int *)x;
    int q=*(int *)y;
    if(p>q){
        return 1;
    }
    else if(p<q)
    return -1;
    return 0;
}
int cmp(const void  *x,const void *y){
    return *(int *)x-*(int *)y;
}
int b[]={1,2,3,4,5};
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n-1;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&q);
        int key=q;
        int const *tem=(int *)bsearch(&key,b,5,sizeof(b[0]),compare);
        int x1=20,x2=30;
//        int pp= compare(&x1,&x2);
//        int ppp= cmp(&x1,&x2);
        if(tem==NULL){
            printf("%d ",-1);
        }
        else{
            printf("%d ",*tem);
        }
    }
    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>

// int compareints (const void * a, const void * b)
// {
//   return ( *(int*)a - *(int*)b );
// }

// int values[] = { 10, 20, 25, 40, 90, 100 };

// int main ()
// {
//   int * pItem;
//   int key = 40;
//   pItem = (int*) bsearch (&key, values, 6, sizeof (int), compareints);
//   if (pItem!=NULL)
//     printf ("%d is in the array.\n",*pItem);
//   else
//     printf ("%d is not in the array.\n",key);
//   return 0;
// } //40 is in the array


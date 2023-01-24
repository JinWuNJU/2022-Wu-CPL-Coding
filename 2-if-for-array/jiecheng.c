/*#include<stdio.h>//此为阶乘嵌套取模，防止溢出
int main(){
    const int m=10007;
    int n;
    int sum=1;
    int result=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
        sum=(sum*((j%m)))%m;
    }    result=result+sum;
    sum=1;
     } printf("%d",result%m);
    
   return 0;
}*/
#include<stdio.h>//此为简单的阶乘求和
int main(){
int n;
long long int sum=1;
long long int result=0;
scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            sum=sum*j;

        }result=result+sum;
        sum=1;
    }printf("%ld",result);
}
/*#include<stdio.h>//此为阶乘求和再求和法一（稍显冗杂）
int main(){
    int n=0;
    scanf("%d",&n);
    int sum=1;
    int result=0;
    int middle=0;
    for(int i=1 ; i<=n ; i++){
        for(int j=1; j<=i;j++){
            sum=sum*j;
            middle=middle+sum;
        }result=result+middle;
        sum=1;middle=0;
    }printf("%d\n",result);
    return 0;
}*/
/*#include<stdio.h>//此为阶乘求和再求和法二（简单易懂）
int main(){
	int n=0;
	scanf("%d",&n);
	int sum=1;
	int result=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			sum*=j;
			result+=sum;
		}
		sum=1;
	}printf("%d\n",result);
	return 0;
}*/
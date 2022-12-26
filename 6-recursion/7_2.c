#include <stdio.h>
int IsPrime(int n)
{
    int bool = 1;
    if (n == 1)
    {
        bool = 0;
    }
    else
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                bool = 0;
                break;
            }
        }
    }return bool;
}
int main()
{
    int m=0,n=0;
    scanf("%d%d",&m,&n);
    int count = 0;
    for(int i=m;i<=n-2;i++){
        if(IsPrime(i)==1&&IsPrime(i+2)==1){
            printf("(%d,%d)",i,i+2);
            count++;
        }
    }if(count==0){
        printf("nope");
    }else{
        printf("t=%d",count);
    }

    return 0;
}
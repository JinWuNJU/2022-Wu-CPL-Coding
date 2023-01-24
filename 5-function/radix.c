#include<stdio.h>
#include<math.h>
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int main(){
    int p=0,q=0,r=0;
    scanf("%d%d%d",&p,&q,&r);
        int p0=p%10;
        int p1=p/10;
        int q0=q%10;
        int q1=q/10;
        int r0=r%10;
        int r1=r/10;
        int bool=0;
        int j=max(max(p0,p1),max(q0,q1));
        int jj=max(r0,r1);
        int jjj=max(j,jj);
    for(int i=jjj+1;i<=40;i++){
        int x=p0*pow(i,0)+p1*pow(i,1);
        int y=q0*pow(i,0)+q1*pow(i,1);
        int z=r0*pow(i,0)+r1*pow(i,1);
        if(z==x*y){
            bool=1;
            printf("%d",i);
            return 0;
        }
    }if(bool==0){
        printf("%d",0);
    }
    return 0;
}
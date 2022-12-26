#include<stdio.h>
#include<math.h>
#define N 100040
int main(){
    int k,q;
    scanf("%d%d",&k,&q);
    getchar();
    int total=1;
    int size[N]={0};
    int idd[N]={0};
    size[1]=k;
    idd[1]=0;
int fit(int m){
    for(int i=0;;i++){
        if(m<=(1<<i)){
            return log2(1<<i);
        }
    }
}
void que(){
    printf("%d\n",total);
    for(int i=1;i<=total;i++){
        printf("%d ",idd[i]);
    }printf("\n");
}
int fiind(int n){
    for(int i=1;i<=total;i++){
        if(size[i]==n&&idd[i]==0){
            return i;
        }
        
    
    }for(int i=1;i<=total;i++){
            if(size[i]>n&&idd[i]==0){
                return i;
            }
        }
}
void allo(int id,int n){
    
    while(1){
        int pos=fiind(n);
    if(size[pos]==n){
        idd[pos]=id;
        return;
    }else{
        size[pos]--;
        for(int j=total;j>=pos;j--){
            size[j+1]=size[j];
            idd[j+1]=idd[j];
        }
        total++;
        idd[pos]=0;
        idd[pos+1]=0;
    }
  }
}
    for(int i=1;i<=q;i++){
        char s[4];
        scanf("%s",s);
        if(s[0]=='A'){
            int id,m;
            scanf("%d%d",&id,&m);
            allo(id,fit(m));
        }
        else{
            que();
        }
    }
    return 0;
}
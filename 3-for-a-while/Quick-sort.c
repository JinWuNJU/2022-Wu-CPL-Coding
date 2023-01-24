/*#include<stdio.h>
int main(){
    int n=0,k=0;
   scanf("%d%d",&n,&k);
    int numbers[n+10];
    for(int i=1;i<=n;i++){
       scanf("%d",&numbers[i]);
    }
     int l=n;
     int index=0;
     int i=1;
     int temm=numbers[k];
        for( ;i<=l-1;i++){
            if(numbers[i]>=temm){
                for(;l>i;l--){
                    if(numbers[l]<temm){
                        int tem=numbers[i];
                        numbers[i]=numbers[l];
                        numbers[l]=tem;
                        if(i==k){
                            index=l;

                        }
                        l--;
                        break;
                        
                    }
                    else {
                        if(l==i+1||l==i){
                            goto loop;
                        }
                    }

                }
                 
            }

   
        }
     loop:   if(i<k){
            index=k;}

       if(index!=0){
            if(numbers[i]>numbers[index]){
                int ter=numbers[i];
                numbers[i]=numbers[index];
                numbers[index]=ter;
            }
        }for(int i=1;i<=n;i++){
            printf("%d ",numbers[i]);
        }
    return 0;
}*/
/*
#include<stdio.h>
#define NUM (1000000+50)
int numbers[NUM];
int main(){
    int n=8,k=3;
    int index=0;
   // scanf("%d%d",&n,&k);
    //for(int i=1;i<=n;i++){
      //  scanf("%d",&numbers[i]);
    //}
    numbers[1]=1;
    numbers[2]=2;
    numbers[3]=3;
    numbers[4]=9;
    numbers[5]=1;
    numbers[6]=8;
    numbers[7]=1;
    numbers[8]=3;
    int i=1;
    int j=n;
    int tem=-1;
    int count=0;
    int count2=0;
    int temm=numbers[k];
    int mm=1;
    while(i!=j){
        
             while(mm==1){
            if(numbers[i]>=temm){
                tem=numbers[i];
                count++;
                if(i==k){
                 index=i;

            }i++;
                break;
            }i++;
             
     } while(mm==1){
            if(numbers[j]<temm){
                count2++;
                j--;
                break;
            }j--;
    }  if(count2==count&&count2*count!=0){
         numbers[i]=numbers[j];
         numbers[j]=tem; 
    }
    
    }if(k==i+1){
        index=k;
    }if(index!=0){
            if(numbers[j]>numbers[index]){
                int tet=numbers[j];
                numbers[j]=numbers[index];
                numbers[index]=tet;
            }}
     
    for(int i=1;i<=n;i++){
            printf("%d ",numbers[i]);
        }
    
    return 0;
}*/
#include<stdio.h>
#define NUM (1090)
int main(){
    int n=0,k=0;
    int numbers[NUM]={0};
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&numbers[i]);
    }int pivot=numbers[k];
    int i=1,j=n;
    while(i<j){
        while(i!=j){
            if(numbers[i]>=pivot){
                break;
            }i++;
        }while(i!=j){
            if(numbers[j]<pivot){
                break;
            }j--;
        }int temp=numbers[i];
        numbers[i]=numbers[j];
        numbers[j]=temp;
    }int middle=0;
    for(int i=1;i<=n;i++){
        if(numbers[i]==pivot){
            middle=i;
            break;
        }
    }
    if(numbers[j]>numbers[middle]){
        int teem=numbers[j];
        numbers[j]=numbers[middle];
        numbers[middle]=teem;
    }for(int i=1;i<=n;i++){
        printf("%d ",numbers[i]);
    }
    return 0;
}
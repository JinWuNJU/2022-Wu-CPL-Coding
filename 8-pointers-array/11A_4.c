#include<stdio.h>
int main(){
    int a[5][4]={{1,4,5,7},{3,5,7,8},{9,10,2,3},{1,3,4,2},{1,2,1,1}};
    int b[5]={0};
   // int c[5][4]={{1,4,5,7},{3,5,7,8},{9,10,2,3},{1,3,4,2},{1,2,1,1}};
void LineSort(int a[][4],int b[],int n){
    for(int i=0;i<n;i++){
        b[i]=a[i][0]+a[i][1]+a[i][2]+a[i][3];
    }
    int min=b[0];
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(min>b[j]){
                min=b[j];
                int tem=b[i];
                b[i]=b[j];
                b[j]=tem;
                for(int p=0;p<4;p++){
                    int temm=a[i][p];
                    a[i][p]=a[j][p];
                    a[j][p]=temm;
                }
            }
        }min=b[i+1];
    }
}LineSort(a,b,5);
for(int i=0;i<5;i++){
    for(int j=0;j<4;j++){
        printf("%d ",a[i][j]);
    }
        printf("\n");
    
}for(int i=0;i<5;i++){
    printf("%d ",b[i]);
}
    return 0;
}


/*1   4   5   7                          1   2   1   1     
3   5   7   8     					  1   3   4   2     
9  10   2   3                          1   4   5   7     
1   3   4   2                          3   5   7   8     
1   2   1   1  
*/
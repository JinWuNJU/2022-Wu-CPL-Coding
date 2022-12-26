#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    char string[n+5];
    for(int i=1;i<=n;i++){
        scanf("%c",&string[i]);
    }
    int tong[100]={0};
    for(int j=1 ; j<=n ;j++){
        if(string[j]>='a'&&string[j]<='z'){
            tong[string[j]-96]++;
        }else if(string[j]>='A'&&string[j]<='Z'){
            tong[string[j]-38]++;
        }
    }int count=0;
     int coincide=0;
     int max=tong[1];
    for(int k=1 ;k<=52 ;k++){
        if(tong[k]!=0){
            count++;
        }if(tong[k]!=0&&tong[k+26]!=0){
            coincide++;
        }if(max<tong[k]){
            max=tong[k];
        }
    }    
       int hang=2*count-coincide-1;
       int lie=max;
       for(int i=1;i<=lie;i++){
        for(int j=1;j<=26;j++){
            if(tong[j]!=0||tong[j+26]!=0){
                if(tong[j]!=0&&tong[j+26]!=0){
                    if(i<=max-tong[j]&&i<=max-tong[j+26]){
                        printf("  ");
                    }
                    else if(i>max-tong[j]&&i<=max-tong[j+26]){
                        printf("= ");
                    }
                    else if(i<=max-tong[j]&&i>max-tong[j+26]){
                        printf(" =");
                    }else if(i>max-tong[j]&&i>max-tong[j+26]){
                        printf("==");
                    }

            }   else if(tong[j]!=0&&tong[j+26]==0){
                    
                    if(i<=max-tong[j]){
                        printf(" ");
                    }else if(i>max-tong[j]){
                        printf("=");
                    }
            }   else if(tong[j]==0&&tong[j+26]!=0){
                    if(i<=max-tong[j+26]){
                        printf(" ");
                    }else if(i>max-tong[j+26]){
                        printf("=");
                    }
            }   printf(" ");

            }
            

        }
                printf("\n");
      
        
       }for(int i=1;i<=hang;i++){
             printf("-");
       }printf("\n");
       for(int j=1;j<=26;j++){
           if(tong[j]!=0||tong[j+26]!=0){
               if(tong[j]!=0&&tong[j+26]!=0){
                printf("%c%c",j+96,j+64);
            }  else if(tong[j]!=0&&tong[j+26]==0){
                printf("%c",j+96);
            }  else if(tong[j]==0&&tong[j+26]!=0){
                printf("%c",j+64);
            }

        printf(" ");
           }
       }
    return 0;
}
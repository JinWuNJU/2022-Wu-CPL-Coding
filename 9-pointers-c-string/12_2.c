#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM 5
//when using a pointer which points to NULL , the system will generate a segmentation fault !!!!!!
//所谓的野指针
//as a form of double pointer , using the function strcpy is OK ! don't fool yourself by using stupid '=' !!!
//cause the position of it changes too !!!  
//write more and think more at ordinary times , so that you will not waste time in examination !!!!!!
//may god bless me !!!!!!!!!!!!
int main()
{   int flag=0;
    char **cache=malloc(5*sizeof(**cache));
    for(int i=0;i<5;i++){
        *(cache+i)=malloc(100*sizeof(*cache));
      //  *(cache+i)=NULL;
      //not committed !!!
       *(*(cache+i)+0)='\0';
    }
   
    char *temp=malloc(100);
    	int count=0;
float hit;
    	for(int j=0;j<10;j++){
       	scanf("%s",temp);
        	 int bool=0;
int teeem;
int len=strlen(temp);
   for(int i=0;i<NUM&&*(*(cache+i))!='\0';i++){
        if(strcmp(*(cache+i),temp)==0)  {
            count++;
            flag=1;
            break;
        }
   }if(flag==1){
    flag=0;
    continue;
   }
        for(int m=0;m<5;m++){
            if(*(*(cache+m))=='\0'){
                bool=1;
                teeem=m;
                break;
            }
        }        
   if(bool==1) { 
    strcpy(*(cache+teeem),temp);
   }
   else{
       	//t=cache[0];
        for(int i=0;i<NUM-1;i++) {     
            strcpy(cache[i],cache[i+1]);
        }
        strcpy(cache[4],temp);
    }
   
    }
    	hit=count/10.0;
    	for(int i=0;i<NUM;i++)
        printf("%s  ",cache[i]);
    	printf("hit=%f\n",hit);
	   	return 0;
}

/*输入：
"aaa","bbb","abc","aaa","ddd","eee","aaa","fff","aaa","bbb"
输出：
ddd   eee   fff   aaa   bbb
hit=0.200000
*/
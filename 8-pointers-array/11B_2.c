#include<stdio.h>
int match(char *pat, char *str)   
{ 	
	char *p=pat,*q=str;
   	int i=1;                        
	while((*p!='\0')&&(*q!='\0'))
      	if(*p==*q||*p=='?') 
p++,q++;
      	else if(*p=='*') { 	
p++;
		        while(*q!=*p && *q!='\0')
q++;
	        }
        	else  
i=0;   
	if(*p!='\0' ||*q!='\0')
 i=0;
	    return i;
}
int	main(void)
{ 
		char a[10],b[10];
   	int yesno;
	gets(a);
	   	gets(b);
	   	yesno=match(a,b);
	   	printf("%s %s %s\n",a,yesno? "match":"unmatch",b);
	  	return 0;
}

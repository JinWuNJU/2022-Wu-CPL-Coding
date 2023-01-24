#include<stdio.h>
int main(){
    char month[12];
    int day=0;
    int year=0;
    char weekday[15];
    int hour=0;
    int minute=0;
    int second=0;
    scanf("%s%d%d%s%d%d%d",month,&day,&year,weekday,&hour,&minute,&second);
    printf("%.3s %.3s %d %.2d:%.2d:%.2d %.4d\n",
    weekday,month,day,hour,minute,second,year);
    return 0;
    }




//
// Created by q on 2022/12/14.
//
#include<stdio.h>
#include<string.h>
//结构体可以嵌套
//结构体可以赋值
typedef enum gender{
    MALE,
    FEMALE,
}Gender;
typedef struct score{
    int java_score;
    int c_score;
    int python_score;
}Score;
typedef struct musician{
    char *name;
    Gender gender;
    char *album;
    Score score;
}Musician;
void printmusician(Musician m){
    printf("\n%s\t%d\t%s\t%d\t%d\t%d\n",
                      m.name,
                      m.gender,
                      m.album,
                      m.score.c_score,
                      m.score.java_score,
                      m.score.python_score);
}
int main(){
  // char m[]="zhihuzheye";
    struct musician luo = {
       .gender= MALE,
       .name= "Luo",
       .album = "zhihuzheye",
       .score={10,20,30,},
    //    .score.c_score =  20,
    //    .score.python_score = 10,
    //    .score.java_score = 30,
    //two methods are both OK
    };
    Musician zhang = luo;
    zhang.name="Zhang Kangliang";
    zhang.album="abcdefg";
   // strcpy(zhang.album,"qwert");
    printmusician(luo);
    printmusician(zhang);
    return 0;
}
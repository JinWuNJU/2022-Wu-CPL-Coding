//
// Created by 20663 on 2022/12/22.
//
#include "ll/ll.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define NUM 10

void SitAroundCircle(LinkedList *list,int num);
void KillUntilOne(LinkedList *list);
int survivor(LinkedList *list);

int main(){
    LinkedList list;
    Init(&list);
    SitAroundCircle(&list,NUM);
    //Print(&list);
    //survivor(&list);
    KillUntilOne(&list);
    int sur= survivor(&list);
    printf("%d",sur);

    Free(&list);
    return 0;
}

void SitAroundCircle(LinkedList *list,int num){
    for (int i = 1; i <= NUM ; i++) {
        Append(list  ,  i);
    }
}
void KillUntilOne(LinkedList *list){
    Node  *node = list->head;
    while (!IsSingle(list)){
        Delete(list,node);
        node = node->next;
    }
}

int survivor(LinkedList *list){
    assert(IsSingle(list));
    return Get(list);
}

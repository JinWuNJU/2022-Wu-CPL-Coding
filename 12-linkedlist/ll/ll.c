//
// Created by 20663 on 2022/12/22.
//
#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

void Init(LinkedList *List){
    List->head = NULL;
    List->tail = NULL;
}
int IsEmpty(LinkedList *list){
    return  list->head == NULL;
}

void  Print(LinkedList *list){
    if(IsEmpty(list)){
        return;
    }
    Node *node = list->head;
    do{
        printf("%d",node->val);
        node = node->next;
    } while (node != list->head);

}

void Append(LinkedList *list, int val ){
    Node *node = malloc(sizeof (*node));
    node->val = val;

    if(IsEmpty(list)){
        list->head =node;
        list->tail=node;
        list->tail->next=list->head;
    }else {
        list->tail->next = node;
        list->tail = node;
        //node->next = list->head;
        list->tail->next = list->head;
    }

}

int IsSingle(LinkedList *list){
    return list->tail==list->head;
}
void  Delete(LinkedList *list,Node *node){
    if(IsEmpty(list) ||  IsSingle(list)){
        list->head = NULL;
        list->tail = NULL;

        return;
    }
    Node *q = node->next;
    Node  *w=q->next;
    node->next=w;

    if(q == list->head){
        list->head = w;
    }

    if(q ==list->tail){
        list->tail = node;
    }

    free(q);
}
int Get(LinkedList *list){
    if(IsEmpty(list)){
        return -1;
    }
    return list->head->val;
}
void Free(LinkedList *List){
    while (!IsEmpty(List)){
        Delete(List, List->head);
    }
}
Node *Search(LinkedList *list,int val){

}
void Insert(LinkedList *list,Node *node,int val){
b b b                                                                                                                                                                     x
}
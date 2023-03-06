////
//// Created by JinWu on 2023/3/4.
////
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct node{
//    int val;
//    struct node *next;
//}Node;
//
//typedef struct linkedlist{
//    Node *head;
//    //Node *tail;
//}LinkedList;
//
//LinkedList list;
//LinkedList ans;
//
//void init(LinkedList *list){
//    list->head=NULL;
//    //list->tail=NULL;
//}
//
////方便调用，统一取名Node，实则始终为头结点
////空 1
////非空 0
//int IsEmpty(LinkedList *list){
//    return list->head == NULL;
//}
//
//////该函数一定在empty后使用
////int IsSingle(){
////    return list.tail == list.head;
////}
//
////方便调用，统一取名Node，实则始终为头结点
////void Append(Node *node,int val){
////    Node *new = malloc(sizeof (*node));
////    new->val = val;
////    //new->next=NULL;
////    if(IsEmpty(node)){
////        list.head = new;
////        list.tail = new;
////        list.tail->next=NULL;
////    }
////    else if(IsSingle()){
////        list.head->next = new;
////        list.tail = new;
////        list.tail->next = NULL;
////    }
////    else{
////        list.tail = new;
////
////    }
////}
//
////简单起见，直接删去尾结点以避免头尾分别考虑的复杂情况
//void Append(Node *node,int val){
//    Node *new = malloc(sizeof(*new));
//    new->val=val;
//    new->next=NULL;
//    if(IsEmpty(&list)){
//        list.head=new;
//    }
//    else{
//        while (node->next!=NULL){
//            node=node->next;
//        }
//        node->next=new;
//    }
//}
//
////插入至第一个，比较关键
////传入参数为ans的头结点
//void Insert(Node *node,Node *target){
//    Node *temp = malloc(sizeof(*temp));//此处需要malloc空间
//    temp->val=target->val;
//    if(IsEmpty(&ans)){
//        ans.head=temp;
//        temp->next=NULL;
//    }
//    else{
//        temp->next=ans.head;
//        ans.head=temp;
//    }
//}
//
//LinkedList *Reverse(LinkedList *list){
//    if(IsEmpty(list)){
//        return NULL;
//    }
//    else{
//        Node *temp=list->head;
//        do{
//            Insert(ans.head,temp);
//            temp=temp->next;
//        } while (temp!=NULL);
//    }
//    return &ans;
//}
//
//int main(){
//    init(&list);
//    init(&ans);
//    for(int i=1;i<=100;i++){
//        Append(list.head,i);
//    }
//    Reverse(&list);
//
//    return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int a,b;
    char map[50][100];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%c",&map[i][j]);
        }
        if(i!=4){
            //scanf("\n");
            getchar();
        }
    }
    for(int i=0;i<50;i++){
        for(int j=0;j<100;j++){
            if(map[i][j]=='#'){
                a=i;
                goto loop1;
            }
        }
    }

    loop1:   for(int i=49;i>=0;i--){
        for(int j=99;j>=0;j--){
            if(map[i][j]=='#'){
                b=i;
                goto loop2;
            }
        }
    }

    loop2: printf("%d %d\n",a,b);
    return 0;
}


//
// Created by 20663 on 2022/12/22.
//

#ifndef INC_2022_WU_CPL_CODING_LL_H
#define INC_2022_WU_CPL_CODING_LL_H

typedef struct node{
    int val;
    struct node *next;
}Node;

typedef struct ll{
    Node *head;
    Node  *tail;
}LinkedList;

void Init(LinkedList *List);
int IsEmpty(LinkedList *list);
void  Print(LinkedList *list);
void Append(LinkedList *list, int val );
int IsSingle(LinkedList *list);
void  Delete(LinkedList *list,Node *node);
int Get(LinkedList *list);
void Free(LinkedList *List);
Node *Search(LinkedList *list,int val);
void Insert(LinkedList *list,Node *node,int val);

#endif //INC_2022_WU_CPL_CODING_LL_H

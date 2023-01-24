//
// Created by 20663 on 2022/12/28.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cut[550]={0} ;
typedef struct node{
    char s[21];
    struct node *next1;
    struct  node *next2;
    struct node *left;
}Node ;

typedef struct tt{
    Node *first;
}Tree;

void Init(Tree *x){
    x->first=NULL;
}
void Initt(Node *y){
    y->next1=NULL;
    y->next2=NULL;
}
Node *Search(Node *p,char *ss){

    if(!strcmp(p->s,ss)){
        return p;
    }

    if(p!=NULL&&(strcmp(p->s,ss)!=0)){
        if(p->next1!=NULL) {
            Node *t=Search(p->next1, ss);
            if(t!=NULL){
                return t;
            }
        }
        if(p->next2!=NULL) {
            Node *t=Search(p->next2, ss);
            if(t!=NULL) {
                return t;
            }
        }

    }
    return NULL;

}
//Node *Search2(Node *p,char *ss){
//    if(p!=NULL) {
//        if (!strcmp(p->next1->s, ss) || !strcmp(p->next2->s, ss)) {
//            return p;
//        }
//    }
//    if(p!=NULL&&(strcmp(p->next1->s,ss)!=0)&&(strcmp(p->next2->s,ss)!=0)){
//        if(p->next1!=NULL) {
//            if(Search(p->next1, ss)!=NULL){
//                return Search2(p->next1, ss);
//            }
//        }
//        if(p->next2!=NULL) {
//            if(Search(p->next2, ss)!=NULL) {
//                return Search2(p->next2, ss);
//            }
//        }
//    }
//
//
//}


void Append(Tree *x,char *a,char *b){
    Node *tmp= malloc(sizeof (*tmp));
    Initt(tmp);
    sprintf(tmp->s,"%s", a);
    if(!strcmp(b,"~~~")){
        x->first=tmp;
        return;
    }else{
        Node *jiedian= Search(x->first,b);
        if(jiedian->next1==NULL){
            jiedian->next1=tmp;
            tmp->left=jiedian;
        }
        else{
            jiedian->next2=tmp;
            tmp->left=jiedian;
        }
    }
}

int count(Node *m,int e){
    if(m!=NULL) {
        if (m->next1 != NULL) {
            cut[e]++;
            count(m->next1,e);
        }
        if (m->next2 != NULL) {
            cut[e]++;
            count(m->next2,e);
        }
    }
    return cut[e];
}
int count2(Node *m){
    int sum=0;
    if(m!=NULL) {
        if (m->next1 != NULL) {
            sum++;
            count2(m->next1);
        }
        if (m->next2 != NULL) {
            sum++;
            count2(m->next2);
        }
    }
    return sum;
}



Tree tree;
int main(){
    Init(&tree);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        char s1[11];
        char s2[11];
        scanf("%s%s",s1,s2);
        Append(&tree,s1,s2);
    }
    int e=0;
    for(int i=1;i<=q;i++){
        char caozuo[10];
        char string[10];
        scanf("%s%s",caozuo,string);
        if(!strcmp(caozuo,"query")){
            Node *jiedian= Search(tree.first,string);
            printf("%d\n",count(jiedian,e)+1);
            e++;
        }
        else{
            Node *jiedian= Search(tree.first,string);
            Node *baga=jiedian->left;
            if(baga->next1!=NULL&&baga->next2!=NULL){
                if(baga->next1==jiedian){
                    baga->next1=NULL;
                } else{
                    baga->next2=NULL;
                }
            } else if(baga->next1==NULL){
                baga->next2=NULL;
            } else{
                baga->next1=NULL;
            }



        }
    }

    return 0;
}
//10 10
//utdg5kkk3 ~~~
//kejog utdg5kkk3
//qx2 kejog
//bawnnq kejog
//p0q2ykm utdg5kkk3
//wfw7gcd7 p0q2ykm
//j5ugv bawnnq
//fxhxh p0q2ykm
//t bawnnq
//saetrx6n6 wfw7gcd7
//query saetrx6n6
//query fxhxh
//remove qx2
//query utdg5kkk3
//remove fxhxh
//query utdg5kkk3
//remove wfw7gcd7
//query utdg5kkk3
//remove p0q2ykm
//query utdg5kkk3

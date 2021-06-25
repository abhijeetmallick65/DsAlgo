#ifndef Chains_h
#define Chains_h
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void SortedInsert(struct Node* *H,int x){
    struct Node *t,*q=NULL,*p=*H;

    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(*H==NULL)
        *H=t;
    else
    {
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==*H){
            t->next=*H;
            *H=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}
int Delete(struct Node *h,int x){
    int res = -1;
    struct Node *last = h;
    struct Node *q = NULL;
    while(last && last->data != x){
        q = last;
        last = last->next;
    }
    if(last){
        q->next = last->next;
        res = last->data;
        delete last; 
    }
    return res;
}
struct Node *Search(struct Node *p,int key){
    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;

}
#endif /* Chains_h */
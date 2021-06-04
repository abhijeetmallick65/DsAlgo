#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;

void create(int A[],int n){
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    head->prev = NULL;

    struct Node *last = head;

    for(int i = 1;i<n;i++){
        struct Node *temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
    head->prev = last;
    last->next = head;
}

int Length(struct Node *p){
    int count  = 0;
    do{
        p=p->next;
        count++;
    }while(p!=head);
    return count;
}
void Insert(struct Node *p,int pos,int value){
    if(pos <0|| pos>Length(head))return ;

    struct Node *temp = new Node;

    temp->data = value;
    temp->prev = temp->next = NULL;

    if(pos ==0){
        if(head == NULL){
            head = temp;
        }else{
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
            head = temp;
        }
    }else{
        for(int i = 0;i<pos-1;i++){
            p=p->next;
        }
        temp->next = p->next;
        temp->prev = p;
        p->next->prev = temp;
        p->next = temp;
    }
}
int Delete(struct Node *p,int index){
    if(index < 0 || index > Length(p))return -1;

    int x  = 0;
    struct Node *temp = head;
    if(index == 1){
        if(head->next == head){
            head = NULL;
        }else{
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
            x = p->data;
            delete p;
        }
    }else{
        for(int i = 1 ; i<index;i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next)p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}


void Display(struct Node *p){
    if(head == NULL)return;
    do{
        cout<<p->data<<endl;
        p=p->next;
    }while(p!=head);
}

int main(){
    int A[] = {1,2,3,4,5,6};
    create(A,6);
    Insert(head,0,11);
    Display(head);
    return 0;
}
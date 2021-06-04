#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// Node 
struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

// head pointer
struct Node *head;

// create
void create(int A[],int n){
    struct Node *temp,*last;
    // creating head
    // c
    // head = (struct Node *)malloc(sizeof(struct Node));
    // c++
    head = new Node;
    head->data = A[0];
    head->next = head->prev = NULL;
    last = head;
    // creating the remaining list
    for(int i = 1;i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }
}
// Length
int Length(struct Node *p){
    if(!head)return 0;
    int count = 0;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    return count;
}
// insert
void Insert(struct Node *p,int pos,int val){
    if(pos<0 || pos> Length(head))return;

    struct Node *temp;
    temp = new Node;
    temp->data = val;
    if(pos == 0){
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }else{
        for(int i = 0;i<pos-1;i++){
            p = p->next;
        }
        temp->next = p->next;
        temp->prev = p;
        if(p->next){
            p->next->prev = temp;
        }
        p->next = temp;
    }
}
// Delete
int Delete(struct Node *p,int index){
    if(index <= 0 || index > Length(head))return -1;
    int x = 0;
    if(index == 1){
        p = head;
        head = head->next;
        if(head != NULL)head->prev = NULL;
        x = p->data;
        delete p;
    }else{
        for(int i = 0;i<index-1;i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next)p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}
// reverse
void Reverse(struct Node *p){
    struct Node *temp;
    while(p!=NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p != NULL && p->next == NULL)
            head = p;
    }
}
// Display
void Display(struct Node *p){
    while(p!=NULL){
        cout << p->data << endl;
        p = p->next;
    }
}

int main(){
    int A[] = {1,2,3,4,5};
    create(A,5);
    Reverse(head);
    Display(head);
    return 0;
}
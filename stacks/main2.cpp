#include<stdio.h>
#include<iostream>
using namespace std;
// Node // Stack using linked list
struct Node{
    int data;
    struct Node *next;
}*head = NULL;
// isFull
// if heap is full
int isFull(struct Node *p){
    struct Node *t = new Node;
    if(t == NULL){
        delete t;
        return 1;
    }
    delete t;
    return 0;
}
// isEmpty
int isEmpty(struct Node *p){
    // if(head == NULL)return 1;
    // return 0;
    return p == NULL;
}
// stackTop
int stackTop(struct Node *p){
    return p->data;
}
// push
void push(struct Node *p,int val){
    if(isFull(p)){
        cout << " stack is full " << endl;
        return ;
    }
    struct Node *temp = new Node;
    temp->data = val;
    temp->next = head;
    head = temp;
}
// pop
int pop(struct Node *p){
    int x = -1;
    if(isEmpty(p)){
        cout << " the stack is empty " << endl;
        return x;
    }
    struct Node *temp = head;
    head  = head->next;
    x = temp->data;
    // delete temp;
    free(temp);
    return x;
}
// peek
int peek(struct Node *p,int position){
    for(int i = 1;p && i<position;i++){
        p = p->next;
    }
    if(p)return p->data;
    return -1;
}
// Display
void Display(struct Node *p){
    while(p!=NULL){
        cout << p->data << endl;
        p = p->next;
    }
}

// main
int main(){
    push(head,0);
    push(head,1);
    pop(head);
    peek(head,1);
    Display(head);
    return 0;
}
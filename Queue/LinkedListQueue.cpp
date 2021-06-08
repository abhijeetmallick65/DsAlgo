#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*front = NULL,*rear = NULL;

// isfull
int isFull(){
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    if(!q)return 1;
    delete q;
    return 0;
}
// isEmpty
int isEmpty(){
    if(front == NULL)return 1;
    return 0 ;
}
// enqueue
void enqueue(int val){
    if(isFull()){
        cout << "Queue is full";
        return;
    }
    struct Node *t = new Node;
    t->data = val;
    t->next = NULL;
    if(front == NULL){
        front = rear = t;
        return;
    }else{
        rear->next = t;
        rear = t;
    }
}
// dequeue
int dequeue(){
    int x = -1;
    struct Node *q = new Node;
    if(isEmpty()){
        cout << "Queue is empty";
        return x;
    }
    q = front;
    x = q->data;
    front = front->next;
    delete q;
    return x;
}
// Display
void Display(){
    struct Node *q = front;
    while(q!=NULL){
        cout << q->data << " ";
        q= q->next; 
    }
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    Display();
    return 0;
}
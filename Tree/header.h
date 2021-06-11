#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// formula  => Rear = (Rear + 1) % Queue.size
struct Node{
    struct Node *leftChild;
    int data;
    struct Node *rightChild;
};

// queue structure
struct Queue{
    int size;
    int front;
    int rear;
    struct Node * *Q;
};

// create 
void create(struct Queue *q , int size){
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));//(int *)malloc(sizeof(int))
}
// enqueue
void enqueue(struct Queue *q,struct Node *data){
    if((q->rear+1)%q->size == q->front){
        cout << "Queue is full";
        return;
    }

    q->rear = (q->rear+1)%q->size;
    q->Q[q->rear] = data;
}
// dequeue
struct Node * dequeue(struct Queue *q){
    struct Node *x = NULL;
    if(q->front == q->rear){
        cout << "Queue is empty";
        return x;
    }
    q->front = (q->front+1)%q->size;
    x = q->Q[q->front];
    return x;
}
// display
void Display(struct Queue q){
    int i = q.front+1;
    do{
        cout<<q.Q[i]<<" ";
        i = (i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
}

// isEmpty()
int isEmpty(struct Queue q){
    return q.front == q.rear;
}
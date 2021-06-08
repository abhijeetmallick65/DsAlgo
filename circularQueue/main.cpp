#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// formula  => Rear = (Rear + 1) % Queue.size

// queue structure
struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

// create 
void create(struct Queue *q , int size){
    q->size = size;
    q->front = q->rear = 0;
    q->arr = new int[size];
}
// enqueue
void enqueue(struct Queue *q,int data){
    if((q->rear+1)%q->size == q->front){
        cout << "Queue is full";
        return;
    }

    q->rear = (q->rear+1)%q->size;
    q->arr[q->rear] = data;
}
// dequeue
int dequeue(struct Queue *q){
    int x = -1;
    if(q->front == q->rear){
        cout << "Queue is empty";
        return x;
    }
    q->front = (q->front+1)%q->size;
    x = q->arr[q->front];
    return x;
}
// display
void Display(struct Queue q){
    int i = q.front+1;
    do{
        cout<<q.arr[i]<<" ";
        i = (i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
}

// main
int main(){
    struct Queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q,50);

    Display(q);
    return 0;
}
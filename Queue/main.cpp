#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// queue structure
struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};
// create
void create(struct Queue *q,int size){
    q->size = size;
    q->front = q->rear = -1;
    // q->arr = new int[q->size];
    q->arr = (int *)malloc(size*sizeof(int));
}
// is full
int isFull(struct Queue q){
    if(q.rear == q.size - 1)return 1;
    return 0;
}
// is empty
int isEmpty(struct Queue q){
    if(q.front == q.rear)return 1;
    return 0;
}
// enqueue
void enqueue(struct Queue *q,int val){
    if(isFull(/*dereferencing*/*q)){
        cout << "Queue is full.";
        return;
    }

    q->rear++;
    q->arr[q->rear] = val;
}
// dequeue
int dequeue(struct Queue *q){
    int x = -1;
    if(isEmpty(/*dereferencing*/*q))return x;
    q->front++;
    x = q->arr[q->front];
    return x;
}
// display
void Display(struct Queue q){
    for(int i = q.front+1;i<=q.rear;i++)
        cout << q.arr[i] << " ";
    cout << endl;
}
// main
int main(){
    struct Queue q;
    create(&q,5);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);
   
    Display(q);
    return 0;
}
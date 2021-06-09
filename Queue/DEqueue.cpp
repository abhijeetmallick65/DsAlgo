#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

void create(struct Queue * q,int  size){
    q->arr = new int[size];
    q->front = q->rear = -1;
    q->size = size;
}

void enqueueFront(struct Queue *q,int val){
    q->arr[q->front] = val;
    q->front--;
}
void enqueueRear(struct Queue *q,int val){
    q->rear++;
    q->arr[q->rear] = val;
}
void enqueue(struct Queue *q,int val){
    if(q->rear < q->size-1){
        enqueueRear(q,val);
    }else if(q->front>-1 && q->front < q->rear){
        enqueueFront(q,val);
    }else{
        cout<< "the queue is completely full";
    }
}
int dequeueFront(struct Queue *q){
    int x = 0;
    q->front++;
    x = q->arr[q->front];
    return x;
}
int dequeueRear(struct Queue *q){
    int x = 0;
    x = q->arr[q->rear];
    q->rear--;
    return x;
}
int dequeue(struct Queue *q){
    int x = -1;
    if(q->front == q->rear)return x;

    if(q->front < q->rear ){
        x = dequeueFront(q);
    }else if(q->rear > q->front){
        x = dequeueRear(q);
    }
    cout << x << " ";
    return x;

}

void Display(struct Queue q){
    cout << endl;
    for(int i = q.front+1;i<=q.rear;i++){
        cout << q.arr[i] << " ";
    }
}

int main(){
    struct Queue q;
    create(&q,5);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);
    dequeue(&q);
    dequeueRear(&q);
    enqueue(&q,5);
    enqueue(&q,6);


    Display(q);
    return 0;
}
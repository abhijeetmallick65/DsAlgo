#include<stdio.h>
#include<iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int size;
        int *arr;
    public:
        Queue(){front = rear = -1;size = 5; arr = new int[size];}
        Queue(int size){front = rear = -1;this->size = size; arr = new int[size];}
        void Enqueue(int data);
        int Dequeue();
        void Display();
};

void Queue :: Enqueue(int data){
    if(this->rear == this->size-1)return;
    this->rear++;
    this->arr[this->rear] = data;
}

int Queue :: Dequeue(){
    int x = -1;
    if(this->front == this->rear){
        cout<< "full";
    }
    this->front++;
    x = this->arr[this->front];
    return x;                                                                                                                                                                                                                                                                                           

}

void Queue :: Display(){
    for(int i= this->front+1;i<=this->rear;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    Queue q(4);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    cout << q.Dequeue() << endl;
    // q.Enqueue(2);
    q.Display();
    return 0;
}
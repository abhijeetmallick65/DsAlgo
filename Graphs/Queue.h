#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*front = NULL,*rear = NULL;


void enqueue(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;

    if(front  == NULL){
        front = rear = temp;
    }else{
        rear->next = temp;
        rear = rear->next;
    }
}

int dequeue(){
    int x = -1;
    if(front == NULL)return x;
    Node *temp = front;
    x = temp->data;
    front = front->next;
    delete temp;
    return x;
}

int isEmpty(){
    // if(front == NULL)return 1;
    // return 0;
    return front==NULL;
}
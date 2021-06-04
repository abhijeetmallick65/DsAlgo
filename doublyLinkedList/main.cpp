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
    int count = 0;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    return count;
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
    Display(head);
    cout << Length(head) << endl;
    return 0;
}
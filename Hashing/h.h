#ifndef header
#define header
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

struct Node{
    int data;
    Node* next;
};

void hashInsert(struct Node* *H,int val){
    struct Node *temp = new Node;
    temp->data = val;
    temp->next = NULL;

    if(*H == NULL){
        *H = temp;
    }else{
        struct Node *last = *H;
        struct Node *q = NULL;
        while(last && last->data < val){
            q = last;
            last = last->next;
        }
        if(last == *H){
            temp->next = *H;
            *H = temp; 
        }else{
            temp->next = q->next;
            q->next = temp;
        }
    }
}

int hashDelete(struct Node* *H,int val){
    int x = -1;
    struct Node *temp = *H; 
    struct Node *q = NULL; 

    while(temp && temp->data != val){
        q = temp;
        temp = temp->next;
    }
    if(temp != NULL){
        x = temp->data;
        q->next = temp->next;
        delete temp;
    }
    return x;
}

int hashSearch(struct Node* h,int val){
    int x = -1;
    struct Node *temp = h;
    while(temp && temp->data != val){
        temp = temp->next;
    }
    if(temp != NULL){
        x = temp->data;
    }
    return x;
}

#endif
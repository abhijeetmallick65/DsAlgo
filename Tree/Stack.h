#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include "header.h"
using namespace std;

// stack structure
struct Stack{
    int size;
    int top;
    struct Node **arr;
};
// create Stack
void createStack(struct Stack *stk,int size){
    stk->size = size;
    stk->top = -1;
    stk->arr = (struct Node **)malloc(stk->size*sizeof(struct Node *));
}
// isfullSatck
int isFullSatck(struct Stack s){
    // if(s.top == s.size-1)return 1;
    // return 0;
    return s.top == s.size-1;
}
// isEmpty
int isEmptyStack(struct Stack s){
    // if(s.top == -1)return 1;
    // return 0;
    return s.top == -1;
}
// push
void push(struct Stack *s,struct Node *val){
    // if full
    if(isFullSatck(*s)){
        cout<<"stack overflow"<<endl;
        return;
    }
    // else
    s->top++;
    s->arr[s->top] = val;
    return;
}
// pop
struct Node * pop(struct Stack *s){
    struct Node *x = NULL;
    if(isEmptyStack(*s)){
        return x;
    }

    x = s->arr[s->top];
    s->top--;
    return x;
}
// peek
struct Node * peek(struct Stack s,int positon){
    if(s.top - positon + 1 < 0){
        cout << "Invalid Position" << endl;
        return NULL;
    }
    return s.arr[s.top - positon + 1];
}
// stack top
struct Node * stackTop(struct Stack s){
    if(isEmptyStack(s))return NULL;
    return s.arr[s.top];
}
// display
void Display(struct Stack s){
    while(s.top >=0){
        cout<< s.arr[s.top]<<endl;
        s.top--;
    }
}


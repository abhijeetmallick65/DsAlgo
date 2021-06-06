#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// stack structure
struct Stack{
    int size;
    int top;
    int *arr;
};
// create Stack
struct Stack createStack(int size){
    struct Stack newStack;
    newStack.size = size;
    newStack.top = -1;
    newStack.arr = new int[newStack.size];
    return newStack;
}
// isfull
int isFull(struct Stack s){
    // if(s.top == s.size-1)return 1;
    // return 0;
    return s.top == s.size-1;
}
// isEmpty
int isEmpty(struct Stack s){
    // if(s.top == -1)return 1;
    // return 0;
    return s.top == -1;
}
// push
void push(struct Stack *s,int val){
    // if full
    if(isFull(*s)){
        cout<<"stack overflow"<<endl;
        return;
    }
    // else
    s->top++;
    s->arr[s->top] = val;
    return;
}
// pop
int pop(struct Stack *s){
    int x = -1;
    if(isEmpty(*s)){
        return x;
    }

    x = s->arr[s->top];
    s->top--;
    return x;
}
// peek
int peek(struct Stack s,int positon){
    if(s.top - positon + 1 < 0){
        cout << "Invalid Position" << endl;
        return -1;
    }
    return s.arr[s.top - positon + 1];
}
// stack top
int stackTop(struct Stack s){
    if(isEmpty(s))return -1;
    return s.arr[s.top];
}
// display
void Display(struct Stack s){
    while(s.top >=0){
        cout<< s.arr[s.top]<<endl;
        s.top--;
    }
}
int main(){
    struct Stack st = createStack(5);
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);
    push(&st,0);
    Display(st);
    return 0;
}


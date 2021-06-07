#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top = NULL,*temp = NULL;



void push(int a){
    struct Node *n = new Node;
    n->data = a;
    n->next = top;
    top = n;
}
int pop(){
    struct Node *p = top;
    int x = p->data;
    top = top->next;
    delete p;
    return x;
}
// struct Node{
//     char data;
//     struct Node *next;
// }*top = NULL,*temp = NULL;



// void push(char a){
//     struct Node *n = new Node;
//     n->data = a;
//     n->next = top;
//     top = n;
// }
// char pop(){
//     struct Node *p = top;
//     char x = p->data;
//     top = top->next;
//     delete p;
//     return x;
// }

// intfix to postfix
// is operand
int isOperand(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/')return 0;
    return 1;
}
int pre(char a){
    if(a == '+' || a == '-')return 1;
    if(a == '*' || a == '/')return 2;
    return 0;
}
char * infixTopostfix(char *infix){
    int len = strlen(infix);
    char *res = new char[len];
    int i = 0,j=0;
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            res[j++] = infix[i++];
        }else{
            if(top == NULL || (pre(top->data) < pre(infix[i]))){
                push(infix[i++]);
            }else{
                res[j++] = pop();
            }
        }
    }
    while(top!=NULL){
        res[j++] = pop();
    }
    res[j] = '\0';
    return res;
}

int evaluate(char *a){
    int i = 0,r = 0;
    for(int i = 0;i< strlen(a);i++){
        if(isOperand(a[i])){
            push(a[i] - '0');
        }else{
            int x2 = pop();
            int x1 = pop();
            switch (a[i])
            {
            case '+' :r = x1 + x2;break;
            case '*' :r = x1 * x2;break;
            case '-' :r = x1 - x2;break;
            case '/' :r = x1 / x2;break;
            }
            push(r);
        }
    }
    return r;
}
int main(){
    /*
    char a[] = "a+b*c-d/e";
    push('#');
    char *p = infixTopostfix(a);
    printf("%s ",p);
    */
    char a[] =  "234*+82/-";
    cout << evaluate(a);
    return 0;

}
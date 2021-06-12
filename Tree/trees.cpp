
#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

struct Node *root = NULL;
struct Queue q;
int x = 0;

// create tree
void createTree(){
    struct Node *p,*t;
    create(&q,100);
    cout << "enter root data : ";
    cin >> x;
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->leftChild = root->rightChild = NULL;
    enqueue(&q,root);

    while(!isEmpty(q)){
        t = dequeue(&q);
        cout<<"enter left child of " << t->data << " : ";
        cin>>x;
        if(x!=-1){
            p = (struct Node *)malloc(sizeof(struct Node));
            p->data = x;
            p->leftChild = p->rightChild = NULL;
            t->leftChild = p;
            enqueue(&q,p);
        }
        cout<<"enter right child of " << t->data << " : ";
        cin>>x;
        if(x!=-1){
            p = (struct Node *)malloc(sizeof(struct Node));
            p->data = x;
            p->leftChild = p->rightChild = NULL;
            t->rightChild = p;
            enqueue(&q,p);
        }
    }
}

// Recursive Traversals
// preorder : root , left , right
void Preorder(struct Node *p)
{
 if(p)
 {
 printf("%d ",p->data);
 Preorder(p->leftChild);
 Preorder(p->rightChild);
 }
}
// inorder : left root right 
void Inorder(struct Node *p){
    if(!p) return;
    Inorder(p->leftChild);
    cout<<p->data<<" ";
    Inorder(p->rightChild);
}
// postorder : left right root
void postOrder(struct Node *p){
    if(!p)return;
    postOrder(p->leftChild);
    postOrder(p->rightChild);
    cout << p->data << " ";
}

// Iterative Traversals

// preorder
void Ipreorder(struct Node *p){
    struct Stack stk;
    createStack(&stk,100);
    while(!isEmptyStack(stk) || p){
        if(p){
            cout << p->data << " ";
            push(&stk,p);
            p = p->leftChild;
        }else{
            p = pop(&stk);
            p = p->rightChild;
        }
    }
}
// inorder
void Iinorder(struct Node *p){
    struct Stack stk;
    createStack(&stk,100);
    while(!isEmptyStack(stk)||p){
        if(p){
            push(&stk,p);
            p = p->leftChild;
        }else{
            p = pop(&stk);
            cout << p->data << " ";
            p = p->rightChild;
        }
    }
}

// postorder
void Ipostorder(struct Node *p){
    struct Stack stk1;
    struct Stack stk2;
    createStack(&stk1,100);
    createStack(&stk2,100);
    push(&stk1,p);
   while (!isEmptyStack(stk1)) {
        // Pop an item from &stk1 and push it to &stk2
        p = pop(&stk1);
        push(&stk2,p);
  
        // Push left and right children of removed item to &stk1
        if (p->leftChild)
            push(&stk1, p->leftChild);
        if (p->rightChild)
            push(&stk1, p->rightChild);
    }
  
    // Print all elements of second stack
    while (!isEmptyStack(stk2)) {
        p = pop(&stk2);
        printf("%d ", p->data);
    }
}

void levelOrder(struct Node *p){
    struct Queue q;
    create(&q,100);
    enqueue(&q,p);
    while(!isEmpty(q)){
        p = dequeue(&q);
        if(p)cout << p->data << " ";
        if(p->leftChild){
            enqueue(&q,p->leftChild);
        }
        if(p->rightChild){
            enqueue(&q,p->rightChild);
        }
    }
} 
// main
int main(){
    createTree();
    cout << endl;
    // levelOrder(root);
    // Preorder(root);
    // Inorder(root);
    cout << endl;
    // Ipreorder(root);
    // Iinorder(root);
    Ipostorder(root);
    cout << endl;
    // postOrder(root);
    return 0;
}
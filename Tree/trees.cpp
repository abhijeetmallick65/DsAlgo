
#include<stdio.h>
#include<stdlib.h>
#include "header.h"

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
// main
int main(){
    createTree();
    cout << endl;
    Preorder(root);
    cout << endl;
    Inorder(root);
    cout << endl;
    postOrder(root);
    return 0;
}
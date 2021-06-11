
#include<stdio.h>
#include<stdlib.h>
#include "header.h"

struct Node *root = NULL;
struct Queue q;

// treecreate
void treeCreate(){
    struct Node *p,*t;
    int x;
    create(&q,100);

    cout << " enter the root value " << endl;
    scanf("%d",&x);
    root= (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->leftChild = root->rightChild = NULL;
    enqueue(&q,root);

    while(!isEmpty(q)){
        p = dequeue(&q);
        cout << "Enter the leftchild " << p->data <<endl;
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->leftChild = t->rightChild = NULL;
            p->leftChild = t;
            enqueue(&q,t);
        }
        cout << "Enter the rightchild "<< p->data <<endl;
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->leftChild = t->rightChild = NULL;
            p->rightChild = t;
            enqueue(&q,t);
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
    treeCreate();
    cout << endl;
    Preorder(root);
    cout << endl;
    Inorder(root);
    cout << endl;
    postOrder(root);
    return 0;
}
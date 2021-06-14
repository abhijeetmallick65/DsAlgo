#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//TREE NODE
struct Node{
    struct Node *leftchild;
    int data;
    struct Node *rightchild;
}*root = NULL;

//ITERATIVE INSERT
void insert(int data){
    struct Node *q = NULL;

    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->leftchild = p->rightchild = NULL;

    if(root == NULL){
        root = p;
        return;
    }  
    struct Node *temp = root;
    while(temp != NULL){
        q = temp;
        if(temp->data == data)return;
        if(temp->data < data)temp=temp->rightchild;
        else temp=temp->leftchild;
    } 

    if(q->data < data)q->rightchild = p;
    else q->leftchild = p;
}

//ITERATIVE SEARCH
struct Node * search(int data){
    if(root == NULL)return NULL;
    struct Node *temp = root;

    while(temp != NULL){
        if(temp->data == data)return temp;
        else if(temp->data < data)temp = temp->rightchild;
        else temp = temp->leftchild;
    }
    return NULL;

}

//INORDER TRAVERSAL
void inorder(struct Node *p){
    if(p!=NULL){
        inorder(p->leftchild);
        cout << p->data << " ";
        inorder(p->rightchild);
    }
}

//Main
int main(){
      // Insert
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);
 
    inorder(root);
    return 0;
}
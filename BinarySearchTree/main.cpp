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

//Recursive insert
struct Node * Rinsert(struct Node *p,int data){
    if(p == NULL){
        p = new Node;
        p->data = data;
        p->leftchild = p->rightchild = NULL;
        return p;
    }else if(p->data < data){
        p->rightchild = Rinsert(p->rightchild,data);
    }else{
        p->leftchild = Rinsert(p->leftchild,data);
    }
    return p;
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

//Recursive Search
struct Node * Rsearch(struct Node *p,int data){
    if(p == NULL || p->data == data)return p;
    else if(p->data < data){
        return Rsearch(p->rightchild,data);
    }else{
        return Rsearch(p->leftchild,data);
    }
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
      // RInsert
    root = Rinsert(root,10);
    Rinsert(root,5);
    Rinsert(root,20);
    Rinsert(root,8);
    Rinsert(root,30);
    //   // Insert
    // insert(10);
    // insert(5);
    // insert(20);
    // insert(8);
    // insert(30);
    struct Node *temp = Rsearch(root,5);
    cout<< temp->data<< endl;
    inorder(root);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// Node
struct Node{
    int data;
    Node *next;
};
struct Node *head;

// create
void create(int A[],int n){
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;
    struct Node *last,*temp;
    last = head;

    for(int i = 1;i<n;i++){
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}
// Display
// iterative
void Display(struct Node *p){
    do{
        cout << p->data << endl;
        p = p->next;
    }while(p!=head);
}
// recursive
void Rdisplay(struct Node *p){
    static int flag = 0;
    if(p!=head || flag == 0){
        flag = 1;
        cout<<p->data<<endl;
        Rdisplay(p->next);
    }
    // flag is static so only 1 copy created, and remains same in all function call, so we need to change it to 0 otherwise it will remain 1 , and function wont run if we call it again after calling once
    flag = 0;
}

// length
int Length(struct Node *p){
    int flag = 0,count = 0;
    if(!head)return 0;
    while (p!=head || flag == 0)    
    {
        /* code */
        flag = 1;
        p=p->next;
        count++;
    }
    return count;
}

// insert
void Insert(struct Node *p,int position,int value){
    if(position<0||position>Length(head))return;

    struct Node *t = new Node;
    t->data = value;
    
    struct Node *last;

    // if(position == 0)
    if(position == 0){
        // if (!head)
        if(head == NULL){
            head = t;
            head->next = head;
        }
        // if(head)
        else{

            last = head;
            do{
                last = last->next;
            }while(last->next != head);
            last->next = t;
            t->next = head;
            head = t;
        }
    }
    // if(position != 0)
    else{
        last = head;
        for(int i = 1;i<position;i++){
            last=last->next;
        }
        t->next = last->next;
        last->next = t;
    }
}
// delete
int Delete(struct Node *p,int index){
    int x = 0;
    // valid position check 
    if(index<=0 || index > Length(head))return -1;
    // index == 0
    if(index == 1){
        while (p->next !=head){
            p = p->next;
        }
        x = head->data;    
        // if p still at head : means that head is the only node in the linked list
        if(p == head){
            delete head;
            head = NULL;
        }else{
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }else{
        for(int i = 0; i<index-2;i++){
            p = p->next;
        }
        struct Node *q = p->next;
        x = q->data;
        p->next = q->next;
        delete q;
    }
    return x;
}
int main(){
    int a[] = {1,2,3,4,5};
    create(a,5);
    Delete(head,5);
    Rdisplay(head);
    return 0;
}
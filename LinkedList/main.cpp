#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *head;

void create(int A[],int n){


    struct Node *temp,*last;
    
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    // we want last as a pointer to point it to some nodes, we don't requires memory structure for last, so new is not used with last
    last = head;
    int i = 1;


    while (i<n)
    {
        /* code */
        // temp = new Node;


        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
        i++;
    }
}
void Display(struct Node *p){
    // struct Node *p = head;
    // p->data = 99;
    while(p){
        cout << p->data << endl;
        // cout << p->next << " " << head->next << endl;

        // watch carefully : we assign variable "p" with p->next, we DO NOT assign p->next with P and that's why head remains same as its not being changed and its next is not being changed, whats changing is variable p;
        p = p->next;
    }
    // cout << head->data ;
}

// Linked list operations
int count(){
    struct Node *p = head;
    int count = 0;
    while(p != 0){
        count++;
        p = p->next;
    }
    return count;
}
int Rcount(struct Node *p){
    if(p == 0)return 0;
    return Rcount(p->next) + 1;
}

// sum
int sum(struct Node *p){
    int s = 0;
    while(p){
        s+=p->data;
        p = p->next;
    }
    return s;
}
int Rsum(struct Node *p){
    if(!p)return 0;
    return Rsum(p->next) + p->data;
}
// max
int max(struct Node *p){
    int max  = INT32_MIN;
    while (p)
    {
        /* code */
        if(p->data > max){
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
int Rmax(struct Node *p){
    int x = 0;
    if(!p){
        return INT32_MIN;
    }
    x = Rmax(p->next);
    if(x>p->data){
        return x;
    }else{
        return p->data;
    }
}
int main(){
    int A[] ={3,4,5,6,7};
    create(A,5);
    Display(head);
    cout << max(head) << endl ;
    cout << Rmax(head) ;
    
    return 0;
}
/*
struct check {
    int a ;
    struct check *n;
};
struct check *ab;
struct check *bs;
ab = (struct check *)malloc(sizeof(struct check));
    bs = new check;
    bs->a = 98;
    struct check *p = ab;
    ab->a = 56;
    ab->n = bs;
    cout << p->a << " " << p->n << endl;;
    p = ab->n;
    cout << ab->a << " " << ab->n << endl;;
    cout << bs << endl;
    cout << p->a << " " << p->n << endl;;

*/
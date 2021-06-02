#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<set>
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
        // new node
        temp = (struct Node *)malloc(sizeof(struct Node));
        // add data
        temp->data = A[i];
        // next is null
        temp->next = NULL;
        // connect to previous
        last->next = temp;
        // move to latest *last*
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
void Rdisplay(struct Node *p){
    if(p!=NULL){
        // Rdisplay(p->next);
        cout << p->data << endl;
        Rdisplay(p->next);
    }
}
// Linked list operations
int count(struct Node *p ){
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
// 1/6/21
struct Node * Search(struct Node *p,int key){
    while(p != NULL){
        if(p->data == key)return p;
        p = p->next;
    }
    return NULL;
}
struct Node * Rsearch(struct Node *p,int key){
    if(p == NULL)return NULL;
    if(p->data == key)return p;
    return Rsearch(p->next,key);
}
struct Node * moveToHead(struct Node *p,int key){
    struct Node *q = NULL;
    while(p){
        if(p->data == key){
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p= p->next;
    }
    return NULL;
}
// insert 
void Insert(struct Node *p,int index,int val){
    struct Node *t = NULL;
    // insert at start
    if(index == 0){
        t = new Node;
        t->data = val;
        t->next = head;
        head = t;
    }else if(index>0){
        // any other index
        for(int i = 0;i< index-1 && p;i++){
            p = p->next;
        }
        if(p){
            t= new Node;
            t->data = val;
            t->next = p->next;
            p->next = t;
        }
    }
}
void insertLast(int value){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last;
    t->data = value;
    t->next = NULL;
    if(head == NULL){
        head = last  = t;
    }else{
        last = head;
        while(last->next){
            last = last->next;
        }
        last->next = t;
        last = t;
    }
}
void sortedInsert(struct Node *p,int val){
    // creating node to be inserted
    struct Node *t = new Node;
    struct Node *q = NULL;
    
    t->data = val;
    t->next = NULL;

    // if(head == null) / t is the first node
    if(head == NULL){
        head = t;
    }else{
        while(p && p->data < val){
            q = p;
            p = p->next;
        }
        // if val < head->data
        if(p == head){
            t->next = head;
            head = t;
        }else{
            // val > head->data
            t->next = q->next;
            q->next = t;
        }
    }
}
// 2/6/21
int Delete(struct Node *p,int index){
    if(index < 1 || index > count(p))return -1;
    struct Node *q = NULL;
    int x = -1;
    if(index == 1){
        p = head;
        head = head->next;
        x = p->data;
        delete p;
    }else{
        for(int i = 0; i<index-1;i++){
            q = p;
            p= p->next;
        }
        x = p->data;
        q->next = p->next;
        delete p;
    }
    return x;
}
// check sorted
bool checkSorted(struct Node *p){
    int x  = p->data;
    p = p->next;
    while(p!=NULL){
        if(p->data < x){
            return false;
        }
        x = p->data;
        p=p->next;
    }
    return true;
}
// delete duplicates
// sorted
void sortedDuplicateDelete(struct Node *p){
    struct Node *q = p;
    p = p->next;
    while(p!=NULL){
        if(p->data == q->data){
            q->next = p->next;
            delete p;
            p = q->next;
        }else{
            q = p;
            p = p->next;
        }
    }
}
// unsorted 
void unsortedDuplicateDelete(struct Node *p){
    set<int, greater<int> > s1;
    struct Node *q= NULL;
    while(p!=NULL){
        if(s1.count(p->data) == 1){
            q->next = p->next;
            delete p;
            p = q->next;
        }else{
            s1.insert(p->data);
            q = p;
            p = p->next;
        }
    }
}
// reversing linked list
// changing values /*DONT USE THIS METHOD : REASON -> */ : we DO NOT USE THIS METHOD BECAUSE WE DON'T WANT MOVEMENT OF DATA IN A LINKED LIST, AS A LOT OF DATA MAY BE REQUIRED TO BE MOVED/CHANGED.
void reverseChangeValues(struct Node *p){
    // int size = count(p);
    // int A[size];
    int *A;
    A = (int *)malloc(count(p) * sizeof(int));
    int i = 0;
    while (p!=NULL)
    {
        A[i] = p->data;
        p=p->next;
        i++;
    }
    p = head;
    i--;
    while (p!=NULL)
    {
        p->data = A[i];
        i--;
        p=p->next;
    }
}
// reversing linked list using sliding pointers:
void reverse(struct Node *p){
    struct Node *q = NULL,*r = NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}
void Rreverse(struct Node *q,struct Node *p){
    if(p){
        Rreverse(p,p->next);
        p->next = q;
    }else{
        head = q;
    }
}
int main(){
    int A[] ={3,4,5,3,7,5,8};
    create(A,7);
    // sortedDuplicateDelete(head);
    unsortedDuplicateDelete(head);
    Rreverse(NULL,head);
    Rdisplay(head);
    return 0;
}
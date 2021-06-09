#include <stdio.h>
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL; 
    }
};

class LinkedList{
    private:
    Node *head;
    public:
    LinkedList(){
        head = NULL;
    }
    LinkedList(int a[],int n){
        head = new Node(a[0]);
        Node *last = head;
        for(int i = 1;i<n;i++){
            Node *temp = new Node(a[i]);
            last->next = temp;
            last = temp;
        }
    }
    int remove(int x){
        if(!this->head)return -1;
        int data;
        if(x == 1){
            Node *temp = head;
            head = head->next;
            data = temp->data;
            delete temp;
        }else{
            Node *temp = head;
            for(int i = 0;i<x-2;i++)
                temp=temp->next;
            Node *req = temp->next;
            temp->next = req->next ? req->next : NULL;
            data = req->data;
            delete req;
        }
        return x;
    }
    void Display(){
        Node *p = head;
        while(p!=NULL){
            cout << p->data << " ";
            p=p->next;
        }
    }
};

int main(){
    int a[] = {1,2,3,4,5};
    LinkedList ll(a,5);
    ll.remove(8);
    ll.Display();
    return 0;
}
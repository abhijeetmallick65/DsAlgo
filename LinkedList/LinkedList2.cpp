#include <stdio.h>
#include<iostream>
using namespace std;

class Node{
    private:
    int data;
    Node *next;
};

class LinkedList{
    private:
    Node *head;

    public:
    LinkedList(){
        head = NULL;
    }
    LinkedList(int a[],int n);
    ~LinkedList();

    void Display();
    void Insert(int data,int x);
    int Delete(int index);
    int Length();
};
int main(){
    return 0;
}
#include <stdio.h>
#include<iostream>
#include<stdlib.h>
#include "header.h"
using namespace std;

int HashFunction(int key){
    return key%10;
}
void Insert(struct Node* *h,int key){
    int idx = HashFunction(key);
    SortedInsert(&h[idx],key);
}
int main(){
    // hash table
    struct Node* Hash[10];
    // initialize Hash table
    for(int i = 0;i<10;i++)Hash[i] = nullptr;

    Insert(Hash,22);
    Insert(Hash,42);
    Insert(Hash,52);
    Insert(Hash,62);
    Insert(Hash,11);

    struct Node *temp = Search(Hash[HashFunction(22)],22);

    cout << temp->data << endl;
    cout << Delete(Hash[HashFunction(52)],52) << endl;
    temp = Search(Hash[HashFunction(52)],52);
    cout << temp->data << endl;

    return 0;
}
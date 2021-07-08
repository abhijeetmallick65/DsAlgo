#include<iostream>
using namespace std;

#define size 10
int hash1(int key){
    return key % size;
}

int hash2(int key){
    return 7 - (key % 7);
}

int combine(int h[],int key){
    int i = 0;
    while(h[(hash1(key) + i * hash2(key))%size] != 0)i++;
    return (hash1(key) + i * hash2(key))%size;
}
void Insert(int h[],int key){
    int idx = hash1(key);
    if(h[idx] != 0){
        idx = combine(h,key);
    }
    cout << idx << " " << key << endl;
    h[idx] = key;
}

int search(int h[],int key){
    int i = 0;
    while(h[(hash1(key) + i * hash2(key))%size] != key)i++;
    return (hash1(key) + i * hash2(key))%size;
}
int main(){
    int hashTable[size] = {0};
    Insert(hashTable,12);
    Insert(hashTable,25);
    Insert(hashTable,35);
    Insert(hashTable,26);
    for(int i : hashTable){
        cout << i << " " ;
    }
    printf("\n");
    cout << search(hashTable,35) << " ";
    return 0;
}
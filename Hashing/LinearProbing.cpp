#include<iostream>
using namespace std;

#define size 10

int hashf(int key){
    return key % size;
}

int prob(int hashTable[],int key){
    int idx = hashf(key);
    int i = 0;
    while(hashTable[(idx + i) % size] != 0){
        i++;
    }
    return (idx + i)%size;
}

int Search(int hashTable[] ,int key){
    int i = 0;
    while(hashTable[(key + i) % size] != key){
        if(hashTable[(key + i) % size] == 0)return -1;
        i++;
    }
    return (key + i)%size;
}

void Insert(int hashTable[],int n){
    int index = hashf(n);
    
    if(hashTable[index] != 0){
        index = prob(hashTable,n);
    }

    hashTable[index] = n;
}

int main(){
    int hashTable[size] = {0};
    Insert(hashTable,12);
    Insert(hashTable,25);
    Insert(hashTable,35);
    Insert(hashTable,26);
    cout << Search(hashTable,26) << endl;
    return 0;
}
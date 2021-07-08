#include<iostream>
using namespace std;
#define size 10

int hashFunction(int key){
    return key %10;
}

void Insert(int arr[],int key){
    int idx = hashFunction(key);
    int i = 0;
    if(arr[idx] != 0){
        while(arr[idx + i*i %size] != 0)i++;
    }
    arr[(idx + (i*i)) %size] = key;
}

int search(int arr[],int key){
    int i = 0;
    int idx = hashFunction(key);
    while(arr[idx + i*i % size] != key)i++;
    if(arr[(i*i+idx) %size] == 0)return -1;
    return idx + i*i % size;
}

int main(){
    int h[size] = {0};
    Insert(h,23);
    Insert(h,43);
    Insert(h,13);
    Insert(h,27);
    for(int i : h)cout << i << endl;
    cout << "Key found at : " << search(h,13) << endl;

    return 0;
}
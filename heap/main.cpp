#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void Insert(int heap[],int n){
    int i = n,temp = heap[i];

    while(i > 1 && temp > heap[i/2]){
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = temp;
}

int Delete(int heap[],int n){
    int x = heap[1];
    heap[1] = heap[n];
    int i = 1,j = 2*i;
    while(j<n-1){
        if(j< n-1 && heap[j] < heap[j+1]){
            j++;
        }
        if(heap[i] < heap[j]){
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
            j = 2*i;
        }else{
            break;
        }
    }
    heap[n] = x;
    return x;
}
int main(){
    int Heap[] = {0,10,20,30,40,50,60,70};

    for(int i=2;i<=7;i++){
        Insert(Heap,i);
    }
    for(int i=7;i>=2;i--){
        Delete(Heap,i);
    }

    for(int i = 1;i<=7;i++){
        cout << "Element : " << Heap[i] << endl;
    }


    return 0;
}
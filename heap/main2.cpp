#include<stdio.h>
#include<iostream>
using namespace std;

void insert(int heap[],int n){
    int i = n;
    int temp = heap[n];
    while(i> 1 && temp > heap[i/2]){
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = temp;
}
int Delete(int heap[],int n){
    int i = 1,j = i*2;
    int x = heap[1];
    heap[1] = heap[n];

    while(j<n-1){
        if(j<n-1 && heap[j] < heap[j+1])j++;
        //if ele > child : break
        if(heap[i] > heap[j])break;
        else{
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
            j = 2*i;
        }
    }
    heap[n] = x;
    return x;
}

int main(){
    int Heap[8] = {0,10,20,60,30,40,50,70};
    //create heap
    for(int i = 2;i < 8;i++){
        insert(Heap,i);
    }
    //heap sort
    for(int i = 7;i>=2;i--){
        Delete(Heap,i);
    }

    //Display heap
    for(int i = 1;i<8;i++){
        cout << "Element is : " << Heap[i] << endl;
    }
    return 0;
}
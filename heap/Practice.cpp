#include<stdio.h>
#include<iostream>
using namespace std;

void insertMax(int heap[],int n){
    int i = n,temp = heap[n];
    while(i>1 && temp > heap[i/2]){
        heap[i] = heap[i/2];
         i = i/2;
    }
    heap[i] = temp;
}

int Deletemax(int heap[],int n){
    int res = heap[1];
    heap[1] = heap[n];
    int i = 1,j=2*i;
    while(j<n-1){
        if(j < n-1 && heap[j] < heap[j+1])j++;
        if(heap[i] > heap[j])break;
        else{
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] =  temp;
            i = j;
            j = 2*i;
        }
    }
    heap[n] = res;
    return res;

}

void insertMin(int heap[],int n){
    int i = n,temp = heap[n];
    while(i > 1 && temp < heap[i/2]){
        heap[i] = heap[i/2];
        i = i/2;
    }
    heap[i] = temp;

}

int Deletemin(int heap[],int n){
    int res = heap[1];
    heap[1] = heap[n];
    int i = 1,j = 2*i;

    while(j<n-1){
        if(j < n-1 && heap[j] > heap[j+1])j++;
        if(heap[i] < heap[j])break;
        else{
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
            j = i*2;
        }
    }
    heap[n] = res;
    return res;
}

int main(){
    int heap[] = {0,50,30,10,70,40,20,80,60,90};
    int n = 10;
    
    //max heap
    //insert
    for(int i = 1;i< n;i++){
        insertMax(heap,i);
    }
    //delete
    for(int i = 9;i>=2 ;i--){
        Deletemax(heap,i);
    }

    //minheap
    //insert
    // for(int i = 2;i < n;i++){
    //     insertMin(heap,i);
    // }
   
    // //delete
    // for(int i = 9;i>=2;i--){
    //     Deletemin(heap,i);
    // }

    //display
        
     for(int j = 1;j < n;j++){
        cout <<  heap[j] << " ";
     }
     cout<< endl;    
    return 0;
}
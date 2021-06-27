#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

void Insert(Node **buckets,int data){
    Node* temp = new Node(data);
    if(buckets[data] == nullptr){
        buckets[data] = temp;
    }else{
        Node* last = buckets[data];
        while(last->next != nullptr){
            last = last->next;
        }
        last->next = temp;
        last = temp;
    }
}

int Delete(Node** p,int idx){
    int x = p[idx]->data;
    Node* temp = p[idx];
    p[idx] = p[idx]->next;
    delete temp;
    return x;
}

void radixInsert(Node** buckets,int idx ,int data){
    Node* temp = new Node(data);
    if(buckets[idx] == nullptr){
        buckets[idx] = temp;
    }else{
        Node* last = buckets[idx];
        while(last->next != nullptr){
            last = last->next;
        }
        last->next = temp;
        last = temp;
    }
}

int radixDelete(Node** p,int idx){
    int x = p[idx]->data;
    Node* temp = p[idx];
    p[idx] = p[idx]->next;
    delete temp;
    return x;
}

class Sorting{
    int arr[10] = {30,20,70,80,10,40,90,50,60,100};
    int n = 10;
    //swap
    void swap(int *x,int *y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    //findMax
    int findMax(){
        int max  = INT32_MIN;
        for(int i = 0;i<n;i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
        return max;
    }
    //digitcount
    int DigitCount(int num){
        int count = 0;
        while(num > 0){
            count++;
            num/=10;
        }
        return count;
    }
    public:
    //comparison based sorting
    //bubble sort
    void bubbleSort(){
        for(int i = 0;i<n-1;i++){
            int flag = 0;
            for(int j = 0;j<n-1;j++){
                if(arr[j]>arr[j+1]){
                    flag = 1;
                    swap(&arr[j],&arr[j+1]);
                }
            }
            if(flag == 0)break;
        }
    }
    //insertion sort
    void InsertionSort(){
        for(int i = 1;i<n;i++){
            int temp = arr[i],j = i-1;
            while(j>=0 && arr[j] > temp){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
    }
    //selection sort
    void SelectionSort(){
        int k= 0 , j = 0;
        for(int i = 0;i<n-1;i++){
            for(k = j = i;j<n;j++){
                if(arr[j]< arr[k]){
                    k = j;
                }
            }
            swap(&arr[i],&arr[k]);
        }
    }

    //quick sort

    //quick pivotPosition
    int pivotPosition(int a[],int low,int high){
        int pivot = a[low];
        int i = low,j = high;
        
        do{
            do{i++;} while (a[i]<=pivot);
            do{j--;} while (a[j] > pivot);
            if(i<j){
                swap(&a[i],&a[j]);
            }
        }while(i<j);

        swap(&a[low],&a[j]);
        return j;
    }
    //quick sort
    void quickSort(int low,int high){
        if(low<high){
            int j =  pivotPosition(arr,low,high);
            quickSort(low,j);
            quickSort(j+1,high);
        }
    }

    //merge sort
    void Merge(){
    }
    void IterativeMergeSort(){
    }
    void RecursiveMergeSort(){
    }

    //index based sorting
    //count sort
    void countSort(){
        int max = findMax();
        int *count = new int[max+1];
        for(int i = 0;i<=max;i++){
            count[i] = 0;
        }
        for(int i = 0;i<n;i++){
            count[arr[i]]++;
        }
        int i = 0,j = 0;
        while(i<n){
            if(count[j] > 0){
                arr[i++]= j;
                count[j]--;
            }else{
                j++;
            }
        }
    }
    //bucket sort
    void BucketSort(){
        int max = findMax();
        Node **buckets = new Node*[max+1];

        for(int i = 0 ;i<=max;i++){
            buckets[i] = nullptr;
        }

        for(int i = 0;i<n;i++){
            Insert(buckets,arr[i]);
        }

        int i = 0,j = 0;

        while(i<n){
            if(buckets[j] != nullptr){
                arr[i++] = Delete(buckets,j);
            }else{
                j++;
            }
        }
    }
    //radix sort
    void RadixSort(){
        int max = findMax();
        Node** bin = new Node*[10];

        for(int i = 0;i<10;i++){
            bin[i] = nullptr;
        }

        int digit = DigitCount(max);
        int divisor = 1;

        while(digit > 0){
            for(int i = 0;i<n;i++){
                radixInsert(bin,(arr[i]/divisor)%10,arr[i]);
            }

            int  i =0,j = 0;
            while(i<n){
                if(bin[j] != nullptr){
                    arr[i++] = radixDelete(bin,j);
                }else{
                    j++;
                }
            }

            digit--;
            divisor *=10;
        }
    }
    //shell sort
    void ShellSort(){
        for(int gap = n/2;gap>=1;gap/=2){
            for(int i = gap;i<n;i+=gap){
                int temp = arr[i];
                int j = i-gap;
                while(j>=0 && arr[j] > temp){
                    arr[j+gap] = arr[j];
                    j -= gap;
                }
                arr[j+gap] = temp;
            }
        }
    }

    //display
    void Display(){
        for(int i = 0;i<n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Sorting s;
    // s.bubbleSort();
    // s.InsertionSort();
    // s.SelectionSort();
    // s.quickSort(0,10);
    // s.countSort();
    // s.ShellSort();
    // s.BucketSort();
    // s.RadixSort();
    s.Display();
    return 0 ;
}
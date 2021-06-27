#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

class Sorting{
    int arr[10] = {30,20,70,80,10,40,90,50,60,100};
    int n = 10;
    //swap
    void swap(int *x,int *y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    public:
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
    s.quickSort(0,10);
    s.Display();
    return 0 ;
}
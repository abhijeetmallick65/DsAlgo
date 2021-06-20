#include<stdio.h>
#include<iostream>
using namespace std;


//swap function
void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble sort
int * BubbleSort(int a[],int n){
    for(int i = 0;i<n-1;i++){
        int flag = 0;
        for(int j = 0;j<n-1;j++){
            if(a[j] > a[j+1]){
                swap(&a[j],&a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)break;
    }
    return a;
}
//Insertion sort
void InsertionSort(int a[],int n){
    int x = 0,j = 0;
    for(int i = 1;i<n;i++){
        x = a[i];
        j = i-1;
        while(j>=0 && a[j]>x){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

//Selection sort
void SelectionSort(int a[],int n){
    int i,j,k;
    for(i = 0 ;i<n;i++){
        for(j = k = i;j<n;j++){
            if(a[j] < a[k])k = j;
        }
        swap(&a[i],&a[k]);
    }
}

//Quick sort
int partition(int a[],int low ,int high){
    int pivot = a[low];
    int i = low,j = high;
    do{
        do{i++;}while(a[i] <= pivot);
        do{j--;}while(a[j] > pivot);
        if(i<j){
            swap(&a[i],&a[j]);
        }
    }while(i<j);
    swap(&a[low],&a[j]);
    return j;
}
void quickSort(int a[],int low,int high){
    if(low<high){
        int j = partition(a,low,high);
        quickSort(a,low,j);
        quickSort(a,j+1,high);
    }
}

// MERGE
void merger(int a[],int low,int high,int mid){
    int i = low,j = mid+1,k = low;
    int b[high+1];
    while(i<=mid&&j<=high){
        if(a[i] > a[j])b[k++]=a[j++];
        else b[k++] = a[i++];
    }

    while(i <= mid)b[k++] = a[i++];
    while(j <= high)b[k++] = a[j++];

    for(int i= low;i<= high;i++){
       a[i] = b[i];
    }
}
void iterativeMerge(int a[],int n){
    int p,low,high,i,mid;
    for(p = 2;p<=n;p=p*2){
        for(int i = 0;i+p-1<n;i=i+p){
            low = i;
            high = i+p-1;
            mid = (low+high)/2;
            merger(a,low,high,mid);
        }
    }
    if(p/2 < n)merger(a,0,n-1,p/2-1);
}
//Display
void Display(int a[],int n){
    for(int i = 0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

//main
int main(){
    int a[] = {3,1,5,7,8,12,9,4,11,2};
    // BubbleSort(a,10);
    // InsertionSort(a,10);
    // SelectionSort(a,10);
    // quickSort(a,0,10);
    iterativeMerge(a,10);
    Display(a,10);
    return 0;
}
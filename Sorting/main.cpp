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
//Display
void Display(int a[],int n){
    for(int i = 0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int main(){
    int a[] = {3,1,5,7,8,12,9,4,11,2};
    int *b = BubbleSort(a,10);
    Display(b,10);
    Display(a,10);
    return 0;
}
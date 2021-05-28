#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    // cout << "Hello World !" << endl;
    int a = 5;
    int *p = &a;
    cout << "pointer data : \n" << *p;
    cout << "a data : \n" << a;
    int *arr = (int *)malloc(5*sizeof(int));
    int arr2[] = {1,2,3,4,5};
    int *a2 = arr2;
    for(int i = 0 ;i< 5;i++){
        printf("%d\n",a2[i]);
    }
    for(int i : arr2){
        printf("%d : arr\n",i);
    }
}
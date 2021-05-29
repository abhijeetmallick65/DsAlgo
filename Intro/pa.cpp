#include<stdio.h>
#include<iostream>
using namespace std;

int * fun(){
    int *p = (int*)malloc(5*sizeof(int));
    p[0] = 9;
    return p;
}
int main(){
    int *a = fun();
    a[1]= 21;
    cout << a[0] << endl << a[1] << endl;
    return 0;
}
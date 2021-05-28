#include <iostream>
#include <stdio.h>
using namespace std;

int * fun(int n){
    int *a = (int *)malloc(n*sizeof(int));
    for(int i = 0;i< n ; i++){
        a[i] = i +1;
    }
    return a;
}
void fun2(int n[]){
    n[0] = n[0] + 4;
}

int main(){
    int *a = fun(5);
    for(int i = 0 ;i< 5 ;i++){
        cout << a[i] << endl;
    }
    int b[9] = {12,12,13,12};
    fun2(b);
    cout << b[0] << endl;
    cout << "/n" << endl;
}
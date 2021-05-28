#include<stdio.h>
#include<iostream>
using namespace std;

void toh(int n , int a , int b,int c){
    if(n<=0)return;
    // 1 : source to auxiliary 
    toh(n-1,a,c,b);
    // 2 : source to destination
    printf("%d to %d\n",a,c);
    // 3 : auxiliary to destination
    toh(n-1,b,a,c);
}



int main()
{
    // toh(2,1,2,3);
    // bitwise
    char A[] = "this is a string";
    long int h = 0,x = 0,diff= 0;
cout << A<<endl;
    for(int i = 0;A[i] != '\0';i++){
        x = 1; //00000001
        // left shift
        diff = A[i]-97;
        x = x << diff;
        if(/*Masking*/(x&h) > 0){
            cout << "duplicate found : " << A[i] << endl;
        }else{
            // merging
            h= x|h;
        }
    }
    return 0;
}

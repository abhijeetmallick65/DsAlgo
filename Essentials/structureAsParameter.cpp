#include <stdio.h>
#include <iostream>
using namespace std;

 struct Rec{
     int length;
     int breadth;
     int size[10];
};

struct Rec * fun1(){
    // allocating memory in heap
    struct Rec *r1 = (struct Rec *)malloc(sizeof(struct Rec));
    r1->length = 10;
    r1->breadth = 10;
    r1->size[0] = 9;
    return r1;
}

int main(){

    struct Rec *r1 = fun1();
    cout<<"length : " << r1->length << " breadth : " << r1->breadth << " array : " << r1->size[0]<< endl;

    struct Rec r22 = {3,5};
    struct Rec *r2 = &r22;
    cout<<"length : " << r2->length << " breadth : " << r2->breadth << endl;

     return 0;
}
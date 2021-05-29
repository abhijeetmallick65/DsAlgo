#include <stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

struct Rectangle
{
    /* data */
    int length;
    int breadth;
};

int add(int a,int b){
    int c  = a+b;
    return c;
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;  
}
int main(){

    struct Rectangle r1 = {4,8};
    struct Rectangle *p = &r1;
    // cout << p->length << endl << p->breadth << endl;

    // struct Rectangle *p2 = (struct Rectangle *)malloc(sizeof(struct Rectangle)) ;
    struct Rectangle *p2 = new Rectangle;
    p2->breadth = 90;
    p2->length = 80;
    // cout << p2->length << endl << p2->breadth << endl << sizeof(p2) << endl;
// printf("%d",add(1,2));
int a= 8;
int b = 5;
swap(&a,&b);
cout << a << endl << b << endl;
    return 0;
}
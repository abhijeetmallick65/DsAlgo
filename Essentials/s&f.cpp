#include<iostream>
#include<stdio.h>
using namespace std;

struct Rectangle{
    int length = 0;
    int breadth = 0;
};

int area(struct Rectangle r){
    return r.length*r.breadth;
}

int perimeter(struct Rectangle r){
    return 2*(r.length+r.breadth);
}

int main(){
    struct Rectangle r1;
    // cin >> r1.length ;
    // cin >> r1.length ;
    cin >> r1.length >> r1.breadth ;

    int a = area(r1);
    int p = perimeter(r1);

    cout << "Area : " << a << endl << "Breadth : " << p;
    return 0;
}
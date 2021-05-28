#include<iostream>
#include<stdio.h>
using namespace std;

class Rectangle{
private :
    int length = 0;
    int breadth = 0;
public :
    Rectangle(){
        length = 0;
        breadth = 0;
    }

    Rectangle(int l, int b){
        length = l;
        breadth = b;
    }

    // void initialize(int l,int b){
    //     length = l;
    //     breadth = b;
    // }

    int area(){
        return length*breadth;
    }

    int perimeter(){
        return 2*(length+breadth);
    }

    void setLength(int l){
        length = l;
    }

    void setBreadth(int b){
        breadth = b;
    }

    int getLength(){
        return length;
    }

    int getBreadth(){
        return breadth;
    }
    // destructor
    ~Rectangle(){
        cout << "Destructor Ran" << endl;
    }
};

int main(){
    Rectangle r(5,10);
    // r.initialize(5,10);
    cout << "Area : " << r.area() << endl;
    cout << "Perimeter : " << r.perimeter() << endl;

    return 0;
}
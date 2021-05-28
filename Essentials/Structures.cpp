#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

struct Human
{
    /* data */
    int age;
    char name[10];
}x,y,z;


int main(){
    // In c, an array is assignable only in the initialization period, citizen1.name is an array of char type. To solve your problem, you may use this:
    // strcpy(citizen1.name, "Tim McGuiness");
    // x.name = "abhijeet";
    x.age = 21;
    struct Human a;
    strcpy(a.name,"abhijeet");
    a.age = 1;
    cout << a.name << endl;
    cout<<a.age;
    return 0;
}
#include<stdio.h>
#include<iostream>
using namespace std;

class Machine{
    public:
        int price = 10;
        string name;

        Machine(string name){
            this->name = name;
            cout << "constructor ran " << endl;
        }

        string getname(){
            return name;
        }
        void printing(){
            cout << "this is a string" << endl;
        }
};

class Camera : public Machine{
    public:
    Camera(string name) : Machine(name){
        cout<<"s"<<endl;
    }
    void printing2(){
            cout << "this is a  camera string" << endl;
    }
};

int main(){
    Machine machine("new ,machine");
    // machine.printing();
    Camera cam("naming");
    cam.printing();
    cam.printing2();
    return 0;
}

#include<stdio.h>
#include<iostream>
using namespace std;

class Stack{
    
    private:
    int size ;
    int *arr;
    int top;
    public:
    
    Stack(int size){
        this->size = size;
        this->arr = new int[size];
        this->top=-1;
    }
    int isEmpty(){
        if(this->top==-1)return 1;
        return 0;
    }
    void push(int val){
        if(top + 1 == size)return;
        this->top++;
        arr[top] = val;
    }

    int pop(){
        int x = -1;
        if(this->isEmpty())return x;
        x = arr[top];
        top--;
        return x;
    }
    int getTop(){
        return this->arr[top];
    }
    void Display(){
        int i = this->top;
        while (i>=0)
        {
            cout<<arr[i]<< " ";
            i--;
        }
        
    }

};
Stack input(5);
Stack output(5);
int peek(){
    if(output.isEmpty()){
        while(!input.isEmpty()){
            output.push(input.pop());
        }
    }
    return  output.getTop();
}
int popQueue(){
    peek();
    return output.pop();
}

int main(){
    input.push(1011);
    input.push(2);
    input.push(3);
    input.push(4);
    input.push(5);
  
    cout<< popQueue()<<endl;
    cout<< popQueue()<<endl;
    cout<< popQueue()<<endl;
    cout<< popQueue()<<endl;
    cout<< popQueue()<<endl;
    input.push(6);
    input.push(7);
    input.push(8);
    input.push(9);
    cout<< popQueue()<<endl;
    cout<<peek()<<endl;
    return 0;
}
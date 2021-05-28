#include <iostream>
#include<stdio.h>
using namespace std;
 
template<class T>
class arithmetic
{
private:
T a;
T b;
 
public:
arithmetic(T a, T b);
T add();
T sub();
};
 
template<class T>
arithmetic<T>::arithmetic(T a , T b)
{
this->a=a;
this->b=b;
}
 
template<class T>
T arithmetic<T>::add() // this should not take parameters
{
T c;
c=a+b;
return c;
}
 
template<class T>
T arithmetic<T> :: sub() // this should not take parameters
{
T c;
c=a-b;
return c;
}
 
int main(){
arithmetic<int> ar(10,5);
cout<<ar.add();
 
return 0;
}
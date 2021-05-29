#include<stdio.h>
#include<iostream>
using namespace std;

// int x = 0;
int fun1(int n){
    static int x= 0;
    if(n<=0)return 0;
    x++;
    return fun1(n-1) + x;
}

// tail recursion
void funTail(int n){
    if(n<=0)return;
    printf("%d\n",n);
    return funTail(n-1);
}
// Head recursion
void funHead(int n){
    if(n<=0)return;
    funHead(n-1);
    printf("%d\n",n);
}
// Tree Recursion
void funTree(int n){
    if(n<=0)return;
    printf("%d\n",n);
    funTree(n-1);
    funTree(n-1);
}
// Indirect Recursion
void funIndirectB(int n);
void funIndirectA(int n){
    if(n<0)return;
    printf("%d A\n",n);
    funIndirectB(n/2);
}
void funIndirectB(int n){
    if(n<0)return;
    printf("%d B\n",n);
    funIndirectA(n-1);
}

// Nested recusion
int funNested(int n){
    if(n > 100){
        return n-10;
    }
    return funNested(funNested(n+11));
}
int sum(int n){
    if(n== 0)return 0;
    return sum(n-1) + n;
}
int fact(int n){
    if (n <= 1)return 1;
    return fact(n-1) * n;
}
// 24/5/21
int powerL(int x,int y){
    if(y == 0)return 1;
    return powerL(x,y-1) * x;
}
int powerShort(int m,int n){
    if(n==0)return 1;
    else if(n%2 == 0)return powerShort(m*m,n/2);
    else return m * powerShort(m*m,(n-1)/2);
}
double e(int x,int y){
    static double p = 1,f = 1;
    double res;

    if(y==0)return 1;

        res = e(x,y-1);
        p *= x;
        f *= y;
        return res + p/f;
}
double eIter(int x,int n){
    double s = 1;
    for(;n>0;n--){
        s = 1 + (double)x/n*s;
    }
    return s;
}
double eRecur(double x,double n){
    static double s = 1;
    if(n == 0)return s;
    
    s = 1+(double)x/n*s;
    return eRecur(x,n-1);
}

// 27/5/2021
// using DP (I.E CONVERSION OF RECURSIVE SOLUTION TO AN ITERATIVE SOLUTION)
int fib(int n){
    if(n<=1)return n;
    
    int t0 = 0,t1= 1,s= 0;

    for(int i = 2;i<=n;i++){
        s = t0+t1;
        t0= t1;
        t1 = s;
    }
    return s;
}
// 
int rfib(int n){
    if(n<=1) return n;
    return rfib(n-2) + rfib(n-1);
}
// 
int F[10];
int memoFib(int n){

    if(n<=1){
        F[n] = n;
        return n;
    }else{
        if(F[n-2] == -1)
            F[n-2] = memoFib(n-2);
        if(F[n-1] == -1)
            F[n-1] == memoFib(n-1);
        F[n] = F[n-2] + F[n-1];

        return F[n-2] + F[n-1];
    }
}
// combination
// nCr = n!/r!*(n-r)!
int combination(int n,int r){
    int num = fact(n);
    int denominator = fact(r)*fact(n-r);
    return num/denominator;
}
// nCr recursive
int nCr(int n,int r){
    if(n ==r || r == 0)return 1;
    return nCr(n-1,r-1) + nCr(n-1,r);
}
// tower of hanoi
// steps:
    // source to auxiliary
    // source to destination
    // auxiliary to destination

void TOH(int disc , int source,int auxiliary,int destination){
    if(disc>0){
        TOH(disc-1,source,destination,auxiliary);
        cout << source << " " << destination << endl;
        TOH(disc-1,auxiliary,source,destination);
    }
}
// 
int main(){
    // 27/5/21
    TOH(3,1,2,3);
    // cout << nCr(4,2) <<endl;
    // for(int i = 0;i<10;i++)F[i] = -1;
    // int res = F(6);
    // int res = rF(6);
    // int res = memoFib(6);
    // cout << res <<endl;
    // 24/5/21
    // cout << eRecur(4,15) << endl;
    // cout << eIter(1,10) << endl;
    // int val = powerL(3,8);
    // int val2 = powerShort(2,9);
    // cout << val << endl;
    // cout << val2 << endl;

    // 21/5/21
    // int f = fact(5);
    // int s = sum(5);
    // cout<<f<<endl;
//    int r =  funNested(20);
//    cout << r << endl;
    // 18/5/21
    // funTail(5);
    // funHead(5);
    // funTree(2);
    // funIndirectA(20);
    // 17/5/21
    // int res = fun1(5);
    // int res2 = fun1(5);
    // cout<< res << '\t' << res2 << endl;
    return 0;
    
}
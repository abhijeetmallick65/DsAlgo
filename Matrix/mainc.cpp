#include<stdio.h>
#include<iostream>
using namespace std;

// C
// structure for matrix
struct Matrix{
    int *A;
    int n;
};
// Set function for Matrix
void Set(struct Matrix *m,int i,int j,int value){
    if(i!=j)return;
    // i-1 because we are taking index from user starting from 1 but arrays are 0 indexed
    m->A[i-1] = value;
}
// Get function for Matrix
int Get(struct Matrix m,int i,int j){

    if (i==j){
    // i-1 because we are taking index from user starting from 1 but arrays are 0 indexed
        return m.A[i-1];
    }
    return 0;
}
// Display Matrix 
void Display(struct Matrix m){
    for(int i = 0 ;i< m.n;i++){
        for (int j = 0;j< m.n;j++){
            if(i==j){
                cout << " "<< m.A[i] << " ";
            }else{
                cout << " 0 ";
            }
        }
        cout<< endl;
    }
}

// main
int main(){
    struct Matrix m;
    // cout << "size of the matrix ";
    // cin >> m.n;
    m.n  = 5;
    m.A = (int *)malloc(5*sizeof(int));
    Set(&m,1,1,5);
    Set(&m,2,2,4);
    Set(&m,3,3,3);
    Set(&m,4,4,2);
    Set(&m,5,5,1);
    cout << Get(m,2,2) << endl;
    Display(m);

    /*

    struct Matrix m;
    cout << "enter matrix size :" ;
    cin >> m.n;
    // m.A = (int*)malloc(m.n*sizeof(int));
    m.A = new int[m.n];

    for(int i = 0;i< m.n;i++){
        int value = 0;
        for(int j = 0;j<m.n;j++){
            if(i == j){
                cout << "enter value" << endl;
                cin >> value;
                m.A[i] = value;
            }
        }
    }
    for(int i = 0 ;i< m.n;i++){
        for (int j = 0;j< m.n;j++){
            if(i==j){
                cout << " "<< m.A[i] << " ";
            }else{
                cout << " 0 ";
            }
        }
        cout<< endl;
    }
    */
return 0;

}
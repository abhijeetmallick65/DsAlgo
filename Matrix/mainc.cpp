#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

// C
// structure for matrix
struct Matrix{
    int *A;
    int n;
};
// Set function for Matrix
void Set(struct Matrix *m,int i,int j,int value){
    // diAGONAL
    // if(i!=j)return;
    // i-1 because we are taking index from user starting from 1 but arrays are 0 indexed
    // m->A[i-1] = value;

    // // lower
    // row major
    // if(i>=j){
    //     m->A[i*(i-1)/2 + j-1] = value;
    // }

    // column major
    if(i>=j){
        m->A[m->n*(j-1) + (j-1)*(j-2)/2 + (i-j)] = value;
    }
}
// Get function for Matrix
int Get(struct Matrix m,int i,int j){
    // i-1 because we are taking index from user starting from 1 but arrays are 0 indexed

    if (i>=j){
        // return m.A[i*(i-1)/2 + j-1];
        return m.A[m.n*(j-1) + (j-1)*(j-2)/2 + (i-j)];
    }else{
        return 0;
    }
}
// Display Matrix 
void Display(struct Matrix m){
    for(int i = 1 ;i<= m.n;i++){
        for (int j = 1;j<= m.n;j++){
            if(i>=j){
                cout << " "<< m.A[m.n*(j-1) + (j-1)*(j-2)/2 + i- j] << " ";
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
    // m.A = (int *)malloc(5*sizeof(int));
    m.A = (int*)malloc(m.n*(m.n+1)/2*sizeof(int));
    int value;
    cout << "enter elements" << endl;
    for(int i = 1; i<= m.n;i++){
        for(int j = 1;j<=m.n;j++){
            if(i>=j){
                scanf("%d",&value);
                Set(&m,i,j,value);
            }else{
                Set(&m,i,j,0);
            }
        }
    }
    cout << endl;
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
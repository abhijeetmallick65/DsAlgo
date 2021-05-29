#include<stdio.h>
#include<iostream>
using namespace std;
// C++
class Matrix{
    private:
    // data - members
    int *A;
    int n;
    
    public:
    // member functions
    // constructor
    Matrix(){
        n = 2;
        A = new int[n];
    }
    Matrix(int n){
        this->n = n;
        A = new int[n];
    }
    
    // Set function for matrix
    void Matrix :: Set(int i,int j,int value){
        if(i!=j)return;
        // i-1 because we are taking index from user starting from 1 but arrays are 0 indexed
       A[i-1] = value;
    }
    // Get function for matrix
    int Matrix :: Get(int i,int j){
        if (i==j){
        // i-1 because we are taking index from user starting from 1 but arrays are 0 indexed
            return A[i-1];
        }
        return 0;
    }
    // Display Matrix 
    void Matrix :: Display(){
        for(int i = 0 ;i< n;i++){
            for (int j = 0;j< n;j++){
                if(i==j){
                    cout << " "<< A[i] << " ";
                }else{
                    cout << " 0 ";
                }
            }
            cout<< endl;
        }
    }
    // destructor 
    ~Matrix(){
        delete []A;
    }
};

// C
// structure for matrix
struct Matrix2{
    int *A;
    int n;
};
// Set function for matrix2
void Set(struct Matrix2 *m,int i,int j,int value){
    if(i!=j)return;
    // i-1 because we are taking index from user starting from 1 but arrays are 0 indexed
    m->A[i-1] = value;
}
// Get function for matrix2
int Get(struct Matrix2 m,int i,int j){

    if (i==j){
    // i-1 because we are taking index from user starting from 1 but arrays are 0 indexed
        return m.A[i-1];
    }
    return 0;
}
// Display Matrix2 
void Display(struct Matrix2 m){
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

    Matrix m(5);
    m.Set(1,1,3);
    m.Set(2,2,4);
    m.Set(3,3,7);
    m.Set(4,4,76);
    m.Set(5,5,6);
    m.Display();
    cout<< m.Get(1,4) << endl;
    cout<< m.Get(1,1) << endl;
    /*
    struct Matrix m;
    // cout << "size of the matrix ";
    // cin >> m.n;
    m.n  = 5;
    Set(&m,1,1,5);
    Set(&m,2,2,4);
    Set(&m,3,3,3);
    Set(&m,4,4,2);
    Set(&m,5,5,1);
    cout << Get(m,2,5) << endl;
    Display(m);


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
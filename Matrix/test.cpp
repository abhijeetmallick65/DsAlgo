#include<stdio.h>
#include<iostream>
using namespace std;

class Matrix{
    private:
    int *A;
    int n;

    public:
    Matrix(int n){
        /*
        // 1 diagonal matrix && symmetric matrix
        this->n = n;
        A= new int[n];
        */
       /*
       //    2 Lower triangular & upper triangular
       this->n = n;
       A = new int[n*(n+1)/2];*/

       /* // 3 Tri diagonal matrix
       this->n = n;
       A = new int[3*n-2];
       */
      /* // toeplitz matrix*/
      this->n = n;
      A = new int[2 * n -1];
    }
    /*
    // 1 diagonal matrix && symmetric matrix
    void create(){
        int x;
        cout << " enter the matrix " << endl;
        for(int i = 1;i<= n;i++){
            for(int j = 1;j<=n;j++){
                cin>> x;
                set(i,j,x);
            }
        }
    }
    void set(int i ,int j,int value){
        if(i!=j) return;
        A[i-1] = value;
    }
    int get(int i,int j){
        if(i==j){
            return A[i-1];
        }else{
            return 0;
        }
    }
    //  Diagonal matrix

    void Display(){
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    cout<< " "<<A[i-1] << " ";
                }else{
                    cout << " "<< 0 << " ";
                }
            }
            cout<< endl;
        }
    }
    // symmetric
    void Display2(){
        cout << endl;
        cout << "Matrix is :  " << endl;
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=n;j++){
               if(i>j){
                   cout<< A[j-1] << " ";
               }else if(j > i) {
                   cout<< A[i-1]<< " " ;
               }else{
                   cout<< A[i-1] << " " ;
               }
            }
            cout<< endl;
        }
    }
*/
  /*
//    2 Lower triangular
void create(){
        int x;
        cout << " enter the matrix " << endl;
        for(int i = 1;i<= n;i++){
            for(int j = 1;j<=n;j++){
                cin>> x;
                set(i,j,x);
            }
        }
    }
    void set(int i ,int j,int value){
        if(i>=j){
// row major
            // A[i*(i-1)/2 + j-1] = value;
// column major

            A[n*(j-1) - (j-1)*(j-2)/2 + i-j] = value;

        }
    }
    int get(int i,int j){
        if(i>=j){
            // row major
            // return A[i*(i-1)/2 + j-1];
            // column major
            return A[n*(j-1) - (j-1)*(j-2)/2 + i-j] ;
        }else{
            return 0;
        }
    }
    void Display(){
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i>=j){
                    // row major
                    // cout<< " "<<A[i*(i-1)/2 + j-1] << " ";
                    // column major
                    cout<< " "<<A[n*(j-1) - (j-1)*(j-2)/2 + i-j]  << " ";
                }else{
                    cout << " "<< 0 << " ";
                }
            }
            cout<< endl;
        }
    }

//    upper triangle : i <= j
     void create(){
        int x;
        cout << " enter the matrix " << endl;
        for(int i = 1;i<= n;i++){
            for(int j = 1;j<=n;j++){
                cin>> x;
                set(i,j,x);
            }
        }
    }
    void set(int i ,int j,int value){
        if(i<=j){
        // row major
            A[n*(i-1) - (i-1)*(i-2)/2 + j-i] = value;
        }
    }
    int get(int i,int j){
        if(i<=j){
            // row major
            return A[n*(i-1) - (i-1)*(i-2)/2 + j-i];
        }else{
            return 0;
        }
    }
    void Display(){
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i<=j){
                    // row major
                    // cout<< " "<<A[i*(i-1)/2 + j-1] << " ";
                    // column major
                    cout<< " "<<A[n*(i-1) - (i-1)*(i-2)/2 + j-i]<< " ";
                }else{
                    cout << " "<< 0 << " ";
                }
            }
            cout<< endl;
        }
    }    
    
   // Tridiagonal matrix
       void create(){
        int x;
        cout << " enter the matrix " << endl;
        for(int i = 1;i<= n;i++){
            for(int j = 1;j<=n;j++){
                cin>> x;
                set(i,j,x);
            }
        }
    }
    void set(int i ,int j,int value){
        if(i-j == 1){
            A[i-2] = value;
        }else if(i-j == 0){
            A[n-1 + i -1]=value;
        }else if(i-j == -1){
            A[2 * n - 1 + i - 1] = value;
        }
        return;
    }
    int get(int i,int j){
        if(i-j == 1){ 
            return A[i-2];
        }else if(i-j == 0){
            return A[n-1 + i -1];
        }else if(i-j == -1){
            return A[2 * n - 1 + i-1] ;
        }
       return 0;
    }
    //  Diagonal matrix

    void Display(){
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=n;j++){
            if(i-j == 1){
                cout << " " << A[i-2];
            }else if(i-j == 0){
                cout << " " << A[n-1 + i -1];
            }else if(i-j == -1){
                cout << " " << A[2 * n - 1 + i-1];
            }else{
                cout <<" "<< 0;
                }
            }
            cout<< endl;
        }
    }
    */
//    toeplitz matrix
    void create(){
        int x;
        cout << " enter the matrix " << endl;
        for(int i = 1;i<= n;i++){
            for(int j = 1;j<=n;j++){
                cin>> x;
                set(i,j,x);
            }
        }
    }
    void set(int i ,int j,int value){
        if(i>j){
            A[n + i - j - 1]= value;
        }else{
            A[j-i] = value;
        }
    }
    int get(int i,int j){
        if(i>j){
            return A[n + i - j - 1];
        }else{
            return A[j-i] ;
        }
    }
    //  Diagonal matrix

    void Display(){
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i>j){
                    cout << " " << A[n + i - j -1];
                }else{
                    cout << " " << A[j-i];
                }
            }
            cout<< endl;
        }
    }
    ~Matrix(){
        delete [] A;
    }
};

int main(){
    Matrix m(4);
    m.create();
    m.Display();
    cout << m.get(2,2) << endl;
    return 0;
}
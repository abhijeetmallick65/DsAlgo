
#include "h.h"
using namespace std;

int HashFunction(int val){
    return val % 10;
}

void Insert(struct Node* *arr,int val){
    int idx = HashFunction(val);
    hashInsert(&arr[idx],val);
}

int Delete(struct Node* *arr,int val){
    int idx = HashFunction(val);
    return hashDelete(&arr[idx],val);
}

int Search(struct Node* *arr,int val){
    int idx = HashFunction(val);
    return hashSearch(arr[idx],val);
}

int main(){
    struct Node* bucket[10];
    for(int i = 0;i<10;i++)bucket[i] = NULL;
    int a[] = {16,12,25,39,6,122,5,68,65};
    for(int i = 0;i<9;i++)Insert(bucket,a[i]);
    // cout << Search(bucket,60) << endl;
    cout << Delete(bucket,25) <<  endl;
    return 0;
}
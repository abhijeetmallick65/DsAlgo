#include "Queue.h"

void BreadthFirstSearch(int G[][7],int start,int n){
    int i = start;
    int visited[7] = {0};
    cout << i << " ";
    visited[i] = 1;
    enqueue(i);

    while(!isEmpty()){
        i = dequeue();
        for(int v = 1;v<n;v++){
            if(G[i][v] == 1 && visited[v] == 0){
                cout << v << " ";
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

void DepthFirstSearch(int G[][7],int start,int n){
    int i = start;
   static int visited[7] = {0};
    if(visited[i] == 0){
        printf("%d ",i);
        visited[i] = 1;
        for(int j = 1;j<n;j++){
            if(G[i][j] == 1 && visited[j] == 0){
                DepthFirstSearch(G,j,n);
            }
        }
    }
}

int main(){
    int G[7][7]={{0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};
    // BreadthFirstSearch(G,1,7);
    DepthFirstSearch(G,1,7);
    return 0;
}


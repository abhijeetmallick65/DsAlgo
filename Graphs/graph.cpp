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

void bfs(int graph[][7],int start,int n){
    int i = start;
    int visited[7] = {0};
    printf("%d",start);
    enqueue(i);
    visited[i] = 1;
    while(!isEmpty()){
        i = dequeue();
        for(int v = 1;v< n;v++){
            if(graph[i][v] == 1 && visited[v] == 0){
                enqueue(v);
                printf(" %d",v);
                visited[v] = 1;
            }
        }
    }
}

void dfs(int graph[][7] ,int start , int n){
    static int visited[7] = {0};
    int i = start;
    if(visited[i] == 0){
        cout<<i <<" ";
        visited[i] = 1;
        for(int v = 0;v < n;v++){
            if(graph[i][v] == 1 && visited[v] == 0){
                dfs(graph,v,7);
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
    // bfs(G,1,7);
    dfs(G,1,7);
    return 0;
}


#include "Queue.h"

#define I 32767  // Infinity
#define V 7  // # of vertices in Graph
#define E 9  // # of edges in Graph
void Display(int result[][V-1]){
    for(int i = 0;i< V-1;i++){
        cout << "[" << result[0][i] << "," << result[1][i] << "]" << endl;
    }
}
void bfs(int graph[][7],int start, int n){
    int i = start;
    int visited[n]={0};

    cout << i << " ";
    visited[i] = 1;
    enqueue(i);

    while(!isEmpty()){
        i = dequeue();
        for(int u = 1;u<=n;u++){
            if(graph[i][u] == 1 && visited[u] == 0){
                cout << u << " ";
                visited[u] = 1;
                enqueue(u);
            }
        }
    }
}

void dfs(int graph[][7],int start,int n){
    static int visited[7] = {0};
    if(visited[start] == 0){
        cout<< start << " ";
        visited[start] = 1;
        for(int i = 1; i<= n;i++){
            if(graph[start][i] == 1 && visited[i] == 0){
                dfs(graph,i,n);
            }
        }
    }
}

//uinon
int find(int u, int set[]){
    int x = u;
    int v = 0;
    while(set[x] > 0){
        x = set[x];
    }
    while(u != x){
        v= set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

void Union(int u,int v,int set[]){
    if(set[u] < set[v]){
        set[u]+=set[v];
        set[v] = u;
    }else{
        set[v]+=set[u];
        set[u] = v;
    }
}

void kruskal(int edges[][E]){
    int i = 0 , j , k , min , u , v , n = V;
    int visited[E] = {0};
    int set[V+1] = {-1, -1, -1, -1, -1, -1, -1, -1};
    int result[2][V-1] = {0};

    while(i< n-1){
        min = I;
        for(j = 1;j<=n;j++){
            if(edges[2][j] < min && visited[j] == 0){
                k = j;
                u = edges[0][j];
                v = edges[1][j];
                min = edges[2][j];
            }
        }
        if(find(u,set) != find(v,set)){
            Union(find(u,set),find(v,set),set);
            result[0][i] = u;
            result[1][i] = v;
            i++;
        }
        visited[k] = 1;
    }
    Display(result);
}
int main()
{
 int G[7][7]={{0,0,0,0,0,0,0},
 {0,0,1,1,0,0,0},
 {0,1,0,0,1,0,0},
 {0,1,0,0,1,0,0},
 {0,0,1,1,0,1,1},
 {0,0,0,0,1,0,0},
 {0,0,0,0,1,0,0}};
//  bfs(G,4,7);
//  dfs(G,4,7);
    int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
 
    kruskal(edges);

 return 0;
}
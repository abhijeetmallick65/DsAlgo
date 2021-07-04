#include<stdio.h>
#include<iostream>
using namespace std;

#define I 32767  // Infinity
#define V 7  // # of vertices in Graph
#define E 9  // # of edges in Graph

void Display(int result[][V-1]){
    for(int i = 0;i< V-1;i++){
        cout << "[" << result[0][i] << "," << result[1][i] << "]" << endl;
    }
}

void Union(int u,int v,int set[]){
    if(set[u] < set[v]){
        set[u] += set[v];
        set[v]  = u;
    }else{
        set[v] += set[u];
        set[u] = v;
    }
}
int find(int u , int set[]){
    int x = u;
    while(set[x] > 0){
        x = set[x];
    }
    int v = 0;
    while(u != x){
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}
void kruskal(int graph[][E]) {
    int min , i = 0, j ,k , u , v;
    int visited[E] = {0};
    int result[2][V-1] = {0};
    int set[V + 1] = {-1,-1,-1,-1,-1,-1,-1};

    while(i< V-1){
        min = I;
        for(j = 0;j< E ; j++){
            if(graph[2][j] < min && visited[j] == 0){
                min = graph[2][j];
                u = graph[0][j];
                v = graph[1][j];
                k = j;
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

int main() {
    int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
 
    kruskal(edges);
 
    return 0;
}
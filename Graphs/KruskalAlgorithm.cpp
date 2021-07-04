#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
 
#define I 32767  // Infinity
#define V 7  // # of vertices in Graph
#define E 9  // # of edges in Graph
 
 //union operation
void UnionFunction(int u,int v , int s[]){
    if(s[u] < s[v]){
        s[u]+=s[v];
        s[v] = u;
    }else{
        s[v]+=s[u];
        s[u] = v;
    }
}

//find / collapsing find
int find(int u,int set[]){
    int x = u,v = 0;
    while (set[x] > 0)
    {
        x = set[x];
    }
    while (u!=x)
    {
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}
//print mst
void Display(int n ,int result[][V-1]){
    for(int i = 0;i< n;i++){
        cout << "[" << result[0][i] << "," << result[1][i] << "]" << endl;
    }
    cout <<endl;
}
void kruskalAlgorithm(int edges[][9],int e,int n){
    int i = 0,j = 0,k = 0, min , u , v ;
    int result[2][V-1] = {0};
    int included[e] = {0};
    int set[n+1];

    for(int i = 0;i< n+1;i++)set[i] = -1;

    while(i<n-1){
        min = I;
        for(int j = 0;j < e;j++){
            if(edges[2][j] < min && included[j] == 0){
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }
        if(find(u,set) != find(v,set)){
            UnionFunction(find(u,set),find(v,set),set);
            result[0][i] = u;
            result[1][i] = v;
            i++;
        }
        included[k] = 1;
    }
    Display(n,result);
}
int main() {
    int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
 
    kruskalAlgorithm(edges,9,7);
 
    return 0;
}
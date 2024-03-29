#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int graph1[N][N];

vector<int> graph2[N]; //adjacency lists vector of arrays

vector<pair<int,int>> graph3[N];

int main(){
    //adjacency matrix
    //make 2d array and use 1 to make the vertices connected
    int n, m; // vertices and edges
    cin >> n >> m;
    for(int i =0; i < m; i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph1[v1][v2] = 1;
        graph1[v2][v1] = 1;

        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
        
        graph3[v1].push_back({v2, wt});
        graph3[v2].push_back({v1, wt});


    }
    int i, j; cin >> i >> j;
    //i, j connected ? , i, j ka weight? 
    if(graph1[i][j]==1) //connected

    for(int child : graph2[i]){
        if(child == j){
            //connected
        }
    }

    for(pair<int,int> child : graph3[i]){
        if(child.first == j){
            //connected
            int weight = child.second;
        }
    }
}
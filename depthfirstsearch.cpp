#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
vector<int> g[N];
bool vis[N];

void dfs(int vertex){
    //take action on vertex after entering the vertex
    // if(vis[vertex]) return; //same as line 15
    cout << vertex << endl;
    vis[vertex] = true;
    for(int child : g[vertex]){
        cout << "parent" << vertex << "child" << child << endl;
        if(vis[child]) continue;
        //take action on child before entering the child node
        dfs(child);
        //take action on child after exiting child node
    }
    //take action on vertex before exiting the vertex
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1);
}
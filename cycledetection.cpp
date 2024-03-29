#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
vector<int> g[N];
bool vis[N];

vector<vector<int>> cc;
vector<int> currentconnectedcomponent;

bool dfs(int vertex, int parent){
    //take action on vertex after entering the vertex
    // if(vis[vertex]) return; //same as line 15
    // cout << vertex << endl;
    vis[vertex] = true;
    bool isLoopExists = false;
    for(int child : g[vertex]){
        // cout << "parent" << vertex << "child" << child << endl;
        if(vis[child] && child == parent) continue;
        if(vis[child]) return true;
        //take action on child before entering the child node
        isLoopExists |= dfs(child, vertex);
        //take action on child after exiting child node
    }
    //take action on vertex before exiting the vertex
    return isLoopExists;
}

int main(){
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bool isLoopExists = false;
    for(int i = 1; i <= n; ++i){
        if(vis[i]) continue;
        if (dfs(i, 0)){
            isLoopExists = true;
            break;
        }
    }
    cout << isLoopExists << endl;
}
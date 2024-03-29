#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
vector<int> g[N];
bool vis[N];

vector<vector<int>> cc;
vector<int> currentconnectedcomponent;

void dfs(int vertex){
    //take action on vertex after entering the vertex
    // if(vis[vertex]) return; //same as line 15
    currentconnectedcomponent.push_back(vertex);
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
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ct = 0;
    for(int i = 1; i <= n; ++i){
        if(vis[i]) continue;
        currentconnectedcomponent.clear(); 
        dfs(i);
        cc.push_back(currentconnectedcomponent);
        ct++;
    }
    cout << endl << "count of connected comps" << ct << endl;

    cout << cc.size() << endl;
    for(auto c : cc){
        for(int vertex: c){
            cout << vertex << " ";
        }
        cout << endl;
    }
}
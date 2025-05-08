

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int x, int y, vector<vector<bool>> &visited, vector<pair<int, int>> &region) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    visited[x][y] = true;
    region.push_back({x, y});
    
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i].first, ny = y + directions[i].second;
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !visited[nx][ny]) {
            dfs(grid, nx, ny, visited, region);
        }
    }
}

vector<set<pair<int, int>>> findRegions(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<set<pair<int, int>>> regions;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                vector<pair<int, int>> region;
                dfs(grid, i, j, visited, region);
                regions.push_back(set<pair<int, int>>(region.begin(), region.end()));
            }
        }
    }
    return regions;
}

int countMatches(vector<string> grid1, vector<string> grid2) {
    int n = grid1.size();
    int m = grid1[0].size();
    
    vector<vector<int>> g1(n, vector<int>(m));
    vector<vector<int>> g2(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g1[i][j] = grid1[i][j] - '0';
            g2[i][j] = grid2[i][j] - '0';
        }
    }

    vector<set<pair<int, int>>> regions1 = findRegions(g1);
    vector<set<pair<int, int>>> regions2 = findRegions(g2);
    
    int matchCount = 0;
    for (auto &r1 : regions1) {
        for (auto &r2 : regions2) {
            if (r1 == r2) {
                matchCount++;
                break;
            }
        }
    }
    
    return matchCount;
}

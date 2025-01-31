#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<int>& board, int currRow, int currCol) {
    for(int i = 0; i < board.size(); ++i) {
        int placedRow = board[i];
        int placedCol = i + 1;
        if(abs(placedRow - currRow) == abs(placedCol - currCol)) {
            return false;
        }
    }
    return true;
}

void nQueenUtil(int col, int n, vector<int>& board, 
                vector<vector<int>>& result, vector<bool>& visited) {
    if(col > n) {
        result.push_back(board);
        return;
    }
    for(int row = 1; row <= n; ++row) {
        if(!visited[row]) {
            if(isSafe(board, row, col)) {
                visited[row] = true;
                board.push_back(row);
                nQueenUtil(col + 1, n, board, result, visited);
                board.pop_back();
                visited[row] = false;
            }
        }
    }
}

vector<vector<int>> nQueen(int n) {
    vector<vector<int>> result;
    vector<int> board;
    vector<bool> visited(n + 1, false);
    nQueenUtil(1, n, board, result, visited);
    return result;
}

int main() {
    int n = 8;
    cin >> n;
    vector<vector<int>> result = nQueen(n);

    cout << "There are " << result.size() << " possible solutions for n = " << n << ".\n";
    // for(auto &res : result) {
    //     cout << "[";
    //     for(int i = 0; i < n; ++i) {
    //         cout << res[i];
    //         if(i != n - 1) cout << ", ";
    //     }
    //     cout << "]\n";
    // }
    return 0;
}

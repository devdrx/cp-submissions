#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int INF = INT_MAX;

// Function to find the minimum cost Hamiltonian cycle using backtracking
void tspBacktracking(vector<vector<int>> &graph, vector<bool> &visited, int currPos, int n, int count, int cost, int &minCost, int start) {
    // If all vertices are visited and there is an edge back to the start vertex
    if (count == n && graph[currPos][start] != 0) {
        minCost = min(minCost, cost + graph[currPos][start]);
        return;
    }

    // Try next vertices
    for (int i = 0; i < n; i++) {
        // Check if node i is not visited and there is a direct edge from currPos to i
        if (!visited[i] && graph[currPos][i] != 0) {
            // Mark as visited
            visited[i] = true;
            // Recur to find the next vertex
            tspBacktracking(graph, visited, i, n, count + 1, cost + graph[currPos][i], minCost, start);
            // Backtrack
            visited[i] = false;
        }
    }
}

int main() {
    // Number of vertices in the graph
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Graph represented as a 2D matrix
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the adjacency matrix (enter 0 if there is no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // Initialize variables
    vector<bool> visited(n, false);
    int minCost = INF;

    // Starting node (Assume we start from node 0)
    visited[0] = true;
    tspBacktracking(graph, visited, 0, n, 1, 0, minCost, 0);

    // Output the minimum cost Hamiltonian cycle
    if (minCost == INF) {
        cout << "No Hamiltonian cycle exists." << endl;
    } else {
        cout << "The minimum cost of the Hamiltonian cycle is: " << minCost << endl;
    }

    return 0;
}

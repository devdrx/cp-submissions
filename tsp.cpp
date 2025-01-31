#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 1e9; // A large value representing infinity

// Function to find the shortest path from a source node using Dijkstra's algorithm
void dijkstra(int source, vector<vector<pair<int, int>>> &graph, int n) {
    // Vector to store the minimum distance from the source to each node
    vector<int> dist(n, INF);
    dist[source] = 0;

    // Min-heap priority queue to efficiently find the node with the smallest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source}); // {distance, node}

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // If the distance is outdated, skip it
        if (currentDist > dist[currentNode])
            continue;

        // Explore all adjacent nodes
        for (auto &neighbor : graph[currentNode]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            // If a shorter path is found
            if (dist[currentNode] + weight < dist[nextNode]) {
                dist[nextNode] = dist[currentNode] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    // Output the shortest distances from the source node
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    // Graph represented as an adjacency list
    vector<vector<pair<int, int>>> graph(n);
    cout << "Enter the edges (source, destination, weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w}); // Directed edge from u to v with weight w
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    // Find the shortest path from the source node
    dijkstra(source, graph, n);

    return 0;
}

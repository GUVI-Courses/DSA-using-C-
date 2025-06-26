#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

// Function to perform Bellman-Ford Algorithm
void bellmanFord(int vertices, int edges, vector<tuple<int, int, int>>& edgeList, int source) {
    vector<int> distance(vertices, INT_MAX); // Distance from source to each vertex
    distance[source] = 0;

    // Relax edges up to (vertices - 1) times
    for (int i = 1; i < vertices; ++i) {
        for (const auto& edge : edgeList) {
            int u, v, w;
            tie(u, v, w) = edge; // Extract the edge details
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edgeList) {
        int u, v, w;
        tie(u, v, w) = edge;
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            cout << "Graph contains a negative-weight cycle.\n";
            return;
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < vertices; ++i) {
        if (distance[i] == INT_MAX) {
            cout << i << "\tINF\n";
        } else {
            cout << i << "\t" << distance[i] << "\n";
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<tuple<int, int, int>> edgeList; // To store edges as (u, v, weight)

    cout << "Enter the edges (u v w):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // u -> start vertex, v -> end vertex, w -> weight
        edgeList.push_back({u, v, w});
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(vertices, edges, edgeList, source);

    return 0;
}

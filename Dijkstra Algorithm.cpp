#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to perform Dijkstra's algorithm
void dijkstra(const vector<vector<pair<int, int>>>& graph, int source) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX); // Distance from source to each vertex
    distance[source] = 0;

    // Priority queue to store (distance, vertex) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first; // Current distance
        int u = pq.top().second;  // Current vertex
        pq.pop();

        // Process neighbors
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;  // Neighbor vertex
            int weight = neighbor.second; // Edge weight

            // Relaxation step
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    // Print the shortest distances
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < n; ++i) {
        cout << i << "\t" << distance[i] << "\n";
    }
}

int main() {
    int n, m; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    cout << "Enter the edges (u v w):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // u -> start vertex, v -> end vertex, w -> weight
        graph[u].push_back({v, w});
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}

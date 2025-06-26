#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
private:
    int vertices; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    // Constructor to initialize the graph
    Graph(int v) : vertices(v + 1) { // Adjust for 1-based indexing
        adjList.resize(v + 1);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        if (u > vertices || v > vertices) {
            cout << "Invalid edge: (" << u << ", " << v << ")" << endl;
            return;
        }
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // Function to perform BFS traversal
    void BFS(int start) {
        vector<bool> visited(vertices, false); // Track visited nodes
        queue<int> q; // Queue for BFS

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            // Visit all adjacent vertices
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Helper function for DFS traversal
    void DFSUtil(int current, vector<bool>& visited) {
        visited[current] = true;
        cout << current << " ";

        // Visit all adjacent vertices
        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // Function to perform DFS traversal
    void DFS(int start) {
        vector<bool> visited(vertices, false); // Track visited nodes
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph graph(vertices);

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        if (u < 1 || v < 1 || u > vertices || v > vertices) {
            cout << "Invalid edge! Vertices must be between 1 and " << vertices << "." << endl;
            continue;
        }
        graph.addEdge(u, v);
    }

    int start;
    cout << "Enter the starting vertex for traversal: ";
    cin >> start;
    if (start < 1 || start > vertices) {
        cout << "Invalid starting vertex! Must be between 1 and " << vertices << "." << endl;
        return 0;
    }

    // Perform BFS and DFS
    graph.BFS(start);
    graph.DFS(start);

    return 0;
}

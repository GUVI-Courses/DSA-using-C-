#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the vertex with the minimum key value
int findMinVertex(int vertices, vector<int>& key, vector<bool>& mstSet) {
    int minKey = INT_MAX, minVertex = -1;
    for (int v = 0; v < vertices; v++) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minVertex = v;
        }
    }
    return minVertex;
}

// Function to implement Prim's Algorithm
void primsAlgorithm(int vertices, vector<vector<int>>& graph) {
    vector<int> key(vertices, INT_MAX);      // Minimum weights to include a vertex
    vector<int> parent(vertices, -1);       // Stores the MST
    vector<bool> mstSet(vertices, false);   // True if vertex is included in MST

    key[0] = 0; // Start from vertex 0

    for (int count = 0; count < vertices - 1; count++) {
        int u = findMinVertex(vertices, key, mstSet);
        mstSet[u] = true;

        // Update the key values of adjacent vertices
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Display the MST
    cout << "\nEdge \tWeight" << endl;
    for (int i = 1; i < vertices; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int vertices = 6; // Number of vertices
    vector<vector<int>> graph = {
        {0, 28, 0, 0, 0, 10},
        {28, 0, 16, 0, 14, 0},
        {0, 16, 0, 12, 0, 0},
        {0, 0, 12, 0, 22, 18},
        {0, 14, 0, 22, 0, 24},
        {10, 0, 0, 18, 24, 0}
    };

    cout << "Prim's Minimum Spanning Tree Algorithm" << endl;
    primsAlgorithm(vertices, graph);

    return 0;
}

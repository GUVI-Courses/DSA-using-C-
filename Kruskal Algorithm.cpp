#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    vector<Edge> edges;
};

// Comparator function to sort edges by weight
bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

// Function to find the root of a node in the disjoint set
int findParent(int v, vector<int>& parent) {
    if (parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent); // Path compression
}

// Function to union two subsets
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

// Kruskal's Algorithm
void kruskalMST(Graph& graph) {
    vector<Edge> result; // Store edges in MST
    vector<int> parent(graph.V);
    vector<int> rank(graph.V, 0);

    // Initialize disjoint sets
    for (int i = 0; i < graph.V; i++) {
        parent[i] = i;
    }

    // Sort all edges by weight
    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    // Iterate through all edges and add to MST if it doesn't form a cycle
    for (Edge& edge : graph.edges) {
        int rootU = findParent(edge.src, parent);
        int rootV = findParent(edge.dest, parent);

        if (rootU != rootV) {
            result.push_back(edge);
            unionSets(rootU, rootV, parent, rank);
        }

        if (result.size() == graph.V - 1) break; // Stop if MST is complete
    }

    // Print the MST
    cout << "\nEdges in the Minimum Spanning Tree (MST):\n";
    cout << "Source - Destination : Weight\n";
    for (Edge& edge : result) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
}

int main() {
    int V = 7; // Number of vertices
    int E = 9; // Number of edges

    Graph graph;
    graph.V = V;
    graph.E = E;

    // Add edges to the graph
    graph.edges = {
        {1, 2, 28}, {1, 6, 10}, {2, 7, 14}, {2, 3, 16},
        {3, 4, 12}, {4, 5, 22}, {5, 6, 25}, {5, 7, 24},
        {4, 7, 18}
    };

    // Run Kruskal's Algorithm
    cout << "Kruskal's Algorithm - Minimum Spanning Tree\n";
    kruskalMST(graph);

    return 0;
}

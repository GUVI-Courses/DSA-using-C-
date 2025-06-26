#include <iostream>
#include <vector>

using namespace std;

void createAdjList(int vertices, vector<vector<int>>& adjList) {
    int edges, u, v;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }
}


void displayAdjList(int vertices, vector<vector<int>>& adjList) {
    cout << "\nAdjacency List Representation:" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        for (int j : adjList[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}


void createAdjMatrix(int vertices, vector<vector<int>>& adjMatrix) {
    int edges, u, v;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph
    }
}



void displayAdjMatrix(int vertices, vector<vector<int>>& adjMatrix) {
    cout << "\nAdjacency Matrix Representation:" << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void createCostAdjMatrix(int vertices, vector<vector<int>>& costMatrix) {

    int edges, u, v, cost;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the edges with costs (u v cost):" << endl;

    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> cost;
        costMatrix[u][v] = cost;
        costMatrix[v][u] = cost; // For undirected graph
    }



}

void displayCostAdjMatrix(int vertices, vector<vector<int>>& costMatrix) {
    cout << "\nCost Adjacency Matrix Representation:" << endl;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << costMatrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;


    // Adjacency List
    vector<vector<int>> adjList(vertices);
    createAdjList(vertices, adjList);
    displayAdjList(vertices, adjList);

     // Adjacency Matrix
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));
    createAdjMatrix(vertices, adjMatrix);
    displayAdjMatrix(vertices, adjMatrix);


     // Cost Adjacency Matrix
    vector<vector<int>> costMatrix(vertices, vector<int>(vertices, 0));
    createCostAdjMatrix(vertices, costMatrix);
    displayCostAdjMatrix(vertices, costMatrix);


    return 0;
}

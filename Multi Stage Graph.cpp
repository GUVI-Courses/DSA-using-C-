#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to solve the multistage graph problem
int multistageGraph(vector<vector<int>>& graph, int stages, int vertices) {
    vector<int> cost(vertices + 1, INT_MAX);
    vector<int> path(vertices + 1, -1);

    cost[vertices] = 0; // Cost to reach the sink is 0

    for (int i = vertices - 1; i >= 1; i--) {
        for (int j = i + 1; j <= vertices; j++) {
            if (graph[i][j] != 0 && cost[j] + graph[i][j] < cost[i]) {
                cost[i] = cost[j] + graph[i][j];
                path[i] = j;
            }
        }
    }

    // Print the minimum cost and path
    cout << "Minimum cost: " << cost[1] << endl;
    cout << "Path: ";
    int current = 1;
    while (current != -1) {
        cout << current << " ";
        current = path[current];
    }
    cout << endl;

    return cost[1];
}

int main() {
    int vertices, stages;

    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of stages: ";
    cin >> stages;

    vector<vector<int>> graph(vertices + 1, vector<int>(vertices + 1, 0));

    cout << "Enter the adjacency matrix (use 0 for no edge):" << endl;
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            cin >> graph[i][j];
        }
    }

    multistageGraph(graph, stages, vertices);

    return 0;
}

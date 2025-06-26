#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

// Function to find the minimum cost of the Traveling Salesperson Problem
int tsp(vector<vector<int>>& graph, int start, vector<bool>& visited, int current, int n, int count, int cost, int& minCost) {
    if (count == n && graph[current][start] > 0) {
        minCost = min(minCost, cost + graph[current][start]);
        return minCost;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[current][i] > 0) {
            visited[i] = true;
            tsp(graph, start, visited, i, n, count + 1, cost + graph[current][i], minCost);
            visited[i] = false;
        }
    }

    return minCost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the cost matrix (use 0 if no path exists):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<bool> visited(n, false);
    visited[0] = true; // Starting from the first city

    int minCost = INF;
    tsp(graph, 0, visited, 0, n, 1, 0, minCost);

    cout << "The minimum cost of the Traveling Salesperson Problem is: " << minCost << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Function to solve the Knapsack problem
int knapsack(int W, vector<int>& weights, vector<int>& profits, int n) {
    // Create a DP table to store the maximum profit for each weight limit
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Include the item or exclude it
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                // Exclude the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // The maximum profit for the given weight limit
}

// Main function
int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> profits(n), weights(n);

    cout << "Enter the profits of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    int maxProfit = knapsack(W, weights, profits, n);

    cout << "The maximum profit is: " << maxProfit << endl;

    return 0;
}

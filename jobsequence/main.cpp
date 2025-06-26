#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent a job
struct Job {
    int id;       // Job ID
    int profit;   // Profit of the job
    int deadline; // Deadline of the job
};

// Comparator function to sort jobs in descending order of profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to find the maximum profit job sequence
void jobScheduling(vector<Job>& jobs, int n) {
    // Step 1: Sort the jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), compare);

    // Step 2: Find the maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Step 3: Create a schedule array to track job slots (initialize with -1)
    vector<int> schedule(maxDeadline + 1, -1);

    int totalProfit = 0; // Track the total profit

    // Step 4: Iterate over the jobs and schedule them
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (schedule[j] == -1) { // If the slot is free
                schedule[j] = jobs[i].id; // Assign the job to this slot
                totalProfit += jobs[i].profit; // Add the profit
                break;
            }
        }
    }

    // Step 5: Display the scheduled jobs and total profit
    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (schedule[i] != -1) {
            cout << "J" << schedule[i] << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    // List of jobs (id, profit, deadline)
    vector<Job> jobs = {
        {1, 35, 3},
        {2, 30, 4},
        {3, 25, 4},
        {4, 20, 2},
        {5, 15, 3},
        {
            6,12,1
        },
        {
            7,5,2
        },
        {
            8,6,1
        }
    };

    int n = jobs.size();

    // Find the job sequence with maximum profit
    jobScheduling(jobs, n);

    return 0;
}

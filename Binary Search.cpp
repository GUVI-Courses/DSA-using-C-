#include <iostream>
using namespace std;

// Function to perform Binary Search
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index

        // Check if the target is at the middle
        if (arr[mid] == target) {
            return mid;
        }

        // If target is smaller, search in the left half
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // If target is larger, search in the right half
        else {
            left = mid + 1;
        }
    }

    return -1; // Return -1 if the target is not found
}

// Main function
int main() {
    int n, target;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search for: ";
    cin >> target;

    // Perform Binary Search
    int result = binarySearch(arr, n, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << "." << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}

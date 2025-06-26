#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Class to represent a Heap (Min or Max Heap)
class Heap {
private:
    vector<int> heap; // Stores the elements of the heap
    bool isMinHeap;   // Determines if the heap is a Min Heap or Max Heap

    // Function to get the parent index of a given index
    int parent(int i) { return (i - 1) / 2; }

    // Function to get the left child index of a given index
    int leftChild(int i) { return 2 * i + 1; }

    // Function to get the right child index of a given index
    int rightChild(int i) { return 2 * i + 2; }

    // Helper function to heapify down (used during deletion)
    void heapifyDown(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int smallestOrLargest = i;

        // Compare with left child
        if (isMinHeap) {
            if (left < heap.size() && heap[left] < heap[smallestOrLargest]) {
                smallestOrLargest = left;
            }
            // Compare with right child
            if (right < heap.size() && heap[right] < heap[smallestOrLargest]) {
                smallestOrLargest = right;
            }
        } else {
            if (left < heap.size() && heap[left] > heap[smallestOrLargest]) {
                smallestOrLargest = left;
            }
            // Compare with right child
            if (right < heap.size() && heap[right] > heap[smallestOrLargest]) {
                smallestOrLargest = right;
            }
        }

        // Swap and continue heapifying if root is not the smallest or largest
        if (smallestOrLargest != i) {
            swap(heap[i], heap[smallestOrLargest]);
            heapifyDown(smallestOrLargest);
        }
    }

    // Helper function to heapify up (used during insertion)
    void heapifyUp(int i) {
        while (i != 0 && ((isMinHeap && heap[i] < heap[parent(i)]) || (!isMinHeap && heap[i] > heap[parent(i)]))) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // Constructor
    Heap(bool isMinHeap = true) : isMinHeap(isMinHeap) {}

    // Function to insert an element into the heap
    void insert(int key) {
        heap.push_back(key); // Add the element to the end
        heapifyUp(heap.size() - 1); // Fix the heap property upwards
    }

    // Function to delete the root element of the heap
    int deleteRoot() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty!");
        }

        int root = heap[0]; // Store the root element
        heap[0] = heap.back(); // Move the last element to the root
        heap.pop_back(); // Remove the last element
        heapifyDown(0); // Fix the heap property downwards

        return root; // Return the removed root element
    }

    // Function to sort the elements using heap sort
    vector<int> heapSort() {
        vector<int> sortedHeap;
        while (!heap.empty()) {
            sortedHeap.push_back(deleteRoot());
        }

        if (!isMinHeap) {
            reverse(sortedHeap.begin(), sortedHeap.end()); // Reverse for descending order in Max Heap
        }
        return sortedHeap;
    }

    // Function to display the heap elements
    void display() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    // Min Heap Example
    cout << "Min Heap Operations:\n";
    Heap minHeap(true); // Create a Min Heap

    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(30);
    minHeap.insert(5);

    cout << "Min Heap after insertions: ";
    minHeap.display();

    cout << "Deleted root: " << minHeap.deleteRoot() << endl;
    cout << "Min Heap after deletion: ";
    minHeap.display();

    vector<int> sortedMinHeap = minHeap.heapSort();
    cout << "Heap Sort (Ascending Order): ";
    for (int val : sortedMinHeap) {
        cout << val << " ";
    }
    cout << endl;

    // Max Heap Example
    cout << "\nMax Heap Operations:\n";
    Heap maxHeap(false); // Create a Max Heap

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(5);

    cout << "Max Heap after insertions: ";
    maxHeap.display();

    cout << "Deleted root: " << maxHeap.deleteRoot() << endl;
    cout << "Max Heap after deletion: ";
    maxHeap.display();

    vector<int> sortedMaxHeap = maxHeap.heapSort();
    cout << "Heap Sort (Descending Order): ";
    for (int val : sortedMaxHeap) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

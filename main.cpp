#include <iostream>
using namespace std;

void displayArray(int arr[], int size) {
    // Function to display the elements of the array
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int& size, int capacity, int element, int position) {
    // Function to insert an element at a specific position
    if (size >= capacity) {
        cout << "Array is full. Cannot insert element." << endl;
        return;
    }
    if (position < 0 || position > size) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
    cout << "Element inserted successfully." << endl;
}

void deleteElement(int arr[], int& size, int position) {
    // Function to delete an element from a specific position
    if (position < 0 || position >= size) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element deleted successfully." << endl;
}

int searchElement(int arr[], int size, int element) {
    // Function to search for an element in the array
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i; // Return the index of the element
        }
    }
    return -1; // Return -1 if the element is not found
}

int main() {
    const int CAPACITY = 10; // Maximum capacity of the array
    int arr[CAPACITY] = {1, 2, 3, 4, 5}; // Initialize the array
    int size = 5; // Current size of the array

    int choice;
    do {
        cout << "\n--- Array Operations ---" << endl;
        cout << "1. Display Array" << endl;
        cout << "2. Insert Element" << endl;
        cout << "3. Delete Element" << endl;
        cout << "4. Search Element" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2: {
                int element, position;
                cout << "Enter the element to insert: ";
                cin >> element;
                cout << "Enter the position (0-based index): ";
                cin >> position;
                insertElement(arr, size, CAPACITY, element, position);
                break;
            }
            case 3: {
                int position;
                cout << "Enter the position of the element to delete (0-based index): ";
                cin >> position;
                deleteElement(arr, size, position);
                break;
            }
            case 4: {
                int element;
                cout << "Enter the element to search: ";
                cin >> element;
                int index = searchElement(arr, size, element);
                if (index != -1) {
                    cout << "Element found at index: " << index << endl;
                } else {
                    cout << "Element not found in the array." << endl;
                }
                break;
            }
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

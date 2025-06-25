#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;       // Pointer to hold the stack elements
    int topIndex;   // Index of the top element
    int capacity;   // Maximum capacity of the stack

public:
    // Constructor to initialize the stack
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];  // Dynamically allocate memory for the stack
        topIndex = -1;            // Initialize top to -1 (empty stack)
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return topIndex == capacity - 1;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++topIndex] = value; // Increment topIndex and add the element
        cout << "Pushed " << value << " onto the stack." << endl;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << "Popped " << arr[topIndex--] << " from the stack." << endl;
    }

    // Peek at the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack Underflow! No elements to peek." << endl;
            return -1; // Return an invalid value to indicate an error
        }
        return arr[topIndex];
    }

    // Display the elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size); // Create a stack with the given size

    int choice, value;
    do {
        cout << "\n--- Stack Operations ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                value = stack.peek();
                if (value != -1) {
                    cout << "Top element is: " << value << endl;
                }
                break;
            case 4:
                stack.display();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;        // Pointer to hold the queue elements
    int front;       // Index of the front element
    int rear;        // Index of the rear element
    int capacity;    // Maximum capacity of the queue
    int size;        // Current size of the queue

public:
    // Constructor to initialize the queue
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Enqueue operation: Add an element to the rear
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = value;
        size++;
        cout << "Enqueued " << value << " to the queue." << endl;
    }

    // Dequeue operation: Remove an element from the front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued " << arr[front] << " from the queue." << endl;
        front = (front + 1) % capacity; // Circular increment
        size--;
    }

    // Peek operation: Get the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue Underflow! No elements to peek." << endl;
            return -1; // Return an invalid value to indicate an error
        }
        return arr[front];
    }

    // Display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue queue(size); // Create a queue with the given size

    int choice, value;
    do {
        cout << "\n--- Queue Operations ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                value = queue.peek();
                if (value != -1) {
                    cout << "Front element is: " << value << endl;
                }
                break;
            case 4:
                queue.display();
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

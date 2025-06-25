#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;       // Data part
    Node* prev;     // Pointer to the previous node
    Node* next;     // Pointer to the next node
};

// Class to manage the doubly linked list
class DoublyLinkedList {
private:
    Node* head;     // Pointer to the head of the list
    Node* tail;     // Pointer to the tail of the list

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to insert an element at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode; // If the list was empty, set the new node as the tail
        }
        head = newNode;
        cout << "Inserted " << value << " at the beginning." << endl;
    }

    // Function to insert an element at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode; // If the list was empty, set the new node as the head
        }
        tail = newNode;
        cout << "Inserted " << value << " at the end." << endl;
    }


    // Function to insert an element at a specific position
void insertAtMiddle(int value, int position) {
    if (position <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Insert at the beginning if position is 1
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }

    Node* temp = head;
    int currentPosition = 1;

    // Traverse to the position before the desired one
    while (temp != nullptr && currentPosition < position - 1) {
        temp = temp->next;
        currentPosition++;
    }

    if (temp == nullptr) {
        cout << "Position is out of bounds." << endl;
        return;
    }

    // Create the new node
    Node* newNode = new Node();
    newNode->data = value;

    // Update the links
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    } else {
        tail = newNode; // Update tail if inserted at the end
    }

    temp->next = newNode;

    cout << "Inserted " << value << " at position " << position << "." << endl;
}


    // Function to delete an element
    void deleteElement(int value) {
        if (head == nullptr) { // List is empty
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;

        while (temp != nullptr && temp->data != value) { // Search for the node
            temp = temp->next;
        }

        if (temp == nullptr) { // Element not found
            cout << "Element " << value << " not found in the list." << endl;
            return;
        }

        // Update links to remove the node
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Update head if the first node is deleted
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Update tail if the last node is deleted
        }

        delete temp; // Free memory
        cout << "Deleted " << value << " from the list." << endl;
    }

    // Function to search for an element
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Function to display the list from head to tail
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "Doubly Linked List (Forward): ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to display the list from tail to head
    void displayBackward() {
        if (tail == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = tail;
        cout << "Doubly Linked List (Backward): ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }









};

int main() {
    DoublyLinkedList list;
    int choice, value;

    do {
    cout << "\n--- Doubly Linked List Operations ---" << endl;
    cout << "1. Insert at Beginning" << endl;
    cout << "2. Insert at End" << endl;
    cout << "3. Insert at Middle" << endl; // New option
    cout << "4. Delete an Element" << endl;
    cout << "5. Search for an Element" << endl;
    cout << "6. Display List Forward" << endl;
    cout << "7. Display List Backward" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter the value to insert at the beginning: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter the value to insert at the end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3: {
            int position;
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the position to insert at: ";
            cin >> position;
            list.insertAtMiddle(value, position);
            break;
        }
        case 4:
            cout << "Enter the value to delete: ";
            cin >> value;
            list.deleteElement(value);
            break;
        case 5:
            cout << "Enter the value to search: ";
            cin >> value;
            if (list.search(value)) {
                cout << "Element " << value << " is present in the list." << endl;
            } else {
                cout << "Element " << value << " is not found in the list." << endl;
            }
            break;
        case 6:
            list.displayForward();
            break;
        case 7:
            list.displayBackward();
            break;
        case 8:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
    }
} while (choice != 8);


    return 0;
}


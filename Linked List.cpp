#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;       // Data part
    Node* next;     // Pointer to the next node
};

// Class to manage the singly linked list
class SinglyLinkedList {
private:
    Node* head;     // Pointer to the head of the list

public:
    // Constructor to initialize an empty list
    SinglyLinkedList() {
        head = nullptr;
    }

    // Function to insert an element at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the beginning." << endl;
    }

    // Function to insert an element at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) { // If the list is empty
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at the end." << endl;
    }

    // Function to delete an element
    void deleteElement(int value) {
        if (head == nullptr) { // List is empty
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (head->data == value) { // Deleting the head node
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << value << " from the list." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != value) { // Searching for the node
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) { // Element not found
            cout << "Element " << value << " not found in the list." << endl;
            return;
        }

        // Deleting the node
        prev->next = temp->next;
        delete temp;
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

    // Function to display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value;

    do {
        cout << "\n--- Singly Linked List Operations ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete an Element" << endl;
        cout << "4. Search for an Element" << endl;
        cout << "5. Display List" << endl;
        cout << "6. Exit" << endl;
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
            case 3:
                cout << "Enter the value to delete: ";
                cin >> value;
                list.deleteElement(value);
                break;
            case 4:
                cout << "Enter the value to search: ";
                cin >> value;
                if (list.search(value)) {
                    cout << "Element " << value << " is present in the list." << endl;
                } else {
                    cout << "Element " << value << " is not found in the list." << endl;
                }
                break;
            case 5:
                list.display();
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

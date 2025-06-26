#include <iostream>
#include <vector>
using namespace std;


const int TABLE_SIZE = 10;

// Hash Table using Chaining
class HashTableChaining {
private:
    vector<int> table[TABLE_SIZE];

public:
    void insert(int key) {
        int hashIndex = key % TABLE_SIZE;
        table[hashIndex].push_back(key);
    }

    void remove(int key) {
        int hashIndex = key % TABLE_SIZE;
        for (auto it = table[hashIndex].begin(); it != table[hashIndex].end(); ++it) {
            if (*it == key) {
                table[hashIndex].erase(it);
                return;
            }
        }
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (int key : table[i])
                cout << key << " -> ";
            cout << "NULL" << endl;
        }
    }
};

// Hash Table using Linear Probing
class HashTableLinearProbing {
private:
    vector<int> table;
    vector<bool> occupied;

public:
    HashTableLinearProbing() : table(TABLE_SIZE, -1), occupied(TABLE_SIZE, false) {}

    void insert(int key) {
        int hashIndex = key % TABLE_SIZE;
        while (occupied[hashIndex]) {
            hashIndex = (hashIndex + 1) % TABLE_SIZE;
        }
        table[hashIndex] = key;
        occupied[hashIndex] = true;
    }

    void remove(int key) {
        int hashIndex = key % TABLE_SIZE;
        while (occupied[hashIndex]) {
            if (table[hashIndex] == key) {
                table[hashIndex] = -1;
                occupied[hashIndex] = false;
                return;
            }
            hashIndex = (hashIndex + 1) % TABLE_SIZE;
        }
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": " << (occupied[i] ? to_string(table[i]) : "NULL") << endl;
        }
    }
};

// Hash Table using Quadratic Probing
class HashTableQuadraticProbing {
private:
    vector<int> table;
    vector<bool> occupied;

public:
    HashTableQuadraticProbing() : table(TABLE_SIZE, -1), occupied(TABLE_SIZE, false) {}

    void insert(int key) {
        int hashIndex = key % TABLE_SIZE;
        int i = 0;
        while (occupied[(hashIndex + i * i) % TABLE_SIZE]) {
            i++;
        }
        hashIndex = (hashIndex + i * i) % TABLE_SIZE;
        table[hashIndex] = key;
        occupied[hashIndex] = true;
    }

    void remove(int key) {
        int hashIndex = key % TABLE_SIZE;
        int i = 0;
        while (occupied[(hashIndex + i * i) % TABLE_SIZE]) {
            if (table[(hashIndex + i * i) % TABLE_SIZE] == key) {
                table[(hashIndex + i * i) % TABLE_SIZE] = -1;
                occupied[(hashIndex + i * i) % TABLE_SIZE] = false;
                return;
            }
            i++;
        }
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": " << (occupied[i] ? to_string(table[i]) : "NULL") << endl;
        }
    }
};

int main() {
    cout << "Hashing with Chaining:\n";
    HashTableChaining hashTableChaining;
    hashTableChaining.insert(10);
    hashTableChaining.insert(20);
    hashTableChaining.insert(15);
    hashTableChaining.insert(25);
    hashTableChaining.display();

    cout << "\nHashing with Linear Probing:\n";
    HashTableLinearProbing hashTableLinear;
    hashTableLinear.insert(10);
    hashTableLinear.insert(20);
    hashTableLinear.insert(15);
    hashTableLinear.insert(25);
    hashTableLinear.display();

    cout << "\nHashing with Quadratic Probing:\n";
    HashTableQuadraticProbing hashTableQuadratic;
    hashTableQuadratic.insert(10);
    hashTableQuadratic.insert(20);
    hashTableQuadratic.insert(15);
    hashTableQuadratic.insert(25);
    hashTableQuadratic.display();

    return 0;
}

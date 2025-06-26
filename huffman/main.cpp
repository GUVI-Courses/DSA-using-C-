#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure for Huffman tree
struct Node {
    char ch; // Character
    int freq; // Frequency of the character
    Node* left; // Left child in the Huffman tree
    Node* right; // Right child in the Huffman tree

    // Constructor to initialize the node
    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue (min-heap based on frequency)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Recursive function to build the Huffman codes
void buildHuffmanCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return; // Base case: null node

    // If the node is a leaf (contains a character)
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code; // Store the code for the character
    }

    // Recur for the left subtree with code "0"
    buildHuffmanCodes(root->left, code + "0", huffmanCodes);

    // Recur for the right subtree with code "1"
    buildHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Function to build the Huffman Tree and generate codes
void huffmanCoding(const string& text) {
    // Step 1: Calculate frequencies of characters
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++; // Increment frequency count for each character
    }

    // Step 2: Build the priority queue (min-heap)
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second)); // Push each character and its frequency into the queue
    }

    // Step 3: Build the Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop(); // Extract the node with the smallest frequency
        Node* right = pq.top(); pq.pop(); // Extract the next smallest frequency

        // Create a new internal node with combined frequency
        Node* combined = new Node('\0', left->freq + right->freq);
        combined->left = left; // Set left child
        combined->right = right; // Set right child
        pq.push(combined); // Push the new node back into the queue
    }

    Node* root = pq.top(); // The root of the Huffman Tree

    // Step 4: Generate Huffman codes
    unordered_map<char, string> huffmanCodes;
    buildHuffmanCodes(root, "", huffmanCodes);

    // Step 5: Display the codes
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Step 6: Encode the input string
    string encodedString;
    for (char ch : text) {
        encodedString += huffmanCodes[ch]; // Append the Huffman code for each character
    }
    cout << "\nEncoded String: " << encodedString << endl;

    // Step 7: Calculate bit savings
    int originalBits = text.size() * 8; // Assuming 8 bits per character
    int compressedBits = encodedString.size(); // Compressed bits based on Huffman codes
    cout << "\nOriginal Bits: " << originalBits << endl;
    cout << "Compressed Bits: " << compressedBits << endl;
    cout << "Bits Saved: " << originalBits - compressedBits << endl;
}

int main() {
    // Input text to be encoded
    string text = "BCCABBDDAECCBBAEDDCC";

    cout << "Input Text: " << text << endl; // Display input text
    huffmanCoding(text); // Perform Huffman coding

    return 0;
}

#include <iostream>
using namespace std;

// Define a Node structure for the AVL tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

// Utility function to get the height of a node
int height(Node* node) {
    return node ? node->height : 0;
}

// Utility function to get the balance factor of a node
int getBalanceFactor(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Right rotation
Node* rightRotate(Node* y) {
    /*
        A right rotation is performed to rebalance the AVL tree when a left-heavy imbalance is detected.
        It involves rotating the subtree rooted at 'y' to the right, such that 'x' (the left child of 'y') becomes the new root of this subtree.

        Steps:
        1. Let 'x' be the left child of 'y'.
        2. Save the right subtree of 'x' (T2) temporarily.
        3. Make 'y' the right child of 'x'.
        4. Assign T2 as the left child of 'y'.
        5. Update the heights of 'y' and 'x'.
        6. Return 'x' as the new root of the subtree.

        This operation ensures that the balance factor for the subtree is within the allowed range (-1, 0, 1).
    */
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // Return the new root
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // Return the new root
}

// Insert a key into the AVL tree
Node* insert(Node* node, int key) {
    // Perform the normal BST insertion
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicates are not allowed

    // Update the height of the ancestor node
    node->height = max(height(node->left), height(node->right)) + 1;

    // Get the balance factor to check whether the node became unbalanced
    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // Return the (unchanged) node pointer
}

// Utility function to find the node with the smallest key value
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Delete a node from the AVL tree
Node* deleteNode(Node* root, int key) {
    // Perform the normal BST deletion
    if (!root) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one child or no child
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;

            if (!temp) { // No child
                temp = root;
                root = nullptr;
            } else { // One child
                *root = *temp;
            }

            delete temp;
        } else {
            // Node with two children
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's key
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node
    if (!root) return root;

    // Update the height of the current node
    root->height = max(height(root->left), height(root->right)) + 1;

    // Get the balance factor
    int balance = getBalanceFactor(root);

    // Balance the tree

    // Left Left Case
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// In-order traversal
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Insert nodes
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 30);
    root = insert(root, 22);
    root = insert(root, 50);

    cout << "In-order traversal of the AVL tree: ";
    inOrder(root);
    cout << endl;

    // Delete a node
    root = deleteNode(root, 40);

    cout << "In-order traversal after deletion: ";
    inOrder(root);
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        left = right = nullptr;
    }
};


Node* findMin(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}


Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return nullptr;

    // Step 1: Search the node
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        // Node found

        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children (IMPORTANT)
        else {
            // Get inorder successor
            Node* successor = findMin(root->right);

            // Replace value
            root->key = successor->key;

            // Delete successor
            root->right = deleteNode(root->right, successor->key);
        }
    }

    return root;
}

Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}
int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder before deletion:\n";
    inorder(root);

    // Delete node with TWO children
    root = deleteNode(root, 50);

    cout << "\nInorder after deletion:\n";
    inorder(root);

    return 0;
}
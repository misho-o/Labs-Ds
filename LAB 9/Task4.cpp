#include <iostream>
using namespace std;

class Node {
public:
    string value;
    bool isQuestion;   // true = question, false = diagnosis
    Node* left;
    Node* right;

    Node(string val, bool q = true) {
        value = val;
        isQuestion = q;
        left = right = nullptr;
    }
};

Node* buildTree() {
    // Root question
    Node* root = new Node("Do you have fever?");

    // Level 1
    root->left = new Node("Do you have cough?");       // YES branch
    root->right = new Node("Do you have headache?");   // NO branch

    // Level 2 (Leaf nodes = diagnoses)
    root->left->left = new Node("Flu", false);
    root->left->right = new Node("Common Cold", false);

    root->right->left = new Node("Migraine", false);
    root->right->right = new Node("Healthy", false);

    return root;
}


void preorder(Node* root) {
    if (root == nullptr) return;

    // Visit node
    if (root->isQuestion)
        cout << "Q: " << root->value << endl;
    else
        cout << "Diagnosis: " << root->value << endl;

    // Left → YES
    preorder(root->left);

    // Right → NO
    preorder(root->right);
}


int main() {
    Node* root = buildTree();

    cout << "Pre-order Traversal:\n";
    preorder(root);

    return 0;
}
/******************************************************************************
Question #2
Scenario: A modern file system organizes directories such that every level of the storage hierarchy
is fully filled, except possibly the last level, which is filled from left to right to maintain a Complete
Binary Tree structure.
 Task: Implement a Complete Binary Tree to represent this file system. Use a Post-order
Traversal (traversing left child, then right child, then the parent) to calculate the total storage
space used by a directory and its sub-directories.
 Average Complexity: O(n) for visiting all nodes in the tree.
*******************************************************************************/
#include <iostream>
using namespace std;

struct File {
    int fileSize;

    File(int fileSize = 0) {
        this->fileSize = fileSize;
    }
};

struct node {
    File file;
    node* left;
    node* right;

    node(File file) {
        this->file = file;
        left = right = NULL;
    }
};

class Queue {
    node** q;
    int size;
    int maxSize;

public:
    Queue(int maxSize) {
        this->maxSize = maxSize;
        q = new node*[maxSize];
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(node* n) {
        if (size == maxSize) return;
        q[size++] = n;
    }

    void dequeue() {
        for (int i = 0; i < size - 1; i++) {
            q[i] = q[i + 1];
        }
        size--;
    }

    node* getFront() {
        return q[0];
    }
};

// COMPLETE BINARY TREE INSERT
node* insert(node* root, File file) {
    if (root == NULL)
        return new node(file);

    Queue q(100);
    q.enqueue(root);

    while (!q.isEmpty()) {
        node* temp = q.getFront();
        q.dequeue();

        if (temp->left == NULL) {
            temp->left = new node(file);
            return root;
        } else {
            q.enqueue(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = new node(file);
            return root;
        } else {
            q.enqueue(temp->right);
        }
    }
    return root;
}

// POSTORDER SUM
int totalSize(node* root) {
    if (root == NULL)
        return 0;

    int left = totalSize(root->left);
    int right = totalSize(root->right);

    return left + right + root->file.fileSize;
}

// OPTIONAL: POSTORDER PRINT
void postorder(node* root) {
    if (!root) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->file.fileSize << " ";
}

int main() {
    node* root = NULL;

    root = insert(root, File(10));
    root = insert(root, File(20));
    root = insert(root, File(30));
    root = insert(root, File(40));

    cout << "Postorder: ";
    postorder(root);

    cout << "\nTotal Storage: " << totalSize(root);

    return 0;
}
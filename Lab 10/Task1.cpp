#include <iostream>
using namespace std;

struct node {
    int value;
    node* left;
    node* right;

    node(int v) {
        value = v;
        left = right = NULL;
    }
};

// BST INSERT
node* insert(node* root, int data) {
    if (!root) return new node(data);

    if (data < root->value)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

// HEIGHT (for comparison)
int height(node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// LINKED LIST
struct ListNode {
    int value;
    ListNode* next;

    ListNode(int v) {
        value = v;
        next = NULL;
    }
};

// INSERT INTO LIST (at end)
void append(ListNode*& head, int value) {
    if (!head) {
        head = new ListNode(value);
        return;
    }
    ListNode* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new ListNode(value);
}

// STEP 1: INORDER → LIST
void inorderToList(node* root, ListNode*& head) {
    if (!root) return;

    inorderToList(root->left, head);
    append(head, root->value);
    inorderToList(root->right, head);
}

// COUNT NODES IN LIST
int countNodes(ListNode* head) {
    int c = 0;
    while (head) {
        c++;
        head = head->next;
    }
    return c;
}

// STEP 2: BUILD BALANCED BST FROM LIST
node* buildBalanced(ListNode*& head, int n) {
    if (n <= 0) return NULL;

    // left subtree
    node* left = buildBalanced(head, n / 2);

    // root
    node* root = new node(head->value);
    root->left = left;

    // move list forward
    head = head->next;

    // right subtree
    root->right = buildBalanced(head, n - n/2 - 1);

    return root;
}

// PRINT INORDER (for checking)
void inorder(node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

int main() {
    node* root = NULL;

    // Skewed BST
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    cout << "Height BEFORE: " << height(root) << endl;

    // Step 1
    ListNode* head = NULL;
    inorderToList(root, head);

    // Step 2
    int n = countNodes(head);
    node* newRoot = buildBalanced(head, n);

    cout << "Height AFTER: " << height(newRoot) << endl;

    cout << "Inorder of balanced BST: ";
    inorder(newRoot);

    return 0;
}
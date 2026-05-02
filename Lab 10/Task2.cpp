
/******************************************************************************
Question # 02
Scenario: You are developing software for a temperature sensor that inserts data every second.
Sometimes the data arrives in strictly increasing or decreasing order, which would normally create a
&quot;tall and skinny&quot; tree. Lab Task:
1. Implement the leftRotate and rightRotate functions as defined in the source.
2. Create a test script that inserts the sequence {30, 35, 45} and {13, 10, 5}.
3. Your code must detect the specific imbalance (Right-Right or Left-Left) and automatically
call the correct rotation function to return a balanced root.
******************************************************************************/






#include <iostream>
using namespace std;

struct node {
    int value;
    int height;
    node* left;
    node* right;

    node(int v) {
        value = v;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(node* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(getHeight(root->left),getHeight(root->right));
}

node* rightRotate(node* root){
    node* child = root->left;
    node* childRight = child->right;
    
    child->right=root;
    root->left = childRight;
    
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    child->height = 1+max(getHeight(child->left),getHeight(child->right));
    
    return child;
}
node* leftRotate(node* root){
    node* child = root->right;
    node* childLeft = child->left;
    
    child->left = root;
    root->right = childLeft;
    
    root->height = 1+max(getHeight(root->left),getHeight(root->right));
    child->height = 1+max(getHeight(child->left),getHeight(child->right));
    
    return child;
}



void inorder(node* root){
    
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}
node* insert(node* root,int data){
    
    if(root==NULL){
        return new node(data);
    }
    
    if(data<root->value){
        root->left = insert(root->left,data);
    }
    
    else if(data>root->value){
        root->right = insert(root->right,data);
    }
    
    int balance = getHeight(root->left)-getHeight(root->right);
    
    //Left right imbalance
    if(balance>1&&data>root->left->value){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //left left
    else if(balance>1&&data<root->left->value){
        return rightRotate(root);
    }
    //right right imbalance
    else if(balance<-1&&data>root->right->value){
        return leftRotate(root);
    }
    //right left imbalance
    else if(balance<-1&&data<root->right->value){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}


int main() {
    node* root= NULL;
    // Skewed BST
    root = insert(root, 30);
    root = insert(root, 35);
    root = insert(root, 45);
    root = insert(root, 13);
    root = insert(root, 10);
    root = insert(root, 5);

    inorder(root);

    return 0;
}
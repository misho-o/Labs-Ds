
/******************************************************************************
Scenario: You are building a digital dictionary. Inserting certain word combinations creates a
&quot;double imbalance&quot; where a node&#39;s child is heavy on the opposite side of the parent&#39;s imbalance.
Lab Task:
1. Implement the insert function to handle the Left-Right (LR) and Right-Left (RL) cases.
2. Using the manual’s logic, write code that first performs a rotation on the child node and then
a second rotation on the original unbalanced node.
3. Verify the balance by inserting the sequence {13, 10, 11} and ensure the final root is 11.
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
    root = insert(root, 13);
    root = insert(root, 10);
    root = insert(root, 11);
    

    inorder(root);
    cout<<root->value;
    return 0;
}
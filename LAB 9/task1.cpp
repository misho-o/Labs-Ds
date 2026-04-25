/******************************************************************************
Scenario: A software company is developing a digital phonebook that needs to store and retrieve
contact names efficiently. You are tasked with implementing a Binary Search Tree where each
node contains a contact name (string) as its key.
 Task: Write a function to search for a specific name in the BST. Ensure that the search
follows the property where names &quot;lesser&quot; than the root are searched in the left subtree and
those &quot;greater&quot; are searched in the right.
*******************************************************************************/

#include <iostream>
using namespace std;

struct node{
    string data;
    node* left;
    node* right;
    
    public:
    node(string data){
        this->data=data;
        left = right = NULL;
    }
};

node* insertBinaryTree(node* root,string data){
    if(root == NULL){
        return new node(data);
    }
    
    if(root->data > data){
        //go to left subtree
        root->left = insertBinaryTree(root->left,data);
    }
    
    if(root->data < data){
        //go to right subtree
        root->right = insertBinaryTree(root->right,data);
    }
    
    return root;
}

node* search(node* root,string data){
    if(root == NULL){
        cout<<"node not found for "<<data;

        return root;
    }
    if(root->data == data){
        cout<<"found node for "<<data;
        return root;
    }
    if(data< root->data){
        //search recurively in left
        return search(root->left,data);
    }
    if(data > root->data){
        return search(root->right,data);
    }
    
    //otherwise no nodefound
    return root;
}
int main()
{
    node* root = new node("Ahmed");
    root = insertBinaryTree(root,"Jawed");
    root = insertBinaryTree(root,"Laiba");
    node* n = search(root,"Laiba");
    cout<<n->data;
    return 0;
}
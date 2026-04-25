/******************************************************************************

Scenario: You are building an auto-complete feature for a search engine. Words are added to a
dictionary as users type them.
 Task: Implement a BST Insertion function that adds new words to the dictionary while
maintaining the BST property: the left subtree must have keys less than or equal to the
parent, and the right subtree must have keys greater than or equal to the parent.
*******************************************************************************/

#include <iostream>

node* addWordToDict(node* root,string data){
    if(root == NULL){
        return new node(data);
    }
    
    if(root->data > data){
        //go to left subtree
        root->left = addWordToDict(root->left,data);
    }
    
    if(root->data < data){
        //go to right subtree
        root->right = addWordToDict(root->right,data);
    }
    
    return root;
}

int main()
{
    node* root = new node("Hibiscus");
    root = insertBinaryTree(root,"Contrary");
    root = insertBinaryTree(root,"Significant");
    
    return 0;
}
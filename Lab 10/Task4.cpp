
/******************************************************************************
Scenario: You need to verify if an AVL tree implementation is truly maintaining its balance
property after a series of complex operations. Lab Task:
1. Implement a Queue class using a linked list as shown in the source.
2. Write a printLevelOrder(Node* root) function that uses this queue to traverse the tree
breadth-first.
3. Task: Perform five insertions and two deletions, then use your printLevelOrder function to
output the tree. The output must prove that the height difference between any two subtrees
remains &lt;1.
******************************************************************************/

#include <iostream>
using namespace std;

struct node {
    int value;
    int height;
    node* left;
    node* right;

    node(int value) {
        this->value = value;
        height = 1;
        left = right = NULL;
    }
};

struct Linknode{
    public:
    node* data;
    Linknode* next;
    
    Linknode(node* data){
        this->data = data;
        next = NULL;
    }
};
//insert ar rear remove from front
struct queue{
    public:
    Linknode* front;
    Linknode* rear;
    
    queue(){
        front = rear = NULL;
    }
    
    void enqueue(node* data){
        Linknode* temp = new Linknode(data);
        
        if(front == NULL){
            front = rear= temp;
            return;
        }
        
        rear->next = temp;
        rear = temp;
        
    }
    bool isEmpty(){
        if(front == NULL){
            return true;
        }
        return false;
    }
    
    node* dequeue(){
        
        if(isEmpty()){
            cout<<"nothing to dequeue"<<endl;
            return NULL;
            
        }
        Linknode* temp = front;
        
        front = temp->next;
        if (front == NULL) rear = NULL;
        node* v = temp->data;
        delete temp;
        
        return v;
    }
};

void printLevelOrder(node* root){
    if(root == NULL) return;

    queue q1;
    q1.enqueue(root);
    
    while(!q1.isEmpty()){
        
        node* r = q1.dequeue();
        cout<<r->value<<endl;
        if(r->left){q1.enqueue(r->left);}
        if(r->left){q1.enqueue(r->right);}
        
    }
}


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
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
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
    
    printLevelOrder(root);
    inorder(root);
    cout<<root->value;
    return 0;
}
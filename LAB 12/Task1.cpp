/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

struct node{
    string data;
    node* next;
    int height;
    
    public:
    node(string data){
        height = 1;
        this->data = data;
        next = NULL;
    }
};

class HashTable{
    int size;
    node** table;
    
    public:
    HashTable(int size){
        this->size = size;
        table = new node*[size];
        for(int i = 0;i<size;i++){
           table[i] = NULL; 
        }
    
    }
    int hashFun(string s) {
        int hash = 0;
        for (char c : s) {
            hash += c;   // ASCII value
        }
        return hash%size;
    }
    int checkHeight(node* n){
        if(n==NULL){
            return 0;
        }
        return 1+checkHeight(n->next);
    }
    void insert(string key){
        int index = hashFun(key);
        cout<<"table height"<<checkHeight(table[index])<<endl;
        
        if(checkHeight(table[index])>=5){
            cout<<"Table has excedeed max height"<<endl;
            return;
        }
        //insert at head 
        
        node* newNode = new node(key);
        newNode->next = table[index];
        table[index]= newNode;
        cout<<key<<" inserted at index: "<<index<<endl;
        return;
    }
    
    void print(){
        
        node* temp;
        for(int i =0;i<size;i++){
            temp = table[i];
            cout<<"at index "<<i<<endl;
            while(temp!=NULL){
                cout<<temp->data<<"->";
                
                temp= temp->next;
            }
            cout<<"\n";
        }
    }
    
};
int main()
{
    HashTable h1(10);
    h1.insert("#SAYNOTOSLAVERY");
    h1.insert("#IMAMURDERER");
    h1.insert("#I_LOVE_PASTA");
    h1.insert("#I_LOVE_PASTA");
    h1.insert("#I_LOVE_PASTA");
    h1.insert("#I_LOVE_PASTA");
    h1.insert("#I_LOVE_PASTA");
    
    h1.insert("#I_LOVE_PASTA");
    h1.insert("SLAAAAAAA");
    h1.print();
    return 0;
}
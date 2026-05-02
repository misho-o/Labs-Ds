/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;


class MaxHeap{
    int* arr;
    int maxSize;
    int size;
    
    public:
    MaxHeap(int maxSize){
        this->maxSize = maxSize;
        arr = new int[maxSize];
        size = 0;
        
    }
    //heapify up
    void insert(int value){
        if(size==maxSize){
            cout<<"heap reached maxSize";
            return;
        }
        
        //check
        arr[size] = value;
        int index = size;
        size++;
        
        while(index>0&&arr[index]>arr[(index-1)/2]){
            swap(arr[index],arr[(index-1)/2]);
            index = (index-1)/2;
        }
        
        cout<<arr[index]<<" is inserted to heap"<<endl;

        
    }
    
    void print(){
        for(int i =0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    
        return;
    }
    
    
    void del(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        cout<<arr[0]<<" deleted"<<endl;
        arr[0] = arr[size-1];
        
        size--;
        
        heapify(0);
        
    }
    
    void heapify(int index){
        
        int left= index*2+1;
        int right= index*2+2;
        int largest = index;
        
        if(left<size&&arr[left]>arr[largest]){
            largest = left;
        }
        
        
        else if(right<size&&arr[right]>arr[largest]){
            largest = right;
        }
        
        if(index != largest){
            swap(arr[index],arr[largest]);

            heapify(largest);
        }
        
    }
};
int main()
{
    MaxHeap h1(8);
    h1.insert(12);
    h1.insert(542);
    h1.insert(21);
    h1.insert(412);
    h1.insert(524);
    h1.del();
    h1.insert(923);
    h1.insert(21);
    h1.insert(12);
    h1.del();

    h1.print();
    return 0;
}
#include <iostream>
using namespace std;

class Box {
private:
    int *value;

public:
    // Constructor
    Box(int v = 0) {
        value = new int(v);
    }

    // Copy Constructor (DEEP COPY)
    Box(const Box &obj) {
        value = new int(*obj.value);
    }

    // Copy Assignment Operator (DEEP COPY)
    Box& operator=(const Box &obj) {
        if (this != &obj) {
            delete value;               // free old memory
            value = new int(*obj.value);
        }
        return *this;
    }

    // Set value
    void setValue(int v) {
        *value = v;
    }

    // Display value
    void display() {
        cout << "Value: " << *value << endl;
    }

    // Destructor
    ~Box() {
        delete value;
    }
};

int main() {

    cout << "=== Creating Box A ===\n";
    Box a(10);
    a.display();

    cout << "\n=== Copy Constructor (Box B = A) ===\n";
    Box b = a;
    b.display();

    cout << "\nModify B to 50\n";
    b.setValue(50);

    cout << "A (should remain unchanged): ";
    a.display();

    cout << "B (changed): ";
    b.display();

    cout << "\n=== Copy Assignment Operator (Box C) ===\n";
    Box c;
    c = a;

    cout << "C before change: ";
    c.display();

    cout << "\nModify C to 99\n";
    c.setValue(99);

    cout << "A (unchanged): ";
    a.display();

    cout << "C (changed): ";
    c.display();

    return 0;
}
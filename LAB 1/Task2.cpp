#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char *name;
    char *date;
    int score;

public:
    // Constructor (DMA allocation)
    Exam(const char *n, const char *d, int s) {
        name = new char[strlen(n) + 1];
        date = new char[strlen(d) + 1];

        strcpy(name, n);
        strcpy(date, d);

        score = s;
    }

    // Set function
    void setData(const char *n, const char *d, int s) {
        strcpy(name, n);
        strcpy(date, d);
        score = s;
    }

    // Display function
    void display() {
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Score: " << score << endl;
    }

    // Destructor
    ~Exam() {
        delete[] name;
        delete[] date;
    }
};

int main() {

    // Original object
    Exam e1("Ali", "2026-04-30", 85);

    cout << "Original Exam Object:\n";
    e1.display();

    // Shallow copy (DEFAULT COPY CONSTRUCTOR USED)
    Exam e2 = e1;

    cout << "\nCopied Exam Object (Before change):\n";
    e2.display();

    // Modify copied object
    e2.setData("Ahmed", "2026-05-01", 95);

    cout << "\nAfter modifying copy:\n";

    cout << "Original Object:\n";
    e1.display();   // ❌ Problem occurs here

    cout << "\nCopied Object:\n";
    e2.display();

    return 0;
}
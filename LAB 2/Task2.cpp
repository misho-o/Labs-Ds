#include <iostream>
using namespace std;

int main() {
    int students = 5, subjects = 4;

    // Dynamic 2D array
    int **marks = new int*[students];
    for (int i = 0; i < students; i++) {
        marks[i] = new int[subjects];
    }

    // Input marks
    cout << "Enter marks for 5 students in 4 subjects:\n";
    for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << ":\n";
        for (int j = 0; j < subjects; j++) {
            cin >> marks[i][j];
        }
    }

    // 1. Total marks of each student
    int total[5] = {0};

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            total[i] += marks[i][j];
        }
    }

    // 2. Average marks of each subject
    float avg[4] = {0};

    for (int j = 0; j < subjects; j++) {
        int sum = 0;
        for (int i = 0; i < students; i++) {
            sum += marks[i][j];
        }
        avg[j] = sum / 5.0;
    }

    // 3. Find topper
    int topperIndex = 0;
    for (int i = 1; i < students; i++) {
        if (total[i] > total[topperIndex]) {
            topperIndex = i;
        }
    }

    // OUTPUT SECTION
    cout << "\n--- TOTAL MARKS ---\n";
    for (int i = 0; i < students; i++) {
        cout << "Student " << i + 1 << ": " << total[i] << endl;
    }

    cout << "\n--- AVERAGE MARKS (SUBJECT WISE) ---\n";
    for (int j = 0; j < subjects; j++) {
        cout << "Subject " << j + 1 << ": " << avg[j] << endl;
    }

    cout << "\n--- TOPPER ---\n";
    cout << "Student " << topperIndex + 1 
         << " with total marks: " << total[topperIndex] << endl;

    // Memory deallocation
    for (int i = 0; i < students; i++) {
        delete[] marks[i];
    }
    delete[] marks;

    return 0;
}
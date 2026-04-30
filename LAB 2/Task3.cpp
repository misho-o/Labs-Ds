#include <iostream>
using namespace std;

int main() {
    int departments;

    cout << "Enter number of departments: ";
    cin >> departments;

    // Step 1: Create dynamic array for departments
    int ***marks = new int**[departments];
    int *students = new int[departments];

    // Input data
    for (int d = 0; d < departments; d++) {
        cout << "\nEnter number of students in Department " << d + 1 << ": ";
        cin >> students[d];

        // each department -> students
        marks[d] = new int*[students[d]];

        for (int s = 0; s < students[d]; s++) {
            marks[d][s] = new int[5]; // 5 subjects

            cout << "Enter marks for Student " << s + 1 << " (5 subjects): ";
            for (int sub = 0; sub < 5; sub++) {
                cin >> marks[d][s][sub];
            }
        }
    }

    cout << "\n===== DEPARTMENT ANALYSIS =====\n";

    // Step 2: Process each department
    for (int d = 0; d < departments; d++) {

        int totalSum = 0;
        int count = 0;

        int highest = -1;
        int lowest = 999999;

        for (int s = 0; s < students[d]; s++) {

            int studentTotal = 0;

            for (int sub = 0; sub < 5; sub++) {
                studentTotal += marks[d][s][sub];
            }

            // update department stats
            totalSum += studentTotal;
            count++;

            if (studentTotal > highest)
                highest = studentTotal;

            if (studentTotal < lowest)
                lowest = studentTotal;
        }

        float avg = (count == 0) ? 0 : (float)totalSum / count;

        cout << "\nDepartment " << d + 1 << " Results:\n";
        cout << "Highest Marks: " << highest << endl;
        cout << "Lowest Marks: " << lowest << endl;
        cout << "Average Marks: " << avg << endl;
    }

    // Step 3: Free memory
    for (int d = 0; d < departments; d++) {
        for (int s = 0; s < students[d]; s++) {
            delete[] marks[d][s];
        }
        delete[] marks[d];
    }
    delete[] marks;
    delete[] students;

    return 0;
}
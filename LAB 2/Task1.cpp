#include <iostream>
using namespace std;

class DynamicMatrix {
private:
    int **mat;
    int rows, cols;

public:
    // Constructor: Create matrix
    DynamicMatrix(int r, int c, int initValue = 0) {
        rows = r;
        cols = c;

        mat = new int*[rows];
        for (int i = 0; i < rows; i++) {
            mat[i] = new int[cols];
        }

        // initialize
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = initValue;
            }
        }
    }

    // Print matrix
    void print() {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Resize matrix
    void resize(int newR, int newC, int fillValue = 0) {
        int **newMat = new int*[newR];

        for (int i = 0; i < newR; i++) {
            newMat[i] = new int[newC];
        }

        // copy old values
        for (int i = 0; i < newR; i++) {
            for (int j = 0; j < newC; j++) {
                if (i < rows && j < cols)
                    newMat[i][j] = mat[i][j];
                else
                    newMat[i][j] = fillValue;
            }
        }

        // delete old matrix
        for (int i = 0; i < rows; i++) {
            delete[] mat[i];
        }
        delete[] mat;

        mat = newMat;
        rows = newR;
        cols = newC;
    }

    // Transpose matrix
    void transpose() {
        int **newMat = new int*[cols];

        for (int i = 0; i < cols; i++) {
            newMat[i] = new int[rows];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                newMat[j][i] = mat[i][j];
            }
        }

        // delete old
        for (int i = 0; i < rows; i++) {
            delete[] mat[i];
        }
        delete[] mat;

        mat = newMat;
        swap(rows, cols);
    }

    // Add 2 to odd indices (1D indexing)
    void addToOddIndices() {
        int index = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (index % 2 == 1) {
                    mat[i][j] += 2;
                }
                index++;
            }
        }
    }

    // Destructor
    ~DynamicMatrix() {
        for (int i = 0; i < rows; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }
};

// ---------------- MAIN ----------------
int main() {
    DynamicMatrix m(3, 3, 1);

    cout << "Initial Matrix:\n";
    m.print();

    cout << "\nAfter adding 2 to odd indices:\n";
    m.addToOddIndices();
    m.print();

    cout << "\nAfter resizing (4x5):\n";
    m.resize(4, 5, 0);
    m.print();

    cout << "\nAfter transpose:\n";
    m.transpose();
    m.print();

    return 0;
}
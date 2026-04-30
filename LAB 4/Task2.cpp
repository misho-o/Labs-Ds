#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key, int &comp) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        comp++;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int interpolationSearch(int arr[], int n, int key, int &comp) {
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        comp++;

        if (low == high) {
            if (arr[low] == key)
                return low;
            return -1;
        }

        int pos = low + ((key - arr[low]) * (high - low)) /
                         (arr[high] - arr[low]);

        comp++;

        if (arr[pos] == key)
            return pos;
        else if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {5,10,15,20,25,30,35,40,45,50};
    int n = 10;
    int key = 45;

    int comp1 = 0, comp2 = 0;

    int bResult = binarySearch(arr, n, key, comp1);
    int iResult = interpolationSearch(arr, n, key, comp2);

    cout << "Binary Search Index: " << bResult << endl;
    cout << "Binary Comparisons: " << comp1 << endl;

    cout << "Interpolation Search Index: " << iResult << endl;
    cout << "Interpolation Comparisons: " << comp2 << endl;

    return 0;
}
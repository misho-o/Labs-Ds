#include <iostream>
#include <vector>
using namespace std;

struct File {
    int size; // in KB
};

struct Folder {
    vector<File> files;
    vector<Folder> subfolders;
};
int getFolderSize(Folder f) {
    int totalSize = 0;

    // Add sizes of files in current folder
    for (int i = 0; i < f.files.size(); i++) {
        totalSize += f.files[i].size;
    }

    // Recursively add sizes of subfolders
    for (int i = 0; i < f.subfolders.size(); i++) {
        totalSize += getFolderSize(f.subfolders[i]);
    }

    return totalSize;
}

int main() {
    Folder root;

    // Root files
    root.files.push_back({10});
    root.files.push_back({20});

    // Subfolder A
    Folder subA;
    subA.files.push_back({5});
    subA.files.push_back({15});

    // Subfolder B
    Folder subB;
    subB.files.push_back({25});

    // Add subfolders to root
    root.subfolders.push_back(subA);
    root.subfolders.push_back(subB);

    cout << "Total Folder Size: " << getFolderSize(root) << " KB";

    return 0;
}

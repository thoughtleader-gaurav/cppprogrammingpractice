#include <iostream>
#include <algorithm>
using namespace std;

void printV1(const std::string& arrayName, const int* a, int size) {
    cout << "[Version 1] The contents of " << arrayName << " are:";
    for (int i = 0; i < size; ++i) {
        cout << " " << a[i];
    }
    cout << endl;
}

void printV2(const std::string& arrayName, int(&a)[5]) {
    cout << "[Version 2] The contents of " << arrayName << " are:";
    for (int& item : a) {
        cout << " " << item;
    }
    cout << endl;
}



int main() {
    // 1. Initialize
    int a0[5];
    int a1[5] = { 1, 2, 3 };  // other element will be set as the default value
    // 2. Get Length
    int size0 = sizeof(a0) / sizeof(a0[0]);
    cout << "The size of a0 is: " << size0 << endl;
    int size = sizeof(a1) / sizeof(*a1);
    cout << "The size of a1 is: " << size << endl;
    // 3. Access Element
    cout << "The first element is: " << a1[0] << endl;
    // 4. Iterate all Elements
    printV1("a1", a1, size);
    printV2("a1", a1);
    // 5. Modify Element
    cout << "Modified array" << endl;
    a1[0] = 4;
    // 6. Sort
    sort(a1, a1 + size);
    // 7. Iterate sorted elements
    printV1("sorted a1", a1, size);
}
#include <iostream>
using namespace std;
const int SIZE = 100;  

void traverse(int arr[], int n) {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &n, int pos, int value) {
    if (n >= SIZE) {
        cout << "Array is full, cannot insert!" << endl;
        return;
    }
    if (pos < 0 || pos > n) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1]; 
    }
    arr[pos] = value;
    n++;
}


void deleteElement(int arr[], int &n, int pos) {
    if (pos < 0 || pos >= n) {
        cout << "Invalid position!" << endl;
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];  
    }
    n--;
}

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5};
    int n = 5;  

    cout << "Initial Array: ";
    traverse(arr, n);

    
    insertElement(arr, n, 2, 99); 
    cout << "After Insertion: ";
    traverse(arr, n);

   
    deleteElement(arr, n, 3);
    cout << "After Deletion: ";
    traverse(arr, n);

    return 0;
}

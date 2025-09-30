#include <iostream>
using namespace std;

int main() {
    int arr[6] = {1, 2, 3, 4, 5}; 
    int i, n;
    cout << "Enter the number to be inserted: ";
    cin >> i;
    cout << "Enter the position (1 to 6): ";
    cin >> n;
    int l = 5; 
    for (int j = l - 1; j >= n - 1; j--) {
        arr[j + 1] = arr[j];
    }
    arr[n - 1] = i; 
    l++;
    cout << "The new array is: ";
    for (int k = 0; k < l; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
    return 0;
}

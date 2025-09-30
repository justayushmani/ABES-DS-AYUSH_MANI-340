#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int pos;

    cout << "Enter the position to delete element (0 to 4): ";
    cin >> pos;

    if (pos < 0 || pos >= 5) {
        cout << "Invalid position" << endl;
        return 1;
    }

    for (int i = pos; i < 4; i++) {
        arr[i] = arr[i + 1];
    }

    cout << "Array after deletion: ";
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

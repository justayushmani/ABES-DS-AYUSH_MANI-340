#include <iostream>
using namespace std;

int main()
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n;
    int low = 0, high = 8, mid;
    cout<< ("Enter the number to be searched: ");
    cin >> n;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == n)
        {
            cout<< ("Element found at index %d\n", mid);
            return 0;
        }
        else if (arr[mid] < n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout<< ("Element not found\n");
    return 0;
}
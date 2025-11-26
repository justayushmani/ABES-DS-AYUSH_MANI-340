#include <stdio.h>

void mergesort(int arr[], int left, int right)
{
    int mid;
    if (left < right)
    {
        mid = left + (right - left) / 2;

        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);

        int i, j, k;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int L[n1], R[n2];

        for (i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        i = 0;
        j = 0;
        k = left;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Given array is:\n");
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergesort(arr, 0, arr_size - 1);

    printf("\nSorted array is:\n");
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

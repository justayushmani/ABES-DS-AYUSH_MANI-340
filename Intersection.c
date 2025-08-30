#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {3, 4, 5, 6, 7};
    int arr3[5];  
    int k = 0;    

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i] == arr2[j]) {
                arr3[k] = arr[i];
                k++;
                break; 
            }
        }
    }

    printf("Common elements: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}

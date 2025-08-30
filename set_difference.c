#include <stdio.h>
#include <stdlib.h>

int main() {
    int set1[5] = {1, 2, 3, 4, 5};
    int set2[5] = {4, 5, 6, 7, 8};
    int set3[5];
    int k = 0;

    for (int i = 0; i < 5; i++) {
        int iscommon = 0; 

        for (int j = 0; j < 5; j++) {
            if (set1[i] == set2[j]) {
                iscommon = 1; 
                break;
            }
        }

        if (!iscommon) { 
            set3[k] = set1[i];
            k++;
        }
    }

    printf("Elements in set1 but not in set2: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", set3[i]);
    }
    printf("\n");

    return 0;
}

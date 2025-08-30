#include <stdio.h>
#include <stdlib.h>

int main() {
    int setA[5] = {1, 2, 3, 4, 5};
    int setB[5] = {4, 5, 6, 7, 8};

    int setC[10]; 
    int setD[5];  
    int setE[10]; 

    int kC = 0, kD = 0, kE = 0;

    // Intersection (setD = A ∩ B)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (setA[i] == setB[j]) {
                setD[kD++] = setA[i];
                break;
            }
        }
    }

    // Union (setC = A ∪ B)
    for (int i = 0; i < 5; i++) {
        setC[kC++] = setA[i];
    }
    for (int j = 0; j < 5; j++) {
        int found = 0;
        for (int i = 0; i < 5; i++) {
            if (setB[j] == setA[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            setC[kC++] = setB[j];
        }
    }

    // Symmetric Difference (setE = (A ∪ B) - (A ∩ B))
    for (int i = 0; i < kC; i++) {
        int iscommon = 0;
        for (int j = 0; j < kD; j++) {
            if (setC[i] == setD[j]) {
                iscommon = 1;
                break;
            }
        }
        if (!iscommon) {
            setE[kE++] = setC[i];
        }
    }

    printf("Symmetric Difference : ");
    for (int i = 0; i < kE; i++) {
        printf("%d ", setE[i]);
    }
    printf("\n");

    return 0;
}

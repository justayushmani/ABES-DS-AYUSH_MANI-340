#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, n;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Enter the number to be searched: ");
    scanf("%d", &n);
    for (i = 0; i < 10; i++)
    {
        if (arr[i] == n)
        {
            printf("Element found at index %d\n", i);
            break;
        }

        else if (i == 9)
        {
            printf("Element not found\n");
        }
    }
}
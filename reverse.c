#include <stdio.h>
#include <stdlib.h>
int main(){
    int arr2[5];
    int arr[5]={1,2,3,4,5};
    int i;
    for(i=0;i<5;i++){
        arr2[i]=arr[4-i];
    }
    for(i=0;i<5;i++){
        printf("%d\n ",arr2[i]);
    }
}
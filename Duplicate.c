#include <stdio.h>
#include <stdlib.h>
int main(){
    int arr[5]={1,2,3,3,4};
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(arr[i]==arr[j]){
                printf("Duplicate element found: %d\n",arr[i]);
            }
        }
    }
    

}
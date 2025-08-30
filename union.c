#include <stdio.h>
#include <stdlib.h>
int main(){
    int i,j;
    int arr1 [5]={1,2,3,4,5};
    int arr2 [5]={4,5,6,7,8};
   int arr3[10];
   int k=0;
    for(i=0;i<5;i++){
        arr3[k]=arr1[i];
        k++;
    }
   for(j=0;j<5;j++){
        int found=0;
        for(i=0;i<5;i++){
            if(arr2[j]==arr1[i]){
                found=1;
                break;
            }
        }
        if(!found){
            arr3[k]=arr2[j];
            k++;
        }
   }
       
    

}
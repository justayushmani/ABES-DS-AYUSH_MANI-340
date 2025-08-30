
#include <stdio.h>
#include <stdlib.h> 
int main(){
    int arr[5]={1,2,3,4,5};
    int i,pos;
    printf("Enter the position to delete element: ");
    scanf("%d",&pos);
    if(pos<0 || pos>=5){
        printf("Invalid position\n");
        return 1;
    }   
    for(i=pos;i<4;i++){
        arr[i]=arr[i+1];
    }
    printf("Array after deletion: ");
    for(i=0;i<4;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
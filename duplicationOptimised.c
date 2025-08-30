#include <stdio.h>
#include <stdlib.h>
int main(){
    int arr[5]={1,2,3,3,4};
    int max=0;
    for(int i=0;i<5;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
  int buffer[max];
    for(int i=0;i<=max;i++){
        buffer[i]=0;
    }

    for(int i=0;i<=max;i++){
        buffer[arr[i]]++;
    }

    for(int i=0;i<=max;i++){
            printf("the count of %d is %d\n",i,buffer[i]);
    }
}


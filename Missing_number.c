#include <stdio.h>
#include <stdlib.h>
int main(){
    int arr[5]={1,2,3,4,6};
    int n=6;
    int total_sum=n*(n+1)/2;
    int sum=0;
    for(int i=0;i<n-1;i++){
        sum+=arr[i];
    }
    int missing_number=total_sum-sum;
    printf("Missing number is %d",missing_number);
}
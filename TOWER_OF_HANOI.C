#include <stdio.h>

void hanoi(int n, char A, char B, char c) {
   if(n==1){
       printf("Move disk 1 from rod %c to rod %c\n", A, c);
       return;
   }
   else{
    hanoi(n - 1, A, B, c);
    printf("Move disk %d from rod %c to rod %c\n", n, A, c);
    hanoi(n - 1, B, c, A);         
   }
}

int main() {
    int n = 3; 
    hanoi(n, 'A', 'C', 'B'); 
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}
int main(){
    int a = 20, b = 30;
    printf("%d and %d \n", a, b);
    swap(&a, &b);
    printf("%d and %d \n", a, b);
    return 0;
}
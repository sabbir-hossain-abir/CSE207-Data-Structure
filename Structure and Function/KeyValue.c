#include <stdio.h>
#include <stdlib.h>

struct charSet
{
    char s;
    int i;
};

void keyValue(char* s, int* i){
    scanf("%s %d", s, i);
}

int main(){

    struct charSet A;
    keyValue(&A.s, &A.i);
    printf("%c %d", A.s, A.i);
    return 0;
}
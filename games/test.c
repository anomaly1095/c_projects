#include <stdio.h>
#include <stdlib.h>

typedef struct Test
{
    char val;
}Test;


void fill(Test **x){
    x[0] = (Test*)malloc(sizeof(char));
    x[0][0].val = 0x31;
}

int main(int argc, char const **argv){
    Test **x = (Test**)malloc(sizeof(Test*));
    fill(x);
    printf("%c\n", x[0][0].val);
    free(x);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define uint16 unsigned short
#define uint32 unsigned int
const char* UNIT = "mm";

typedef struct{
    uint16 length;
    uint16 width;
    uint16 height;
    uint32 volume;
} rectangular_prism;

void *get_prism_data(int){
    rectangular_prism *prism1 = (rectangular_prism*)malloc(sizeof(rectangular_prism));
    printf("Enter rectangular prism's length(%s): ", UNIT);
    prism1->length = (uint16*)fgets("%hu", sizeof(uint16), stdin);
    printf("\nEnter rectangular prism's width(%s): ", UNIT);
    prism1->width = (uint16*)fgets("%hu", sizeof(uint16), stdin);
    printf("\nEnter rectangular prism's height(%s): ", UNIT);
    prism1->height = (uint16*)fgets("%hu", sizeof(uint16), stdin);
    return (void*)prism1;
}

// Enter point for the program
int main(int argc, char **argv){
    rectangular_prism *prism = (rectangular_prism*)get_prism_data;
    return 0;
}

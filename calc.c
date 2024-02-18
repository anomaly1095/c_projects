#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
const char UNIT = 'm'; 

typedef struct {
    uint32_t length;
    uint32_t width;
    uint32_t height;
    uint32_t side1_surface; // surface between width & length
    uint32_t side2_surface; // surface between width & height
    uint32_t side3_surface; // surface between length & height
    uint64_t volume;
}rectangular_prism;

rectangular_prism *get_data(){
    rectangular_prism *prism = (rectangular_prism*)malloc(sizeof(rectangular_prism));
    printf("Enter length of the prism (%c): ", UNIT);
    fscanf(stdin, "%u", &prism->length);
    printf("\nEnter width of the prism (%c): ", UNIT);
    fscanf(stdin, "%u", &prism->width);
    printf("\nEnter height of the prism (%c): ", UNIT);
    fscanf(stdin, "%u", &prism->height);
    return prism;
}

int calculate(rectangular_prism *prism){
    prism->side1_surface = prism->length * prism->width;
    prism->side2_surface = prism->width * prism->height;
    prism->side3_surface = prism->height * prism->length;
    prism->volume = prism->side1_surface * prism->height;

}

// printing the width and height of the prism
void draw_prism(rectangular_prism *prism){
    for (uint32_t i = 0; i < prism->width; i++){

        if ((i == 0) || (i == prism->width - 1)){
            //width borders 
            for (uint32_t j = 0; j < prism->length; j++){ // printing width border   
                printf("x");
            }
            printf("\n"); // skipping line after printing
        }else{

            for (uint32_t j = 0; j < prism->length; j++){
                if (j == 0){    // first position of length so printing first border
                    printf("x"); 
                }else if(j == prism->length -1){ //last position of length so brake line
                    printf("x\n");
                }else{   //printing line to go to other border
                    printf(" ");
                }                
            }
        }
    }    
}

int main(int argc, char const *argv[])
{
    rectangular_prism *prism = get_data();
    calculate(prism);
    draw_prism(prism);
    free(prism);
    return 0;
}

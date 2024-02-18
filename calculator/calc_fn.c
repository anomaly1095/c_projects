#include "calc_fn.h"


// Function to calculate based on the values in the queue
void calc(QueueNode **head) {
    if (*head == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    double result = 0;
    while (dequeue(head) != NULL){ // remove first head before even starting since it doesnt have useful data
        if ((*head)->valtype == integer){
            
        }
        else if ((*head)->valtype == symbol){   // finish this
            
        }
        else if ((*head)->valtype == decimal){
            
        }
    }

    printf("Calculation result: %lf\n", result);
}
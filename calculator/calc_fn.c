#include "calc_fn.h"


// Function to calculate based on the values in the queue
void calc(QueueNode **head) {
    if (*head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    double result = 0;
    QueueNode *current, *item_before, *item_next;
    while (*head != NULL) {
        current = dequeue(head);
        if (current->valtype == integer) {
            result += current->NodeVal.integer;
        } else if (current->valtype == symbol) {
            switch (current->NodeVal.symbol){
                case 0x21:   // !

                    break;   
                case 0x25:   // %
   
                    break;   
                case 0x2A:   // *
   
                    break;   
                case 0x2B:   // +
   
                    break;   
                case 0x2D:   // -
   
                    break;   
                case 0x2F:   // /

                    break;
            }
        } else if (current->valtype == decimal) {
            result += current->NodeVal.decimal;
        }

        // Free the memory of the dequeued node
        free(current);
    }

    printf("Calculation result: %lf\n", result);
}

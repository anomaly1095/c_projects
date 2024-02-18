#include "sparsing.h"

//#########################################
_int8 get_buffer(char *s){
    if (s == "exit" || s == "quit"){
        return 0x1;
    }else if (s == "help" || s == "--h" || s == "-h"){
        return 0x2;
    }
    char *c;
    sstrip(s); // remove spaces 
    
    // check if there are unwanted values
    if (check_buffer(s, c) == 0x1){
        printf("Unexcepted value: %c\n", c);  
        return 0x3;
    }
    
    // creating head node
    QueueNode *head = (QueueNode*)malloc(sizeof(QueueNode));
    head->next = NULL;
    head->previous = NULL;

    // parse and add the elements to the queue
    if (parse_buffer(s, &head) != 0x0){ return 0x4; }
    
    //calculate
    calc();

    return 0x0;
}

//######################################### buffer processing

void leftshift(char *s, int position){
    while (*(s+position) != 0x0){
        *(s+position) = *(s+position+0x01);
        position++;
    }
}


void sstrip(char *s){
    _uint8 i = 0x0;
    while (*(s+i) != 0x0){
        if (*(s+i) == 0x20){
            leftshift(s, i);
        }
    }
}
//######################################### buffer checking

_int8 check(char c){
    if ((c >= 0x30 && c <= 0x39) || c == 0x2A || c == 0x2B || c == 0x21 || c == 0x2E || c == 0x2F || c == 0x25 || c == 0x2D){
        return 0x0;
    }
    return 0x1;
}

_int8 check_buffer(char *s, char *c){
    _uint8 i = 0x0;
    while (*(s+i) != 0x0){
        if (check(*(s+i)) == 0x1){
            goto charerror;
        }
    }
    return 0x0;
    charerror:
        *c = *(s+i); // return the invalid value
        return 0x1;
}


_int8 parse_buffer(char *s, QueueNode **head){
    _uint8 i = 0x0, j = 0x0, x = 0x0, decimal_test = 0x0;
    char *digits = (char*)malloc(sizeof(char)*LEN_DBL);  // 30 digits for biggest possible double by IEEE 754
    QueueNode *new_node;

    while (*(s + i) != 0x0){ // 0(n) not O(n²)
    
        //found number
        while ( (*(s + i + x) >= 0x30 && *(s + i + x) <= 0x39) || *(s + i) == 0x2E ){
            
            // too many digits for int64                      //   Node structure: 0x1C bytes
            if (x > LEN_LL && decimal_test == 0x0) {          
                goto int64_overflow;                          //    #8bytes#8bytes#4bytes#8bytes#
            }                                                 //    #      #      #      #      #
            // too many digits for all                        //    # <--  # value# type # -->  #
            if (x > LEN_DBL) {                                //    #      #      #      #      #
                goto dbl_overflow;                            //    # *prev# union# int32# *next#
            }
            // found '.'
            if (*(s + i + x) == 0x2E){ 
                decimal_test = 0x1;
            }
            // add character and increment x
            *(digits + x) = *(s + i + x++);

            // checking if next item is invalid
            if (( *(s + i + x) < 0x30 || *(s + i + x) > 0x39 ) && *(s + i) != 0x2E ){ 
                new_node = (QueueNode*)malloc(sizeof(QueueNode));
                switch (decimal_test){  
                    case 0x0:
                        new_node->NodeVal.integer = strtoll(digits, NULL, 10); 
                        new_node->valtype = integer;
                        break;
                    case 0x1:
                        new_node->NodeVal.decimal = strtod(digits, NULL);      
                        new_node->valtype = decimal;
                        break;
                }
                new_node->next = NULL;
                new_node->previous = NULL;
                queue(head, new_node);  //adding node to queue
                i += x;  x = 0x0;  decimal_test = 0; // increment i by the length of the number found (x)
            }
        }
    
        //found symbol
        if (*(s+i) == 0x2A || *(s+i) == 0x2B || *(s+i) == 0x21 || *(s+i) == 0x2F || *(s+i) == 0x25 || *(s+i) == 0x2D){
            new_node = (QueueNode*)malloc(sizeof(QueueNode));
            new_node->NodeVal.symbol = *(s+i);
            new_node->next = NULL;
            new_node->previous = NULL;
            new_node->valtype = symbol;
            queue(head, new_node);  //adding node to queue
        }
    i++;
    }
    return 0x0;
    int64_overflow:
        return 0x1;
    dbl_overflow:
        return 0x2;
}

// add calculate function
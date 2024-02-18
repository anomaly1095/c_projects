#include "sparsing.h"

//#########################################
_int8 get_buffer(char *s){
    if (s == "help" || s == "--h" || s == "-h"){
        return 0x2;
    }else if (s == "exit" || s == "quit"){
        return 0x1;
    }
    sstrip(s);
    char *c;
    if (check_buffer(s, c) == 0x1){
        printf("Unexcepted value: %c\n", c);
        return 0x3;
    }
    
    // now that checking has been done we start parsing
    if (parse1(s) == 0x0){
        
    }



    return 0x0;
}
//######################################### buffer processing

void leftshift(char *s, int position){
    while (*(s+position) != 0x0){
        *(s+position) = *(s+position+1);
        position++;
    }
}


void sstrip(char *s){
    _uint8 i = 0;
    while (*(s+i) != 0x0){
        if (*(s+i) == 0x20){
            leftshift(s, i);
        }
    }
}
//######################################### buffer checking

_int8 check(char c){
    if ((c >= 0x30 && c <= 0x39) || c == 0x2A || c == 0x2B || c == 0x2C || c == 0x21 || c == 0x2F || c == 0x25 || c == 0x2D){
        return 0x0;
    }
    return 0x1;
}

_int8 check_buffer(char *s, char *c){
    _uint8 i = 0;
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

//######################################### buffer parsing

_int8 parse_for_ll(char *s){
    _uint8 i = 0, j = 0, t = 0, x = 0; // i iterator over the buffer j counter for numbers t counter for symbols x counter for digits of a number
    _int64 *p = (_uint64*)malloc(sizeof(_uint64) * MAX_OPERANDS);
    char *ps = (char*)malloc(sizeof(char)*19); // MAX_INT64 is 19 digits
    char *symbols = (char*)calloc(sizeof(char), MAX_OPERANDS);
    while (*(s+i) != 0x0){
        //found digit
        while (*(s+i+x) >= 0x30 && *(s+i+x) <= 0x39){ // 0(n)->second loop will only be accessed in case of a digit is found
            if (x >= 19) {goto _overflow;} // too many digits
            *(ps+x) = (s+i+x);
            x++;
            if (*(s+i+x) > 0x39 || *(s+i+x) < 0x30){ // no more digits
                
                *(ps+x) = '\0'; // set null terminator
                *(p+j) =  (_int64)strtoll(ps, NULL, 10); // lets conv the char pntr to int
                x = 0;
                j++;
            }    
        }
        //found symbol
        if (*(s+i) == 0x2A || *(s+i) == 0x2B || *(s+i) == 0x2C || *(s+i) == 0x21 || *(s+i) == 0x2F || *(s+i) == 0x25 || *(s+i) == 0x2D){
            *(symbols+t) = *(s+i);
            t++;
        }
    i++;
    }
                                        ///////// now calculate the output and maybe try toi do the float function
    free(symbols); free(ps); free(p);
    return 0;
    _overflow:
        free(symbols); free(ps); free(p);
        return 1;
}

_int8 parse_for_f(char *s){
    _uint8 i = 0, j = 0, t = 0, x = 0; // i iterator over the buffer j counter for numbers t counter for symbols x counter for digits of a number
    _int64 *p = (_uint64*)malloc(sizeof(_uint64) * MAX_OPERANDS);
    char *ps = (char*)malloc(sizeof(char)*19); // MAX_INT64 is 19 digits
    char *symbols = (char*)calloc(sizeof(char), MAX_OPERANDS);
    while (*(s+i) != 0x0){
        //found digit
        while (*(s+i+x) >= 0x30 && *(s+i+x) <= 0x39){ // 0(n)->second loop will only be accessed in case of a digit is found
            if (x >= 19) {goto _overflow;} // too many digits
            *(ps+x) = (s+i+x);
            x++;
            if (*(s+i+x) > 0x39 || *(s+i+x) < 0x30){ // no more digits
                
                *(ps+x) = '\0'; // set null terminator
                *(p+j) =  (_int64)strtoll(ps, NULL, 10); // lets conv the char pntr to int
                x = 0;
                j++;
            }    
        }
        //found symbol
        if (*(s+i) == 0x2A || *(s+i) == 0x2B || *(s+i) == 0x2C || *(s+i) == 0x21 || *(s+i) == 0x2F || *(s+i) == 0x25 || *(s+i) == 0x2D){
            *(symbols+t) = *(s+i);
            t++;
        }
    i++;
    }

    free(symbols); free(ps); free(p);
    return 0;
    _overflow:
        free(symbols); free(ps); free(p);
        return 1;
}
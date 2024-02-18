#include <stdio.h>
#include <stdlib.h>
#include "calc_fn.h"
#include "mytypes.h"

//1
/// @brief 
/// @param s 
/// @return 1 to exit, 2 to get help, 3 if invalid character ...
_int8 get_buffer(char *s);

//3
/// @brief leftshifts all elements
/// @param s buffer
/// @param position where the shifting should begin
void leftshift(char *s, int position);

//2
/// @brief strips buffer from spaces 
/// @param s buffer
void sstrip(char *s);

//4
/// @brief check if the character is an axcepted value
/// @param c character from the buffer
/// @return 0 if accepted 1 if not
_int8 check(char c);

//3
/// @brief check if buffer has all accepted values
/// @param s buffer
/// @param c char pointer that will be used once an invalid val is found
/// @return returns 
_int8 check_buffer(char *s, char *c);


/// @brief takes the buffer filters the numbers and symbols 
/// @param s buffer
/// @return 
_int8 parse_for_ll(char *s);
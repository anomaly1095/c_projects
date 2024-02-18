#include "calc_fn.h"


//1
/// @brief 
/// @param s 
/// @return 1 to exit, 2 to get help, 3 if invalid character ...
extern _int8 get_buffer(char *s);

//3
/// @brief leftshifts all elements
/// @param s buffer
/// @param position where the shifting should begin
extern void leftshift(char *s, int position);

//2
/// @brief strips buffer from spaces 
/// @param s buffer
extern void sstrip(char *s);

//4
/// @brief check if the character is an axcepted value
/// @param c character from the buffer
/// @return 0 if accepted 1 if not
extern _int8 check(char c);

//3
/// @brief check if buffer has all accepted values
/// @param s buffer
/// @param c char pointer that will be used once an invalid val is found
/// @return returns 
extern _int8 check_buffer(char *s, char *c);


/// @brief parses the buffer adds numbers and symbols to the queue
/// @param s buffer
/// @param head first node in queue
/// @return 0 success 1/2 overflows
extern _int8 parse_buffer(char *s, QueueNode **head);
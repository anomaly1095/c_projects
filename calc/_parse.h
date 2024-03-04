

#if !defined(PARSING_H)
#define PARSING_H
#include <stdio.h>
#include <stdlib.h>

#define BIT_MASK 0b110000
#define MAX_LEN_BUFF 256

typedef union Node_val{
    char symbol;
    float decimal;
}Node_val;

// unidirectional queue
typedef struct QueueNode{
    Node_val content;
    struct QueueNode *next;
}QueueNode;

void queue(QueueNode **head);

/// @brief dequeue
/// @param head 
/// @return head of queue, NULL if empty
QueueNode *dequeue(QueueNode **head);

//#########################################

/// @brief prints the position of the error
/// @param buff input buffer
/// @param positition positon of error!
void print_error(char *buff, char positition);

/// @brief check if the cha r is a digit or .
/// @param c character to check
/// @param F_flag 
/// @return return 00 if figit found else 01
char check_digit(char c, char *F_flag);


/// @brief check if the cha r is an arithmetic operator.
/// @param c (char*) character to check
/// @return return 00 if symbol found else 01
char check_symbol(char c);

/// @brief check validity of input buffer
/// @param buff (char*)input buffer
/// @param F_flag (char*) float flag
/// @return return 00 if valid else 01
char check_buff(char *buff, char *F_flag);

/// @brief first pass to check for invalid chars and floating points
/// @param buff (char*) input buffer
/// @return 00 if all good 01 if error
char first_parse(char *buff);


char second_parse(char *buff, QueueNode **head);

#endif // PARSING_H

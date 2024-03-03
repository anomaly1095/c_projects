

#if !defined(PARSING_H)
#define PARSING_H
#include <stdio.h>
#include <stdlib.h>

#define int32 int
#define MAX_LEN_BUFF 256

typedef union Node_val{
    char symbol;
    int32 integer;
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

void print_error(char *buff, char positition);

char check_buff(char *buff);

char first_parse(char *buff, QueueNode **head);

char second_parse(char *buff, QueueNode **head);

#endif // PARSING_H

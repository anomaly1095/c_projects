#include <stdio.h>


#if !defined(MYTYPES_H)
#define MYTYPES_H

#define LEN_LL 0x13  // max digits for 64bit signed

#define MAX_UINT8 0xff
#define MAX_UINT16 0xffff
#define MAX_UINT32 0xffffffff
#define MAX_UINT64 0xffffffffffffffff
#define MIN_UINT 0x0

#define MAX_INT8 0x7f
#define MAX_INT16 0x7fff
#define MAX_INT32 0x7fffffff
#define MAX_INT64 0x7fffffffffffffff

#define MIN_INT8 (-0x80)
#define MIN_INT16 (-0x8000)
#define MIN_INT32 (-0x80000000)
#define MIN_INT64 (-0x8000000000000000)

#define LEN_DBL 0x1E  // max digits for 64bit double signed

#define MAX_FLOAT 3.40282347e+38F
#define MIN_FLOAT 1.17549435e-38F

#define MAX_DOUBLE 1.7976931348623157e+308
#define MIN_DOUBLE 2.2250738585072014e-308

#define MAX_LONG_DOUBLE 1.18973149535723176502e+4932L
#define MIN_LONG_DOUBLE 3.36210314311209350626e-4932L


//#########################################################

typedef unsigned char _uint8;
typedef unsigned short _uint16;
typedef unsigned int _uint32;
typedef unsigned long long _uint64;

typedef signed char _int8;
typedef signed short _int16;
typedef signed int _int32;
typedef signed long long _int64;

typedef union Val{
    char symbol;
    _int64 integer;
    double decimal;
}Val;

typedef enum type_val{
    symbol,
    integer,
    decimal
}type_val;

typedef struct QueueNode{
    struct QueueNode *previous;
    Val NodeVal;
    type_val valtype;
    struct QueueNode *next;
}QueueNode;

/// @brief add node at the back of the queue
/// @param head head node that we are tracking
/// @param Node node to add 
extern void queue(QueueNode **head, QueueNode *Node);

/// @brief removes first node
/// @param head head node
/// @return node that was removed or NULL if empty
extern QueueNode *dequeue(QueueNode **Node);


#endif // MYTYPES_H
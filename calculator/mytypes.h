


#if !defined(MYTYPES_H)
#define MYTYPES_H

#define MAX_OPERANDS 10 // number of allowed operands in a single statement (useless limitations set by me...)
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

//#########################################################

typedef unsigned char _uint8;
typedef unsigned short _uint16;
typedef unsigned int _uint32;
typedef unsigned long long _uint64;

typedef signed char _int8;
typedef signed short _int16;
typedef signed int _int32;
typedef signed long long _int64;


#endif // MYTYPES_H

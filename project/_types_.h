//####################################################

#ifndef _ERRORS_
  #define _ERRORS_      0x1
  #define _SUCCESS      0x0
  #define NO_ARGS       0x1
  #define U_MISSING     0x2
  #define P_MISSING     0x3
  #define F_NOT_FOUND   0x4
  #define WRONG_CRED    0x5
  #define ARCH_ERROR    0x32

#endif

//####################################################

#ifndef _TYPES_
  #define _TYPES_ 1
  #if defined(__x86_64__) || defined(__arm__)
    #define _ui8    unsigned char
    #define _i8     signed char
    #define _ui16   unsigned short
    #define _i16    signed short
    #define _ui32   unsigned int
    #define _i32    signed int 
    #define _l64    signed long
    #define _ul64   unsigned long
    #define _ll64   signed long long
    #define _ull64  unsigned long long    
  #else
    #error ARCH_ERROR
  #endif

#endif // _TYPES_ 1

//####################################################
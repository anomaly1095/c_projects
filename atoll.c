#include <stdlib.h>
#include <stdio.h>

#define int64 signed long long
#define int8 signed char

int8 _size(char *arr);
int64 _atoll(char *arr, int8 size);
int8 _checkdigits(char c, int8 *nflag);

int main(int argc, char **argv){
  int8 size;
  int64 val;
  if (argc != 2) {
    return 1;
  }
  size = _size(argv[1]);

  val = _atoll(argv[1], size);
  printf("%lld\n", val);
  free(&val);
  return 0;
}


int8 _size(char *arr){
  int8 i = 0; 
  while (*(arr+i) != 00) {
    i++;
  }
  return i;
}

int64 _atoll(char *arr, int8 size){
  int8 *nflag = (int8*)malloc(sizeof(int8)), digit, pos = 0x1;
  *nflag = 0x0;
  int64 res = 0;
  for (int8 i = 0; i < size; i++) {
    digit = _checkdigits(*(arr+i), nflag);
    if(digit == 1){
      exit(EXIT_FAILURE);
    }else if (res == 0) {
      continue;
    }
    else{
      res += pos * digit;
      pos *= 10;
    }
  }
  if (*nflag == 1) {
    return -res;
  }
  return res;
}

int8 _checkdigits(char c, int8 *nflag){
  int j = 0, i;
  for (i = 0x30; i < 0x39; i++) {
    if (c == i) {
      return j;
    }
  }
  if (c == 0x2D) {
    *nflag = 1;
    return 0;
  }
  return 1;
}

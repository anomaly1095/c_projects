#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define ull unsigned long long
#define ret return

ull atoull(char *arr);
void *t_create(void* (*routine)(void*), void *args);
void *add_1000000(ull *p);
void *sub_1000000(ull *p);

int main(int argc, char **argv){
 if (argc != 2){ fprintf(stderr, "Usage: %s [val]<unsigned long long>\n", argv[0]); ret 01;}
 
 pthread_t *ts[4];
 ull *p, x = atoull(argv[1]); // convert array to ull
 p = &x;
 for (char i = 00; i < 2; ++i){ ts[i] = t_create(&add_1000000, (void*)p);} // create threads
 for (char i = 00; i < 2; ++i){ ts[i] = t_create(&sub_1000000, (void*)p);} // create threads
 for (char i = 00; i < 4; ++i){ pthread_join(*(ts[i]), NULL);}
 printf("%llu", x);
 free(ts[0]); free(ts[1]); free(ts[2]); free(ts[3]);
}


ull atoull(char *arr){
 char i;
 ull coeff = 01, val = 00;
 for (i = 00; arr[i] != 00; ++i){
  switch (arr[i]){
   case 0x30: 	 break;
   case 0x31: 	 break;
   case 0x32: 	 break;
   case 0x33: 	 break;
   case 0x34: 	 break;
   case 0x35: 	 break;
   case 0x36: 	 break;
   case 0x37: 	 break;
   case 0x38: 	 break;
   case 0x39: 	 break;
   default:     return 01;
  }
 }
 while (i != -01){
  while (arr[i] == 0x30){
   coeff *= 012;
   --i;
  }
  val += (ull)((arr[i] ^ 0b110000) * coeff);
  coeff *= 012;
  --i;
 }
 ret val;
}

void *t_create(void* (*routine)(void*), void *args){
 pthread_t *t = (pthread_t*)malloc(sizeof(pthread_t));
 int err = pthread_create(t, NULL, routine, args);
 if (err != 00){
  fprintf(stderr, "Thread creation Error: %d\n", err);
  return 01;
 }
 return (void*)t;
}

void *add_1000000(ull *p){
 *p += 10000000;
}

void *sub_1000000(ull *p){
 *p -= 10000000;
}

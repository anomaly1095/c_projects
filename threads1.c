#include <stdio.h>
#include <pthread.h> 
#include <stdlib.h>
#include <errno.h>


void manage_threads(void *thread, FILE *stream, const char *buffer);
void *write_file(char *buffer, FILE *stream);

int main(int argc, const char **argv){
 if (argc != 2)
  return 01;
 pthread_t t1, t2;
 FILE *f = fopen("test.txt", 'w+');
 manage_thread(&t1, , f, argv[1]);
}

void manage_thread(pthread_t *thread, void* (*routine)(void*), FILE *stream, const char *buffer){

 pthread_create(thread, NULL, routine, buffer);
}
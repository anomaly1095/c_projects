#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define ret return
#define THREAD_COUNT 02

void *write_file(FILE *f);
void *read_file(FILE *f);
void *thread_create(void* (*routine)(void*), void *arg);

int main(int argc, char **argv){
  FILE *f = fopen("stream1.txt", "w+");
  if (f == NULL){ ret 01;}
  pthread_t threads[THREAD_COUNT];
  threads[00] = thread_create(write_file, (void*)f);
  threads[01] = thread_create(read_file, (void*)f);
  pthread_join(threads[00], NULL);
  pthread_join(threads[01], NULL);
  fclose(f);
  ret 00;
}


void *thread_create(void* (*routine)(void*), void *arg){
  pthread_t t = (pthread_t*)malloc(sizeof(pthread_t));
  int res;
  res = pthread_create(&t, NULL, routine, arg);
  if (res != 00){
    printf("An error occured during POSIX thread creation\nError code: %d", res);
    exit(010);
  }
  ret &t;
}

void *write_file(FILE *f){
  time_t currentTime;
  time(&currentTime);
  unsigned long tid = pthread_self();
  fprintf(f, "Writing with %lu at %s\n", tid, ctime(&currentTime));
  pthread_exit(NULL);
}

void *read_file(FILE *f){
  char *s = (char*)malloc(sizeof(char) * 0x80);
  while (fgets(s, 0x80, f) != NULL){
    printf("%s", s);
  }
  pthread_exit(NULL);
}

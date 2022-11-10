#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

struct thread_arg {
  char * name;
  char * str;
  int num;
};

void * func(void * arg) {
  struct thread_arg thrarg = *(struct thread_arg *) arg;
  
  int i;
  for (i = 0; i < thrarg.num; i++) {
    fprintf(stderr, "%s. %s %d\n", thrarg.name, thrarg.str, i+1);
  }
  return NULL;
}

int main() {
  pthread_t thread1, thread2, thread3, thread4;
  

  struct thread_arg thrarg1 = {"Thread_1", "- Text pervogo potoka      - ", 6};
  struct thread_arg thrarg2 = {"Thread_2", "- Text vtorogo potoka      - ", 3};
  struct thread_arg thrarg3 = {"Thread_3", "- Text tret'ego potoka     - ", 1};
  struct thread_arg thrarg4 = {"Thread_4", "- Text chetvertogo potoka  - ", 4};


  if (pthread_create(&thread1, NULL, &func, &thrarg1) != 0){
    fprintf(stderr, "\nError : Thread1\n");
    return 1;
  }
  
  if (pthread_create(&thread2, NULL, &func, &thrarg2) != 0){
    fprintf(stderr, "\nError : Thread2\n");
    return 1;
  }
  
  if (pthread_create(&thread3, NULL, &func, &thrarg3) != 0){
    fprintf(stderr, "\nError : Thread3\n");
    return 1;
  }
  
  if (pthread_create(&thread4, NULL, &func, &thrarg4) != 0){
    fprintf(stderr, "\nError : Thread4\n");
    return 1;
  }

  while(1);

  return 0;
}

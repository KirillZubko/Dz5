#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * child() {
  int i;
  for (i = 0; i < 10; i++)
  {
    printf("Child Thread. Iteration: %d\n", i);
    sleep(1);
  }
}

int main() {

  pthread_t thread;
  
  int g = pthread_create(&thread, NULL, &child, NULL);
  
  if (g != 0){
    fprintf(stderr, "Error!\n");
    return 1;
  }
	
  int i;
  for (i = 0; i < 10; i++) {
    printf("Main Thread. Iteration: %d\n", i);
    sleep(1);
  }
  
  return 0;
}

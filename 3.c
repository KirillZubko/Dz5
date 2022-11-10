#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>


#define chislo 3

void * random_num() {
  while(1) {
    int n = rand()%10+1;
    printf("Random gen. Num: %d\n", n);

    if (chislo	 == n) {
      fprintf(stderr, "Random gen. Chislo sovpadaet!\n");
      pthread_exit(NULL);
    }
  }
  return 0;
}

void * func() {
  int i;
  for (i = 0; i < 10; i++)   {
    printf("Child Thread. Iteration: %d\n", i);
    sleep(1);
  }
}



int main() {
  srand(time(NULL));
  
  pthread_t thread1, thread2;

  if (pthread_create(&thread1, NULL, &func, NULL)!= 0) {
    fprintf(stderr, "Error: Thread 1\n");
    return 1;
  }

  if (pthread_create(&thread2, NULL, &random_num, NULL)!= 0) {
    fprintf(stderr, "Error: Thread 2\n");
    return 1;
  }

  if (pthread_join(thread1, NULL) != 0) {
    fprintf(stderr, "Join error: Thread 1\n");
    return 1;
  }

  if (pthread_join(thread2, NULL) != 0) {
    fprintf(stderr, "Join error: Thread 2\n");
    return 1;
  }

  printf("Main Thread. Vse potoki zavershiili svoyou rabotu!\n");
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

void* start_routine(void*);

int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void*), void *arg);

int pthread_join(pthread_t thread, void **retval);

void* pth_body(void *args)
{
 int n;
 printf("enter a natural number: \n");
 scanf("%d", &n);
 if(n<1)
   printf("Not a Natural Number\n");
 else
  {
   int sum=0, i;
   for(i=1; i<=n; i++)
     sum+=i;
   printf("Sum of %d natural numbers are: %d\n",n, sum);
  }
 printf("Thread Number: %d\n", *((int*)args));
}

int main()
{
 pthread_t thread;
 int count=0;
 while(1){
    count++;
    pthread_create(&thread, NULL, &pth_body, &count);
    pthread_join(thread, NULL);
    sleep(1);
   }
}
	

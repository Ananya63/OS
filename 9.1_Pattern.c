#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t sem1;
sem_t sem2;

void* fun1(void *args)
{
	int i;
	for(i = 0; i < 3; i++){	
		sem_wait(&sem1);
		printf("b");
		printf("a");
		sem_post(&sem2);
	}
}

void* fun2(void *args)
{
	int i;
	for(i = 0; i < 3; i++){	
		sem_wait(&sem2);
		printf("a");
		printf("b");
		sem_post(&sem1);
	}
}

int main(){
	pthread_t t1;
	pthread_t t2;

	sem_init(&sem1, 0, 1);
	sem_init(&sem2, 0, 0);
	
	pthread_create(&t1, NULL, &fun1, NULL);
	pthread_create(&t2, NULL, &fun2, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);	
	
	sem_destroy(&sem1);
	sem_destroy(&sem2);
	
	printf("\n");
	return 1;
}


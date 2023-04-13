#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<pthread.h>
#define MAX 3

int arr[MAX];
int front=-1, rear=-1;

int isFull()
{
	if((front==rear+1)||(front==0 && rear==MAX-1))
		return 1;
	return 0;
}
int isEmpty()
{
	if(front==-1)
		return 1;
	return 0;
}
int enqueue(int n)
{
	if(isFull())
	{
		printf("Queue is full!\n");
		return -1;
	}
	else
	{
		if(front==-1)
			front=0;
		rear=(rear+1)%MAX;
		arr[rear]=n;
		return 0; 
	}
}
int dequeue()
{
	int n;
	if(isEmpty())
	{
		printf("Queue is empty!\n");
		return -1;
	}
	else
	{
		n=arr[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
			front=(front+1)%MAX;
		return n;
	}
}

sem_t full,empty,mutex;
int x=1;

void* prod(void *args)
{
	do{
		sleep(1);
		sem_wait(&empty);
		sem_wait(&mutex);
		if(enqueue(x)==0)
			printf("Producing: %d\n",x);
		x++;
		sem_post(&full);
		sem_post(&mutex);
	}while(1);
}	

void* cons(void *args)
{
	do{
		sleep(2);
		sem_wait(&full);
		sem_wait(&mutex);
                printf("Consuming: %d\n",dequeue());
                sem_post(&empty);
                sem_post(&mutex);
	}while(1);
}

int main()
{
	printf("Buffer Size Available is: 3\n");
        pthread_t pr, con;
	sem_init(&empty,0,10);
	sem_init(&full,0,0);
	sem_init(&mutex,0,1);
	pthread_create(&pr,NULL,&prod,NULL);
	pthread_create(&con,NULL,&cons,NULL);
	pthread_join(pr,NULL);
	pthread_join(con, NULL);
	return 0;
}

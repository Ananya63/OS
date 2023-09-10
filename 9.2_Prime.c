#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
void* start_routine(void *);

void* pth_body(void *args)
{
	int count = 0, i;
	if (*((int*)args)<0)
                printf("Enter a natural number\n");
	else
            {
		for(i  = 1; i <= (*(int*)args); i++)
                 {			
			if(*((int*)args) % i == 0)
                          count++;
			if(count > 2)
                          break;
	         }
            }
        pthread_exit((void *) count);
}
int main()
{
	pthread_t thread;
	
	while(1)
        {
		int n,f;
		printf("Enter a number: ");
		scanf("%d", &n);
		pthread_create(&thread, NULL, &pth_body, &n);
		pthread_join(thread, (void *)&f);
        	if (f == 2)
                  printf("Prime Number\n");
         	else
                  printf("Not prime Number\n");
                sleep(1);
	}
}


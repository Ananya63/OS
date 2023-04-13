#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t id=fork();
    if(id==0)
    {
         printf("Child has started with process id : %d\n", getpid());
         printf("Parent Process ID: %d\n",getppid());
         system("ps -a");
         exit(EXIT_SUCCESS);
    }
    else if(id>0)
    {
        printf("Parent Process id: %d\n", getpid());
        printf("waiting for child process to finish\n");
        wait(NULL);
        printf("Child process finished\n");
    }
    else
    {    
	 printf("unable to create child process\n");
    }
    return EXIT_SUCCESS;
}



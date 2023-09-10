#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
    int PID = fork();
    if(PID == -1)
        printf("Process creation unsuccesful");
    else if(PID == 0) //child
    {
        printf("Child PID(PID) : %d\n",getpid());
        printf("Child's Parent PID(PPID) : %d\n",getppid());
        sleep(10);
    }
    else //parent
    {
        printf("Parent PID(PID) : %d\n",getpid());
        printf("Parent's Parent PID (PPID): %d\n",getppid());
        sleep(5);
        wait(NULL);
    }
    return 0;
}

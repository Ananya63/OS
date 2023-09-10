#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
int i;
void fun1(int signum)
{
  printf("Signal number: %d\n", signum);
  i=1;
}
int main()
{
  int pid = fork();
  if(pid == 0)
  {
    sleep(5);
    kill(getppid(), SIGALRM);
  }
  else
  {
    signal(SIGALRM, fun1);
    while (1)
    {
      printf("Message from parent process...\n");
      sleep(1);
      if(i==1)
        exit(0);
    }
  }
}


#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int i;
void fun1(int signum)
{
  printf("Signal number: %d\n", signum);
  i=1;
}
int main()
{
  signal(SIGINT, fun1);
  while (1)
  {
    printf("Message from the process...\n");
    sleep(1);
    if(i==1)
      break;
  }
return 0;
}


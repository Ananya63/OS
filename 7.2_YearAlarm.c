#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void fun1(int signum)
{
  int y;
  printf("Enter year: ");
  scanf("%d",&y);
  if((y%100!=0 && y%4==0)||(y%400==0))
    printf("%d is Leap Year!\n",y);
  else
    printf("%d is not Leap Year!\n",y);
  printf("Signal number: %d\n", signum);
}
int main()
{
  int pid = fork();
  if(pid == 0)
  {
    while(1)
    {
      signal(SIGALRM, fun1);
    }
   }
   else
   {
     while (1)
     {
       printf("Message from parent...\n");
       sleep(5);
       kill(pid, SIGALRM);
     }
   }
}


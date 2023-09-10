#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/stat.h>

int main()
{

	int pfd[2];
	pipe(pfd);
	pid_t id=fork();
	char data[32];
	if(id==0)
	{
		printf("\nInside parent process");
		char str[20];
		printf("\nEnter a string : ");
		scanf("%s",str);
		write(pfd[1],str,sizeof(str));
	}
	else if(id>0)
	{
		printf("\nInside child process");
		read(pfd[0],data,sizeof(data));
		printf("\n%s\n",data);
	}	

	return 0;

}


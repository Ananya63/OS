#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	char data1[32],data2[32], result[32];
	int fd1=open("./myfifo1",O_RDONLY);
	perror("open");
	int fd2=open("./myfifo2",O_WRONLY);
	perror("open");
	read(fd1,data1,sizeof(data1));
	sleep(1);
	read(fd1,data2,sizeof(data2));
	puts(data1);
	puts(data2);
	if(!strcmp(data1,data2))
		strcpy(result,"SAME");
	else
		strcpy(result,"NOT SAME");
	write(fd2, result, strlen(result)+1);	
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	char str1[20],str2[20];
	char data[20];
	unlink("myfifo1");
	unlink("myfifo2");
	mkfifo("myfifo1",0777);
	perror("mkfifo1");
	mkfifo("myfifo2",0777);
	perror("mkfifo2");
	int fd1=open("myfifo1",O_WRONLY);
	int fd2=open("myfifo2",O_RDONLY);
	printf("\nEnter first string : ");
	scanf("%s",str1);
	printf("\nEnter second string : ");
	scanf("%s",str2);
	write(fd1,str1,sizeof(str1));
	sleep(1);
	write(fd1,str2,sizeof(str2));

	read(fd2,data,sizeof(data));
	printf("%s\n",data);
	return 0;
}


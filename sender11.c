#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char* argv[]){
	char str[512];
	int shmid=shmget(1234,sizeof(str),0666|IPC_CREAT);
	int res=-1;
	void* mybuff=(void*)shmat(shmid,NULL,0);
	
	printf("Enter input to check for palindrome:");
	scanf("%s",str);
	strcpy((char*)mybuff,str);
	
	sleep(5);
	
	res=*((int*)mybuff);
	if(res==1)
		printf("Palindrome\n");
	else
		printf("Not Palindrome\n");
	
	shmdt(mybuff);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}

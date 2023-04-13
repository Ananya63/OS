#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

int main(int argc,char* argv[]){
	char str[512],revstr[512];
	int shmid=shmget(1234,sizeof(str),0666);
	void* mybuff=(void*)shmat(shmid,NULL,0);
	int res=1;
	strcpy(str,(char*)mybuff);
	printf("Received from Process 1: %s\n",(char*)mybuff);
	int i=0;
	int h=strlen(str)-1;
	while(h>=0){
		revstr[i++] = str[h--];
	}
	revstr[i] = '\0';
	res = (!strcasecmp(str,revstr)) ? 1 : 0 ;
	*((int *)mybuff)=res;
	shmdt(mybuff);
	return 0;
}

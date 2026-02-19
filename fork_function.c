#include<stdio.h>
#include<unistd.h>

int main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("child process\n");
		printf("child PID:%d\n",getpid());
	}
	else if (pid>0)
	{
		printf("parent process\n");
		printf("parent PID:%d\n",getpid());
	}
	else
	{
		printf("fork failed\n");
	}
	return 0;
}

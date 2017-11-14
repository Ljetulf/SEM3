#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>

int main()
{
	int status;
	pid_t pid_c;//pid of child process
	pid_t pid = fork();
	if (pid == -1)//if error
	{
		assert(0);
	}
	else if (pid == 0)//if child
	{
		
		execl("hello", "hello", NULL);
		assert(0);
	}
	else//if parent
	{
		pid_c = wait(&status);//wait for child
		printf("Child %d ended with status %d\n", pid_c, status);
		exit(0);
	}
}

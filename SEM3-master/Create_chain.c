#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	int n, i, status;//n - quantity of processes, i - iterator, status - status of ended child
	pid_t endpid;//pid of the ended child
	i = 0;
	printf("Create n processes:");
	scanf("%d", &n);
	printf("I am parent and I born\n");
	while (i < n - 1)//I could do it with for() too
	{
		i++;
		pid_t pid = fork();
		if (pid != 0)
		{
			printf("Child born\n");
			endpid = wait(&status);
			printf("Child %d died with status %d\n", endpid, status);
			exit(0);
		}
	}
	return 0;
}

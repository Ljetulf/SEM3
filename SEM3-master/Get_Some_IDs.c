#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	printf("Your User ID is %d\n", getuid());
	printf("Your Group ID is %d\n", getgid());
	return 0;
}

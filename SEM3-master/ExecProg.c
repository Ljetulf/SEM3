#define SIZEOFSTR 100
#define SIZEOFFILE 100

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <assert.h>

int main()
{
	FILE* file;
	int status;
	int i = 0;
	int j = 0;
	char c;
	char* string;
	char* argvfile[SIZEOFFILE];
	pid_t pid_c;//pid of child process
	if ((file = fopen("Fileforexec.txt","r")) == NULL)
	{
		printf("Error of opening file\n");
		assert(0);
	}
	while((i < SIZEOFFILE-1) && (j < SIZEOFSTR-1) && ((c = fgetc(file))!=EOF))//while we have some commands for our exec
	{
		if (string == NULL)
			string = (char*) malloc(SIZEOFSTR*sizeof(char));
		if (c != '\n')//if we are not reach the end of our string
		{
			if (isspace(c)&&(strlen(string)!=0))//if there is a token
			{
				string[j++]='\0';
				argvfile[i] = (char *) malloc(SIZEOFSTR*sizeof(char));//create place for our string
				strcpy(argvfile[i++],string);
				j = 0;//free our buffer string
				free(string);
				string = NULL;
			}
			else//if there is a char
			{
				string[j++]=c;
			}
		}
		else
		{
			argvfile[i]=NULL;
			pid_t pid = fork();
			if (pid == -1)//if error
			{
				assert(0);
			}
			else if (pid == 0)//if child
			{
				execv(argvfile[0], argvfile);
				assert(0);
			}
			else//if parent
			{
				pid_c = wait(&status);//wait for child
				printf("Child %d ended with status %d\n", pid_c, status);
				for (i = SIZEOFFILE-1; i>=0; i--)
				{
					if (argvfile[i]!=NULL)
					{
						free(argvfile[i]);//free our argv for next program
						argvfile[i] = NULL;
					}
				}
			}
		}
	}
	if (!fclose(file))
	{
		printf("Error of closing file\n");
		assert(0);
	}
	exit(0);
}

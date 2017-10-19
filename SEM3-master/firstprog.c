#include <stdio.h>
#include <string.h>

void GenerateString(int n, char* string)
{
    string[0] = 'a';
    for (int i = 1; i < n; i++)
    {
        string[(1 << i) - 1] = 'a' + i;
	*(string + (1 << i) - 1) = 'a' + i;
    }
    *(string + (1 << n) - 1) = '\0';
}

int main()
{
    int a;
    char *s;
    scanf("%d",&a);
    if (!(string = (char *) malloc(sizeof(char) * (1 << n))))
        printf("Error in memory allocate\n");
    else    
    	GenerateString(a,s);
    printf(s);
    free(s);
    return 0;
}

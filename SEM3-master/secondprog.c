#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const long int SIZEOFARRAY = 1000;
//не забыть пофиксить dilimiters-должен быть массив
int split(char* string, const char* delimiter, char** words)
{
    int number = 0;
    int i = 0;
    if (!string || !delimiter || !words)
        return 0;
    char* symb = strtok(string, delimiter);
    while (symb != NULL)
    {
        words[i++] = symb;
        symb = strtok(NULL, delimiter);
        number++;
    }
    return number;
}

int main()
{
    char* word;
    char* dels;
    char** wordi;
    word = (char *) malloc(sizeof(char) * SIZEOFARRAY);
    dels = (char *) malloc(sizeof(char) * SIZEOFARRAY);
    wordi = (char **) malloc(sizeof(word) * SIZEOFARRAY);
    printf("Write your word:");
    scanf("%s", word);
    printf("Write your delimiters:");
    scanf("%s", dels);
    printf("Count of your words: %d\n", split(word, dels, wordi));
    char** buf = (char **) malloc(sizeof(char) * SIZEOFARRAY);
    for (int i = 0; i < sizeof(word) * SIZEOFARRAY; i++) 
	buf[i] = wordi[i];
    printf("Your words:\n");    
    while (*buf)
    {
        printf("%s\n",*buf);
        buf++;
    }
    free(wordi);
    free(word);
    free(dels);
    return 0;
}

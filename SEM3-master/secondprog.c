#include <stdio.h>
#include <string.h>

// mas -> massiv? ... array
const long int SIZEOFMAS=1000;
// fixit: пробелы вокруг бинарных операторов

// dilimeters - их массив, а не одно значение
int split(char* string, const char* delimiter, char** words)
{
    int number=0;
    int i=0;
    
    // лишние скобки: if (!string || !delimiter || !words)
    if ((!string)||(!delimiter)||(!words))
        return 0;
    char* symb=strtok(string, delimiter);
    while (symb!=NULL)
    {
        words[i++]=symb;
        symb=strtok(NULL, delimiter);
        number++;
    }
    return number;
}

int main()
{
    char* word;
    char* dels;
    char** wordi;
    word=(char *) malloc(sizeof(char)*SIZEOFMAS);
    dels=(char *) malloc(sizeof(char)*SIZEOFMAS);
    wordi=(char **) malloc(sizeof(word)*SIZEOFMAS);
    printf("Write your word:");
    scanf("%s",word);
    printf("Write your delimiters:");
    scanf("%s",dels);
    printf("Count of your words: %d\n",split(word,dels,wordi));
    char** buf=wordi;
    printf("Your words:");
    
    // fixit: нет никакой гарантии, что у вас массив wordi будет инициализирован NULL'ами
    // либо сами явно иницилизируйте, либо с помощью for выводите, т.к. знаете же число слов в строке
    while (*buf)
    {
        printf("%s\n",*buf);
        buf++;
    }
    
    // не обязательно к void* приводить здесь
    free((void*)wordi);
    free((void*)word);
    free((void*)dels);
    return 0;
}

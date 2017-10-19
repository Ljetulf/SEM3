#include <stdio.h>
#include <string.h>

void GenerateString(int n, char* string)
{
    if (!(string=(char *) malloc(sizeof(char)*(1 << n))))
    // fixit: пробелы вокруг бинарных операторов (здесь и ниже)
        printf("Error in memory allocate\n");
    else
    {
        string[0]='a';
        for (int i=1;i<n;i++)
        {
            strncpy(string+(1<<i),string,(1<<i)-1);
            // вам точно string[(1 << i) - 1] = 'a' + i; меньше нравится?
            *(string + (1 << i) - 1)='a'+i;
        }
        *(string + (1 << n) - 1)='\0';
    }
    printf(string);
    // fixit: выделение/освобождение памяти + вывод вынесите из ф-и наружу
    free((void *)string);
}

int main()
{
    int a;
    char *s;
    scanf("%d",&a);
    GenerateString(a,s);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcs.h"


int main()
{
    size_t size = 500;

    char *str = (char*)malloc(sizeof(char)*size);

    if (str == NULL)
    {
	printf("Ошибка выделения памяти");
	exit(-1);
    }

    printf("Выражение: ");
    size_t line = getline(&str, &size, stdin);

    char num1[size];
    char num2[size];
    char oper = 'a';

    CheckString(str, num1, num2, &oper);
    printf("n1: %s, n2: %s, oper: %c", num1, num2, oper);

    free(str);

    return 0;
}


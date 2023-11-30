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


    free(str);

    return 0;
}


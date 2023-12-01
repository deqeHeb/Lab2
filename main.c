#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcs.h"


int main()
{
    size_t size = 500;

    char *str;

    printf("Выражение: ");
    size_t line = getline(&str, &size, stdin);

    if (str == NULL)
    {
	printf("Ошибка выделения памяти");
	exit(-1);
    }


    char num1[size];
    char num2[size];
    char oper = 'a';

    CheckString(str, num1, num2, &oper);
    //printf("n1: %s, n2: %s, oper: %c\n", num1, num2, oper);

    int ss1 = GetSS(num1);
    int ss2 = GetSS(num2);

    //printf("%d %d\n", ss1, ss2);

    if (ss1 == 0 || (ss2 == 0 && oper != '~'))
    {
	printf("Ошибка: неправильная система счисления\n");
	exit(-1);
    }
    if (ss1 != ss2 && oper != '~')
    {
	printf("Ошибка: разные системы счисления\n");
	exit(-1);
    }

    int res;

    switch(oper)
    {
	case '+':
	    res = Addition(num1, num2, ss1);
	    break;
	case '-':
	    res = Subtr(num1, num2, ss1);
	    break;
	case '*':
	    res = Mult(num1, num2, ss1);
	    break;
	case '%':
	    res = Divis(num1, num2, ss1);
	    break;
	case '&':
	    res = BitAnd(num1, num2, ss1);
	    break;
	case '|':
	    res = BitOr(num1, num2, ss1);
	    break;
	case '^':
	    res = BitXor(num1, num2, ss1);
	    break;
	case '~':
	    res = BitNot(num1, ss1);
	    break;
	default:
	    break;
    }

    PrintRes(res, ss1);
    free(str);

    return 0;
}


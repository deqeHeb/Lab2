#include "converse.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int GetDig(char c) //Перевод цифры (0-F) в десятичное число
{
    switch (c)
    {
	case '0':
	    return 0;
	case '1':
	    return 1;
	case '2':
	    return 2;
        case '3':
	    return 3;
	case '4':
	    return 4;
	case '5':
	    return 5;
	case '6':
	    return 6;
	case '7':
	    return 7;
	case '8':
	    return 8;
	case '9':
	    return 9;
        case 'A':
	    return 10;
	case 'a':
	    return 10;
	case 'B':
	    return 11;
	case 'b':
	    return 11;
        case 'C':
	    return 12;
	case 'c':
	    return 12;
	case 'D':
	    return 13;
	case 'd':
	    return 13;
	case 'E':
	    return 14;
	case 'e':
	    return 14;
	case 'F':
	    return 15;
        case 'f':
	    return 15;
	default:
	    return 0;
    }
}

char GetChar(int c) //Перевод числа (остатка от деления) в цифру(0-F)
{
    switch (c)
    {
	case 0:
	    return '0';
	case 1:
	    return '1';
	case 2:
	    return '2';
        case 3:
	    return '3';
	case 4:
	    return '4';
	case 5:
	    return '5';
	case 6:
	    return '6';
	case 7:
	    return '7';
	case 8:
	    return '8';
	case 9:
	    return '9';
        case 10:
	    return 'a';
	case 11:
	    return 'b';
	case 12:
	    return 'c';
	case 13:
	    return 'd';
        case 14:
	    return 'e';
	case 15:
	    return 'f';
	default:
	    return ' ';
    }
}


long poww(long a, long b) //Возведение в степень
{
    long res = 1;
    for (int i = 0; i < b; i++)
    {
	res *= a;
    }
    return res;
}

int StrToDec(char *str, int ss) //Перевод строки в десятичную СС
{
    int res = 0;
    int i = 0;
    int sign = 1;

    if (str[0] == '-')
    {
	i = 1;
	sign = -1;
    }

    if (ss == 16) i += 2;
    else if (ss == 8) i += 1;
    int p = strlen(str)-1-i;

    for (i; i < strlen(str); i++)
    {
	res += GetDig(str[i])*poww(ss, p);
	p--;
    }

    return res*sign;
}

char *IntToStr(int num, int ss) //Перевод из десятичного числа в ss-чную СС в виде строки
{
    int d = num;
    char *str = (char*)malloc(500 * sizeof(char));

    if (str == NULL)
    {
	printf("Ошибка: null malloc");
	exit(-1);
    }
    int indStr = 0;

    if (num < 0)
    {
	d *= (-1);
    }

    while (d > 0) //Перевод числа из десятичной в ss-чную систему счисления
    {
	str[indStr] = GetChar(d % ss);
	indStr++;
	str[indStr] = '\0';

	d /= ss;
    }

    if (strlen(str) == 0)
    {
        str[indStr] = '0';
	indStr++;
	str[indStr] = '\0';
    }

    if (ss == 16)
    {
	str[indStr] = 'x';
	indStr++;
        str[indStr] = '0';
	indStr++;
	str[indStr] = '\0';

    }
    else if (ss == 8)
    {
	str[indStr] = '0';
	indStr++;
	str[indStr] = '\0';
    }

    if (num < 0) //Если число отрицательное, добавляем минус
    {
	str[indStr] = '-';
	indStr++;
	str[indStr] = '\0';
    }

    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) //Переворачиваем строку
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    return str;
}

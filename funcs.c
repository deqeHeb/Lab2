#include <stdio.h>
#include "funcs.h"
#include <stdlib.h>
#include <string.h>

void CheckString(char *str, char *num1, char *num2,char *oper)
{
    char alf[] = "x0123456789AaBbCcDdEeFf";
    char alfOper[] = "+-*%^&|";

    strcpy(num1, "");
    strcpy(num2, "");
    int ind1 = 0;
    int ind2 = 0;
    *oper = ' ';

    int count_space = 0;
    int isFirstSpace = 0;
    char *strtmp = strchr(str, ' ');

    if (strtmp == NULL)
    {
	count_space = 0;
    }
    else
    {
        while ((strtmp = strchr(strtmp, ' ')) != NULL)
        {
            count_space++;
            strtmp++;
        }
    }

    if (count_space == 1 || count_space > 2 || (str[0] != '~' && count_space == 0))
    {
	printf("Ошибка: неправильная расстановка пробелов\n");
	exit(-1);
    }
    int flag = 0;
    if (str[0] == '~' && count_space == 0)
    {
	for (int i = 1; i < strlen(str)-1; i++)
        {
	    flag = 0;
            for (int j = 0; j < strlen(alf); j++)
	    {
		if (alf[j] == str[i])
		{
		    flag = 1;
		    num1[ind1] = str[i];
		    ind1++;
		    num1[ind1] = '\0';
		}
	    }
	    if (flag == 0)
	    {
		printf("Ошибка: неверная запись числа\n");
		exit(-1);
	    }
        }
	*oper = '~';
    } else if (count_space == 2)
    {
	for (int i = 0; i < strlen(str)-1; i++)
        {
	    flag = 0;
            for (int j = 0; j < strlen(alf); j++)
	    {
		if (i == 0 && str[i] == '-')  //Проверка, что '-' это не оператор, а знак числа
		{ 
		    num1[ind1] = '-';
		    ind1++;
		    num1[ind1] = '\0';
		    flag = 1;
		    break;
		}
                if (i != 0 && str[i] == '-' && str[i-1] == ' ')
		{
		    num2[ind2] = '-';
		    ind2++;
		    num2[ind2] = '\0';
		    flag = 1;
		    break;
		}

		if (alf[j] == str[i]) //Если число состоит из допустимых символов
		{
		    if (isFirstSpace == 0)
		    {
		        num1[ind1] = str[i]; //и находится до оператора, то оно записывается в num1 
		        ind1++;
			num1[ind1] = '\0';
		    }
		    else
		    {
		        num2[ind2] = str[i]; //если после оператора, то в num2 
		        ind2++;
			num2[ind2] = '\0';
		    }
		    flag = 1;
		}


		if (str[i] == ' ' && isFirstSpace == 0) //Если встречается первый пробел, то ищется оператор
		{
		    int flagOper = 0;
		    for (int k = 0; k < strlen(alfOper); k++)
		    {
			flagOper = 0;
			char strOper[] = "   ";
			strOper[1] = alfOper[k];
                        char *strs = strstr(str, strOper);
		        if (strs != NULL)
			{
			    *oper = alfOper[k];
			    i += 3;
			    flagOper = 1;
			}	
		    }
		    if (flagOper == 0)
		    {
                        if (*oper == ' ')
	                {
                            printf("Ошибка: неверный оператор\n");
	                    exit(-1);
	                }
		    } 
                    isFirstSpace = 1;
		    flag = 1;
		}

	    }

	    if (flag == 0)
	    {
		printf("Ошибка: неверная запись числа\n");
		exit(-1);
	    }
        }
    }
}

int GetSS(char *str) //Получение системы счисления числа
{
    int len = strlen(str);
    char alf2[] = "01";

    char alf8[] = "01234567";

    char alf16[] = "0123456789AaBbCcDdEeFf";
    int flag = 0;

    int k = 0;

    if (str[0] == '-')
    {
	k = 1;
    }

    if (str[k] == '0' && str[k+1] == 'x')
    {
	for (int i = k+2; i < len; i++)
	{
	    flag = 0;
            for (int j = 0; j < strlen(alf16); j++)
	    {
		if (str[i] == alf16[j])
		{
		    flag = 1;
		}
	    }
	    if (!flag) break;
	    if (i == len-1) return 16;
	}
    }
    else if (str[k] == '0' && len > 1+k)
    {
        for (int i = k+1; i < len; i++)
	{
	    flag = 0;
            for (int j = 0; j < strlen(alf8); j++)
	    {
		if (str[i] == alf8[j])
		{
	            flag = 1;
		}
	    }
	    if (flag == 0) break;
	    if (i == len-1) return 8;
	}
    }
    else 
    {
        for (int i = k; i < len; i++)
	{
	    flag = 0;
            for (int j = 0; j < strlen(alf2); j++)
	    {
		if (str[i] == alf2[j])
		{
		    flag = 1;
		}
	    }
	    if (!flag) break;
	    if (i == len-1) return 2;
	}
    }
    return 0;
}

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

void PrintRes(int res, int ss)
{
    char *resStr = IntToStr(res, ss);
    printf("%s (%d)\n", resStr, res);
    free(resStr);
}

int Addition(char *num1, char *num2, int ss)
{
    int res;
    res = StrToDec(num1, ss) + StrToDec(num2, ss); 
    return res;
}

int Subtr(char *num1, char *num2, int ss)
{
    int res;
    res = StrToDec(num1, ss) - StrToDec(num2, ss); 
    return res;
}

int Mult(char *num1, char *num2, int ss)
{
    int res;
    res = StrToDec(num1, ss) * StrToDec(num2, ss);
    return res;
}

int Divis(char *num1, char *num2, int ss)
{
    int res;
    res = StrToDec(num1, ss) % StrToDec(num2, ss); 
    return res;
}

int BitAnd(char *num1, char *num2, int ss)
{
    int res;
    res = StrToDec(num1, ss) & StrToDec(num2, ss); 
    return res;
}

int BitOr(char *num1, char *num2, int ss)
{
    int res;
    res = StrToDec(num1, ss) | StrToDec(num2, ss); 
    return res;
}

int BitXor(char *num1, char *num2, int ss)
{
    int res;
    res = StrToDec(num1, ss) ^ StrToDec(num2, ss); 
    return res;
}

int BitNot(char *num1, int ss)
{
    int res;
    res = ~(StrToDec(num1, ss)); 
    return res;
}


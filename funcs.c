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

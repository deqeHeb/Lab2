#include <stdio.h>
#include "operations.h"
#include <stdlib.h>
#include "converse.h"

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

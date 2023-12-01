#ifndef FUNCS_H
#define FUNCS_H

void CheckString(char *str, char *num1, char *num2, char *oper);
int GetSS(char *str);
void PrintRes(int res, int ss);
int Addition(char *num1, char *num2, int ss1);
int Subtr(char *num1, char *num2, int ss1);
int Mult(char *num1, char *num2, int ss1);
int Divis(char *num1, char *num2, int ss1);
int BitAnd(char *num1, char *num2, int ss1);
int BitOr(char *num1, char *num2, int ss1);
int BitXor(char *num1, char *num2, int ss1);
int BitNot(char *num1, int ss1);

#endif

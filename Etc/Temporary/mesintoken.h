#ifndef __MESIN_TOKEN_H_
#define __MESIN_TOKEN_H_


typedef struct{
	double val;
	char tkn;
}Token;

void SplitToken(char (*s)[], Token (*Arr)[], int *Ntoken);

#endif
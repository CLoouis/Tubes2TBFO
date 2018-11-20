#ifndef __MESIN_TOKEN_H_
#define __MESIN_TOKEN_H_

#include <complex.h>

typedef struct{
	double complex val;
	char tkn;
}Token;

void SplitToken(char (*s)[], Token (*Arr)[], int *Ntoken);

#endif
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "mesintoken.h"

int NToken;

void SplitToken(char (*s)[], Token (*Arr)[], int *NToken){
    int i = 0;
    while (i < strlen(*s)){
        if ((*s)[i] == ' ') {
            while (i < strlen(*s) && (*s)[i] == ' ') i++; 
        }
        else if ((*s)[i] == '+' || (*s)[i] == '-' || (*s)[i] == '*' || (*s)[i] == '/' 
        || (*s)[i] == '^' || (*s)[i] == '(' || (*s)[i] == ')') {
            (*Arr)[*NToken].tkn = (*s)[i];
            (*Arr)[*NToken].val = -1.00;
            (*NToken)++;
            i++;
         }
        else {
            double tmp = 0.00;
			int dotpos = 0;
            int cnt = 0;
			while (i < strlen(*s) && (((*s)[i] >= '0' && (*s)[i] <= '9') || (*s)[i] == '.')){
                if ((*s)[i] == '.') {
                    dotpos = i;
                    cnt++;
                }
                else tmp = 10 * tmp + ((*s)[i] - '0');
                i++;
            }
            if (cnt != 0) {
                dotpos = i - dotpos - 1;
                while (dotpos > 0){
                    tmp /= 10.0;
                    dotpos--;
                }
            }
            (*Arr)[*NToken].tkn = 'b';
            (*Arr)[*NToken].val = tmp;
            (*NToken)++;
        } 
    }
}
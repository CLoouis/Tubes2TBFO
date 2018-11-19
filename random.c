#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include <math.h>
#include "mesintoken.h"
#include "stack.h"

char InputUser[1005];
Token CToken[10005];
int NToken;
Stack tok;
bool IsValid;

double parse_item();
double parse_factor();
double parse_term();
double parse_expression();

bool cekvalid(double bil1, char opr, double bil2){
    double test;
    test = pow(bil1,bil2);
    if ((opr == '/') && (bil2 == 0)){
        return false;
    }
    else if ((bil1 == 0) && (opr == '^') && (bil2 == 0)){
        return false;
    }
    else if (test != test){
        return false;
    }
    else {
        return true;
    }
}

double parse_item(){
    infotype t, s;
    Pop(&tok, &t);
    if (t.tkn == 'b') return t.val;
    double expr = parse_expression();
    Pop(&tok,&s);
    return expr;
}

double parse_factor(){
    infotype t;
    Pop(&tok, &t);
    Push(&tok, t);    
    double sign;
    if (t.tkn == '-')
        sign = -1;
    else sign = 1;
    if (t.tkn == '+' || sign < 0) 
        Pop(&tok, &t);
    double result = parse_item();
    Pop(&tok, &t);
    Push(&tok, t);
    while (t.tkn == '^'){
        Pop(&tok, &t);
        if (t.tkn != '^') {
            Push(&tok, t);
            break;
        }
        double rhs = parse_factor();
        if (cekvalid(result, '^', rhs)){
            result = pow(result, rhs);
        }
        else {
            IsValid = false;
            return 0;
        }
        Pop(&tok, &t);
        Push(&tok, t);
    } 
    return sign * result;
}

double parse_term(){
    double result = parse_factor();
    infotype t;
    Pop(&tok, &t);
    if (t.tkn != '*' && t.tkn != '/')
        Push(&tok, t);
    while (t.tkn == '*' || t.tkn == '/'){
        double rhs = parse_factor();
        if (cekvalid(result, t.tkn, rhs)) {
            if (t.tkn == '/')
                result /= rhs;
            else
                result *= rhs;
        }
        else {
            IsValid = false;
            return 0;
        }
        Pop(&tok, &t);
        if (t.tkn != '*' && t.tkn != '/'){
            Push(&tok, t);
        }
    }
    return result;
}

double parse_expression(){
    double result = parse_term();
    infotype t;
    Pop(&tok, &t);
    if (t.tkn != '+' && t.tkn != '-') 
        Push(&tok, t);
    while (t.tkn == '+' || t.tkn == '-'){
        double rhs = parse_term();
        if (t.tkn == '+')
            result += rhs;
        else 
            result -= rhs;
        Pop(&tok, &t);
        if (t.tkn != '+' && t.tkn != '-'){
            Push(&tok, t);
        }
    }
    return result;
}

int main(){
    gets(InputUser);
    SplitToken(&InputUser, &CToken, &NToken);
    CreateEmpty(&tok);
    IsValid = true;
    for (int i = 0; i < NToken; i++){
        Push(&tok, CToken[i]);
    }
    tok = Reverse(tok);
    double ans = parse_expression();
    if (IsValid) 
        printf("%.6f\n", ans);
    else 
        printf("Math error!\n");
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "mesintoken.h"
#include "stack.h"
#include "pda.h"
#include "stackchar.h"
#include "boolean.h"

/* Kumpulan variabel yang digunakan untuk menghitung ekspresi */
Token CToken[10005];
int NToken;
Stackt tok;
boolean IsValid;

/* Kumpulan fungsi yang digunakan untuk menghitung ekspresi */
/* fungsi-fungsi di bawah ini juga merupakan implementasi dari recursive descent parser algorithm yang menggunakan CFG */
double parse_item();
double parse_factor();
double parse_term();
double parse_expression();

/*fungsi dibawah ini berfungsi untuk mengecek apakah suatu operasi matematika tersebut valid atau tidak */
/* contoh : 2 + 3 * 5 -> valid 
            9 / (9 - 3*3) -> tidak valid
            0 ^ 0 -> tidak valid 
*/
boolean cekvalid(double bil1, char opr, double bil2){
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

/*implementasi dari parse_item */
double parse_item(){
    Infotype t, s;
    Popst(&tok, &t);
    if (t.tkn == 'b') return t.val;
    double expr = parse_expression();
    Popst(&tok,&s);
    return expr;
}

/*implementasi dari parse_item */
double parse_factor(){
    Infotype t;
    Popst(&tok, &t);
    Pushst(&tok, t);    
    double sign;
    if (t.tkn == '-')
        sign = -1;
    else sign = 1;
    if (t.tkn == '+' || sign < 0) 
        Popst(&tok, &t);
    double result = parse_item();
    Popst(&tok, &t);
    Pushst(&tok, t);
    while (t.tkn == '^'){
        Popst(&tok, &t);
        if (t.tkn != '^') {
            Pushst(&tok, t);
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
        Popst(&tok, &t);
        Pushst(&tok, t);
    } 
    return sign * result;
}

/*implementasi dari parse_term */
double parse_term(){
    double result = parse_factor();
    Infotype t;
    Popst(&tok, &t);
    if (t.tkn != '*' && t.tkn != '/')
        Pushst(&tok, t);
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
        Popst(&tok, &t);
        if (t.tkn != '*' && t.tkn != '/'){
            Pushst(&tok, t);
        }
    }
    return result;
}

/*implementasi dari parse_expression */
double parse_expression(){
    double result = parse_term();
    Infotype t;
    Popst(&tok, &t);
    if (t.tkn != '+' && t.tkn != '-') 
        Pushst(&tok, t);
    while (t.tkn == '+' || t.tkn == '-'){
        double rhs = parse_term();
        if (t.tkn == '+')
            result += rhs;
        else 
            result -= rhs;
        Popst(&tok, &t);
        if (t.tkn != '+' && t.tkn != '-'){
            Pushst(&tok, t);
        }
    }
    return result;
}

/*mendapatkan input dari user */
void getInput(){
    masukan inputuser;
    gets(inputuser);
    if (validasi(inputuser)) {    
        SplitToken(&inputuser, &CToken, &NToken);
        CreateEmptyst(&tok);
    }else{
        printf("Syntax error!\n");
        exit(-1);
    }
}


/* main program */
int main(){
    getInput();
    IsValid = true;
    for (int i = 0; i < NToken; i++){
        Pushst(&tok, CToken[i]);
    }
    tok = Reverse(tok);
    double ans = parse_expression();
    if (IsValid) 
        printf("%.6f\n", ans);
    else 
        printf("Math error!\n");
    return 0;
}
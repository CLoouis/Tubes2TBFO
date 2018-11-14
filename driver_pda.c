#include <stdio.h>
#include <string.h>
#include "stackt.h"
#include "boolean.h"
#include "pda.h"

int main(){
    masukan s;

    scanf("%s",&s);
    if (validasi(s)){
        printf("Masuk pa Eko\n");
    } else {
        printf("Tidak semudah itu Ferguso\n");
    }
    return 0;
}

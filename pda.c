#include <stdio.h>
#include <string.h>
#include "stackchar.h"
#include "boolean.h"
#include "pda.h"

void transisi (State *Q, char input){
    char C;

    if (Posisi(*Q) == 0){
        if (input == '('){
            if (InfoTop(Stack(*Q)) == 'Z'){
                Push(&Stack(*Q),'X');
            } else if (InfoTop(Stack(*Q)) == 'X'){
                Push(&Stack(*Q),'X');
            } else {
                Posisi(*Q) = 5;
            }

        } else if (input == '-'){
            if (InfoTop(Stack(*Q)) == 'Z'){
                Posisi(*Q) = 1; //Pindah ke state 1
            } else if (InfoTop(Stack(*Q)) == 'X'){
                Posisi(*Q) = 1; //Pindah ke state 1
            } else {
                Posisi(*Q) = 5;
            }

        } else if (input=='0'||input=='1'||input == '2'||input=='3'||input=='4'||input=='5'||input=='6'||input=='7'||input=='8'||input=='9') {
            if (InfoTop(Stack(*Q)) == 'X'){
                Posisi(*Q) = 2;
            } else if (InfoTop(Stack(*Q)) == 'Z'){
                Posisi(*Q) = 2;
            } else {
                Posisi(*Q) = 5;
            }
        } else if (input == '.'){
            if (InfoTop(Stack(*Q)) == 'X'){
                Posisi(*Q) = 4;
            } else if (InfoTop(Stack(*Q)) == 'Z'){
                Posisi(*Q) = 4;
            } else {
                Posisi(*Q) = 5;
            }
        } else {
            Posisi(*Q) = 5;
        }

    } else if (Posisi(*Q) == 1){
        if (input=='0'||input=='1'||input == '2'||input=='3'||input=='4'||input=='5'||input=='6'||input=='7'||input=='8'||input=='9'){
            if (InfoTop(Stack(*Q)) == 'X'){
                Posisi(*Q) = 2;
            } else if (InfoTop(Stack(*Q)) == 'Z'){
                Posisi(*Q) = 2;
            } else {
                Posisi(*Q) = 5;
            }

        } else if (input == '('){
            if (InfoTop(Stack(*Q)) == 'Z'){
                Posisi(*Q) = 0;
                Push(&Stack(*Q),'X');
            } else if (InfoTop(Stack(*Q)) == 'X'){
                Posisi(*Q) = 0;
                Push(&Stack(*Q),'X');
            } else {
                Posisi(*Q) = 5;
            }
        } else {
            Posisi(*Q) = 5;
        }

    } else if (Posisi(*Q) == 2){
        if (input=='0'||input=='1'||input == '2'||input=='3'||input=='4'||input=='5'||input=='6'||input=='7'||input=='8'||input=='9'){
            if (InfoTop(Stack(*Q)) == 'X'){
                //do nothing
            } else if (InfoTop(Stack(*Q)) == 'Z'){
                //do nothing
            } else {
                Posisi(*Q) = 5;
            }

        } else if (input=='.'){
            if (InfoTop(Stack(*Q)) == 'X'){
                Posisi(*Q) = 4;
            } else if (InfoTop(Stack(*Q)) == 'Z'){
                Posisi(*Q) = 4;
            } else {
                Posisi(*Q) = 5;
            }

        } else if (input==')'){
            if(InfoTop(Stack(*Q)) == 'X'){
                Pop(&Stack(*Q),&C);
            } else {
                Posisi(*Q) = 5;
            }

        } else if (input=='+'||input=='-'||input=='*'||input=='/'||input=='^'){
            if(InfoTop(Stack(*Q)) == 'X'){
                Posisi(*Q) = 3;
            } else if (InfoTop(Stack(*Q)) == 'Z'){
                Posisi(*Q) = 3;
            } else {
                Posisi(*Q) = 5;
            }

        } else {
            Posisi(*Q) = 5;
        }

    } else if (Posisi(*Q) == 3){
        if (input=='0'||input=='1'||input == '2'||input=='3'||input=='4'||input=='5'||input=='6'||input=='7'||input=='8'||input=='9'){
            if (InfoTop(Stack(*Q)) == 'X'){
                Posisi(*Q) = 2;
            } else if (InfoTop(Stack(*Q)) == 'Z'){
                Posisi(*Q) = 2;
            } else {
                Posisi(*Q) = 5;
            }

        } else if (input == '('){
            if (InfoTop(Stack(*Q)) == 'X'){
                Push(&Stack(*Q),'X');
                Posisi(*Q) = 0;
            } else if (InfoTop(Stack(*Q)) == 'Z'){
                Push(&Stack(*Q),'X');
                Posisi(*Q) = 0;
            } else {
                Posisi(*Q) = 5;
            }
        } else if (input == '-'){
            if (InfoTop(Stack(*Q)) == 'X'){
                Posisi(*Q) = 1;
            } else if (InfoTop(Stack(*Q)) == 'Z'){
                Posisi(*Q) = 1;
            } else {
                Posisi(*Q) = 5;
            }
        } else if (input == '.') {
            if (InfoTop(Stack(*Q)) == 'X'){
                Posisi(*Q) = 4;
            } else if (InfoTop(Stack(*Q)) == 'Z'){
                Posisi(*Q) = 4;
            } else {
                Posisi(*Q) = 5;
            }
        } else {
            Posisi(*Q) = 5;
        }

    } else if (Posisi(*Q) == 4){
        if (input=='0'||input=='1'||input == '2'||input=='3'||input=='4'||input=='5'||input=='6'||input=='7'||input=='8'||input=='9'){
            if (InfoTop(Stack(*Q)) == 'X'){
                //do nothing
            } else if (InfoTop(Stack(*Q)) == 'Z'){
                //do nothing
            } else {
                Posisi(*Q) = 5;
            }

        } else if (input=='+'||input=='-'||input=='*'||input=='/'||input=='^'){
            if(InfoTop(Stack(*Q)) == 'X'){
                Posisi(*Q) = 3;
            } else if (InfoTop(Stack(*Q)) == 'Z'){
                Posisi(*Q) = 3;
            } else {
                Posisi(*Q) = 5;
            }

        } else if (input == ')'){
            if(InfoTop(Stack(*Q)) == 'X'){
                Pop(&Stack(*Q),&C);
            } else {
                Posisi(*Q) = 5;
            }

        } else {
            Posisi(*Q) = 5;
        }
    }
}

boolean validasi (masukan s) {
    int i;
    State Q;
    char karakter;
    //Inisialisasi
    Posisi(Q) = 0;
    CreateEmpty(&Stack(Q));
    Push(&Stack(Q),'Z');

    for (i = 0; i < strlen(s);i++){
        karakter = s[i];
        transisi(&Q,karakter);
        //Uncomment next line to check state movement
        //printf("%d, %c\n",Posisi(Q),InfoTop(Stack(Q)));
    }

    if ((Posisi(Q) == 2 && InfoTop(Stack(Q)) == 'Z') || (Posisi(Q) == 4 && InfoTop(Stack(Q)) == 'Z')){
        return true;
    } else {
        return false;
    }
}

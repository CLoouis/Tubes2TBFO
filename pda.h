/* Louis Cahyadi
Version : 14 - 11 -2018
*/

#ifndef pda_H
#define pda_H

#include <stdio.h>
#include <string.h>
#include "stackchar.h"
#include "boolean.h"

typedef char masukan[100];
//tipe data inputan (string)

typedef struct {
    int Posisi;
    Stack S;
} State;
//Tipe data bentukan state pada PushDown Automata
//Terdiri dari nomor state dan stack
//Manipulasi stack dapat dilihat di stackt.h dan stackt.c

//Selektor
#define Posisi(Q) (Q).Posisi
#define Stack(Q) (Q).S

void transisi (State *Q, char input);
//Merubah kondisi state Q (nomor dan stack) jika menerima masukan input

boolean validasi (masukan s);
//Mengembalikan true jika input dari user valid dan false jika input dari user tidak valid
#endif

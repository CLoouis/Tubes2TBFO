#ifndef Stacktt_H
#define Stacktt_H

#include <stdbool.h>
#include "mesintoken.h"

#define Nill 0
#define MaxEll 20000
/* Nill adalah Stackt dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef Token Infotype;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype Stackt dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
	Infotype T[MaxEll+1]; /* tabel penyimpan elemen */
	address TOP;  /* alamat TOP: elemen puncak */
} Stackt;
/* Definisi Stackt S kosong : S.TOP = Nill */
/* Elemen yang dipakai menyimpan Nillai Stackt T[1]..T[MaxEll] */
/* Jika S adalah Stackt maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyst (Stackt *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah Stackt S yang kosong berkapasitas MaxEll */
/* jadi indeksnya antara 1.. MaxEll+1 karena 0 tidak dipakai */
/* Ciri Stackt kosong : TOP berNillai Nill */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
bool IsEmptyst (Stackt S);
/* Mengirim true jika Stackt kosong: lihat definisi di atas */
bool isFull (Stackt S);
/* Mengirim true jika tabel penampung Nillai elemen Stackt penuh */

/* ************ Menambahkan sebuah elemen ke Stackt ************ */
void Pushst (Stackt * S, Infotype X);
/* Menambahkan X sebagai elemen Stackt S. */
/* I.S. S mungkin kosong, tabel penampung elemen Stackt TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stackt ************ */
void Popst (Stackt * S, Infotype* X);
/* Menghapus X dari Stackt S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah Nillai elemen TOP yang lama, TOP berkurang 1 */

Stackt Reverse(Stackt S);

#endif
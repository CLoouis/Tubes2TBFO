#include <stdio.h>
#include "Stack.h"


/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyst (Stackt *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah Stackt S yang kosong berkapasitas MaxEll */
/* jadi indeksnya antara 1.. MaxEll+1 karena 0 tidak dipakai */
/* Ciri Stackt kosong : TOP berNillai Nill */
{
	Top(*S) = Nill;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
bool IsEmptyst (Stackt S)
/* Mengirim true jika Stackt kosong: lihat definisi di atas */
{
	return (Top(S) == Nill);
}

bool isFull (Stackt S)
/* Mengirim true jika tabel penampung Nillai elemen Stackt penuh */
{
	return (Top(S) == MaxEll);
}

/* ************ Menambahkan sebuah elemen ke Stackt ************ */
void Pushst (Stackt * S, Infotype X)
/* Menambahkan X sebagai elemen Stackt S. */
/* I.S. S mungkin kosong, tabel penampung elemen Stackt TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
	Top(*S)++;
	InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stackt ************ */
void Popst (Stackt * S, Infotype* X)
/* Menghapus X dari Stackt S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah Nillai elemen TOP yang lama, TOP berkurang 1 */
{
	*X = InfoTop(*S);
	Top(*S)--;
}

Stackt Reverse(Stackt S){
	Stackt res;
	CreateEmptyst(&res);
	while (!IsEmptyst(S)){
		Infotype top;
		Popst(&S, &top);
		Pushst(&res, top);
	}
	return res;
}
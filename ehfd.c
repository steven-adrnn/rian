///////////////////listdp////////////////////////


#include "boolean.h"
#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return (First(L) == Nil) && (Last(L) == Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    First(*L) = Nil;
    Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    address p = First(L);
    boolean found = false;
    while (!found && p != Nil) {
        if (Info(p) == X) {
            found = true;
        } else {
            p = Next(p);
        }
    }
    return p;
}
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil) {
        if (IsEmpty(*L)) {
            First(*L) = P;
            Last(*L) = P;
        } else {
            Next(P) = First(*L);
            Prev(First(*L)) = P;
            First(*L) = P;
        }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    address P = Alokasi(X);
    if (P != Nil) {
        if (IsEmpty(*L)) {
            First(*L) = P;
            Last(*L) = P;
        } else {
            Prev(P) = Last(*L);
            Next(Last(*L)) = P;
            Last(*L) = P;
        }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    if (!IsEmpty(*L)) {
        *X = Info(First(*L));
        address P = First(*L);
        First(*L) = Next(First(*L));
        if (First(*L) == Nil) {
            Last(*L) = Nil;
        } else {
            Prev(First(*L)) = Nil;
        }
        Dealokasi(P);
    }
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    if (!IsEmpty(*L)) {
        *X = Info(Last(*L));
        address P = Last(*L);
        Last(*L) = Prev(Last(*L));
        if (Last(*L) == Nil) {
            First(*L) = Nil;
        } else {
            Next(Last(*L)) = Nil;
        }
        Dealokasi(P);
    }
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    if (P != Nil) {
        if (IsEmpty(*L)) {
            First(*L) = P;
            Last(*L) = P;
        } else {
            Next(P) = First(*L);
            Prev(First(*L)) = P;
            First(*L) = P;
        }
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P){
    if (P != Nil) {
        if (IsEmpty(*L)) {
            First(*L) = P;
            Last(*L) = P;
        } else {
            Prev(P) = Last(*L);
            Next(Last(*L)) = P;
            Last(*L) = P;
        }
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec){
    if (Last(*L) != Prec) {
        Next(P) = Next(Prec);
        Prev(P) = Prec;
        Prev(Next(Prec)) = P;
        Next(Prec) = P;
    } else {
        InsertLast(L, P);
    }
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ){
    if (Prev(Succ) != Nil) {
        Next(P) = Succ;
        Prev(P) = Prev(Succ);
        Next(Prev(Succ)) = P;
        Prev(Succ) = P;
    } else {
        InsertFirst(L, P);
    }
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    if (!IsEmpty(*L)) {
        *P = First(*L);
        First(*L) = Next(First(*L));
        if (First(*L) == Nil) {
            Last(*L) = Nil;
        } else {
            Prev(First(*L)) = Nil;
        }
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P){
    if (!IsEmpty(*L)) {
        *P = Last(*L);
        Last(*L) = Prev(Last(*L));
        if (Last(*L) == Nil) {
            First(*L) = Nil;
        } else {
            Next(Last(*L)) = Nil;
        }
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X){
    address P = Search(*L, X);
    if (P != Nil) {
        if (Prev(P) == Nil) {
            DelFirst(L, &P);
        } else if (Next(P) == Nil) {
            DelLast(L, &P);
        } else {
            Next(Prev(P)) = Next(P);
            Prev(Next(P)) = Prev(P);
            Dealokasi(P);
        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec){
    *Pdel = Next(Prec);
    if (*Pdel != Nil) {
        Next(Prec) = Next(*Pdel);
        if (Next(*Pdel) != Nil) {
            Prev(Next(*Pdel)) = Prec;
        } else {
            Last(*L) = Prec;
        }
        Dealokasi(*Pdel);
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ){
    *Pdel = Prev(Succ);
    if (*Pdel != Nil) {
        Prev(Succ) = Prev(*Pdel);
        if (Prev(*Pdel) != Nil) {
            Next(Prev(*Pdel)) = Succ;
        } else {
            First(*L) = Succ;
        }
        Dealokasi(*Pdel);
    }
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L){
    address P = First(L);
    printf("[");
    while (P != Nil) {
        printf("%d", Info(P));
        P = Next(P);
        if (P != Nil) {
            printf(",");
        }
    }
    printf("]\n");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
/* Terdapat newline di akhir setelah tutup kurung */
void PrintBackward (List L){
    address P = Last(L);
    printf("[");
    while (P != Nil) {
        printf("%d", Info(P));
        P = Prev(P);
        if (P != Nil) {
            printf(",");
        }
    }
    printf("]\n");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
/* Terdapat newline di akhir setelah tutup kurung */




///////////////////////listsirkuler/////////////////////////////////////




#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L) {
    return First(L) == Nil;
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L) {
    First(*L) = Nil;
}
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    

/****************** Manajemen Memori ******************/
address Alokasi (infotype X) {
    address p;
    p = (ElmtList*) malloc (sizeof(ElmtList));
    if (p == Nil) return Nil;
    else {
        Info(p) = X;
        Next(p) = Nil;
        return p;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */


void Dealokasi (address P) {
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X) {
    address p;
    boolean found = false;
    if (IsEmpty(L)) return Nil;
    else {
        p = First(L);
        while (Next(p) != First(L) && !found) {
            if (Info(p) == X) found = true;
            else p = Next(p);
        }
    }
    if (Info(p) == X) found = true;

    if (found) {
        return p;
    } else {
        return Nil;
    }
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */


/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X) {
    address p;
    p = Alokasi(X);
    if (p != Nil) InsertFirst(L, p);
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLast (List *L, infotype X) {
    address p;
    p = Alokasi(X);
    if (p != Nil) InsertLast(L, p);
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X) {
    address p;
    DelFirst(L, &p);
    *X = Info(p);
    Dealokasi(p);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    

void DelVLast (List *L, infotype * X) {
    address p;
    DelLast(L, &p);
    *X = Info(p);
    Dealokasi(p);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P) {
    InsertLast(L, P);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */


void InsertLast (List *L, address P) {
    address last;
    if (IsEmpty(*L)) {
        First(*L) = P;
        Next(P) = P;
    }
    else {
        last = First(*L);
        while (Next(last) != First(*L)) {
            last = Next(last);
        }
        Next(last) = P;
        Next(P) = First(*L);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    

void InsertAfter (List *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */    

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P) {
    address last;
    *P = First(*L);
    if (Next(*P) == First(*L)) First(*L) = Nil;
    else {
        last = First(*L);
        while (Next(last) != *P) {
            last = Next(last);
        }
        First(*L) = Next(*P);
        Next(last) = First(*L);
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    

void DelLast (List *L, address *P) {
    address last;
    if (Next(First(*L)) == First(*L)) {
        *P = First(*L);
        First(*L) = Nil;
    } else {
        last = First(*L);
        while (Next(Next(last)) != First(*L)) {
            last = Next(last);
        }
        *P = Next(last);
        Next(last) = First(*L);
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
    

void DelAfter (List *L, address *Pdel, address Prec) {
    *Pdel = Next(Prec);
    if (Next(Prec) == Prec) First(*L) = Nil;
    else if (Next(Prec) == First(*L)) DelFirst(L, Pdel);
    else Next(Prec) = Next(*Pdel);
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    

void DelP (List *L, infotype X) {
    address p, last;
    p = Search(*L, X);
    if (p != Nil) {
        last = First(*L);
        while (Next(last) != p) {
            last = Next(last);
        }
        DelAfter(L, &p, last);
        Dealokasi(p);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
    

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L) {
    address p;
    if (IsEmpty(L)) printf("[]");
    else {
        printf("[");
        p = First(L);
        while (Next(p) != First(L)) {
            printf("%d,", Info(p));
            p = Next(p);
        }
        printf("%d]", Info(p));
    }
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */




//////////////////list_sirkuler(linear)///////////////////////////////





/*
NIM                 : 13520065
Nama                : Rayhan Kinan Muhannad
Tanggal             : 1 November 2021
Topik Praktikum     : Variasi ADT List Linear
Deskripsi           : Definisi fungsi dan prosedur ADT List Sirkuler
*/

#include "list_circular.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi List Circular : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address P dapat diacu INFO(P), NEXT(P) */
/* Elemen terakhir list: jika Addressnya Last, maka NEXT(Last)=FIRST(l) */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    /* KAMUS */

    /* ALGORITMA */
    return (FIRST(l) == NULL);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    /* KAMUS */

    /* ALGORITMA */
    FIRST(*l) = NULL;
}

/****************** Manajemen Memori ******************/
Address allocate(ElType val)
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = (Address) malloc(sizeof(ElmtList));

    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }

    return p;
}
void deallocate(Address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */
{
    /* KAMUS */

    /* ALGORITMA */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val)
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = FIRST(l);

    if (!isEmpty(l)) {
        while ((NEXT(p) != FIRST(l)) && (INFO(p) != val)) {
            p = NEXT(p);
        }

        if (INFO(p) != val) {
            p = NULL;
        }
    }

    return p;
}

boolean addrSearch(List l, Address p)
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */
{
    /* KAMUS */
    Address ptr;

    /* ALGORITMA */
    ptr = FIRST(l);

    if (!isEmpty(l)) {
        while ((NEXT(ptr) != FIRST(l)) && (ptr != p)) {
            ptr = NEXT(ptr);
        }
    }

    return (!isEmpty(l) && (ptr == p));
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
/* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */
{
    /* KAMUS */
    Address p, last;

    /* ALGORITMA */
    p = allocate(val);
    if (p != NULL) {
        if (isEmpty(*l)) {
            NEXT(p) = p;
        } else {
            last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            NEXT(p) = FIRST(*l);
            NEXT(last) = p;
        }
        FIRST(*l) = p;
    }
}
void insertLast(List *l, ElType val)
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */
{
    /* KAMUS */
    Address p, last;

    /* ALGORITMA */
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        p = allocate(val);
        if (p != NULL) {
            last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)) {
                last = NEXT(last);
            }
            NEXT(last) = p;
            NEXT(p) = FIRST(*l);
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val)
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama List l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Jika list baru tidak kosong, Last element menunjuk ke First element baru */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen pertama list lama di-dealokasi */
{
    /* KAMUS */
    Address p, last;

    /* ALGORITMA */
    p = FIRST(*l);
    *val = INFO(p);

    if (NEXT(FIRST(*l)) == FIRST(*l)) {
        FIRST(*l) = NULL;
    } else {
        last = FIRST(*l);
        while (NEXT(last) != FIRST(*l)) {
            last = NEXT(last);
        }
        FIRST(*l) = NEXT(FIRST(*l));
        NEXT(last) = FIRST(*l);
    }
    deallocate(p);
}
void deleteLast(List *l, ElType * val)
/* I.S. List l tidak kosong */
/* F.S. val adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
/*      Jika list baru tidak kosong, Last element baru menunjuk ke First element */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen terakhir list lama di-dealokasi */
{
    /* KAMUS */
    Address precLast, last;

    /* ALGORITMA */
    last = FIRST(*l);
    precLast = NULL;

    while (NEXT(last) != FIRST(*l)) {
        precLast = last;
        last = NEXT(last);
    }
    if (precLast == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(precLast) = FIRST(*l);
    }

    *val = INFO(last);
    deallocate(last);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    if (isEmpty(l)) {
        printf("[]");
    } else {
        p = FIRST(l);
        printf("[");
        do {
            if (NEXT(p) == FIRST(l)) {
                printf("%d", INFO(p));
            } else {
                printf("%d,", INFO(p));
            }
            p = NEXT(p);
        } while (p != FIRST(l));
        printf("]");
    }
}







///////////////////////roundrobin//////////////////////////////////





#include <stdio.h>
#include "listsirkuler.h"

void deleteRR (List *l, infotype tQ){
    infotype X;

    if (IsEmpty(*l)) {
        printf("List kosong\n");
    } else {
        DelVLast(l, &X);
        if (X > tQ) {
            printf("%d\n", tQ);
            X -= tQ;
            InsVFirst(l, X);
        } else {
            printf("%d\n", X);
        }
    }
}
/* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>tQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-tQ
- jika Info(last)<=tQ, maka DelVLast(l,x) dan menampilkan x ke layar */
/* Jika l kosong, cetak "List kosong" */
/* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir l diproses sesuai aturan round-robin.
l mungkin menjadi kosong. */


float average (List l){
    address A;
    int count = 0;
    float sum = 0;

    do {
        sum += Info(A);
        count++;
        A = Next(A);
    } while (A != First(l));
    return (sum/count);
}
/* Menghasilkan nilai rata-rata elemen l. l tidak kosong. */


/* Pengerjaan Soal */
int main() {
    infotype tQ = -1;
    float avg;
    int X;
    List L;

    CreateEmpty(&L);
    while (tQ <= 0) {
        scanf("%d", &tQ);
    }
    char CC;
    while (true) {
        scanf("\n%c", &CC);
        if (CC == 'A') {
            scanf("%d", &X);
            if (X > 0) {
                InsVFirst(&L, X);
            }
        } else if (CC == 'D') {
            deleteRR(&L, tQ);
        } else if (CC == 'F') {
            break;
        } else {
            printf("Kode salah\n");
        }
    }

    if (IsEmpty(L)) {
        printf("Proses selesai\n");
    } else {
        avg = average(L);
        printf("%.2f\n", avg);
    }
}




//////////////queuelist/////////////////




// NIM             : 18221048
// Nama            : Syafiq Ziyadul Arifin
// Tanggal         : 14 November 2022
// Topik praktikum : Praktikum 10
// Deskripsi       : Implementasi dari queuelist.h

#include <stdio.h>
#include "queuelist.h"

void Alokasi(address *P, infotype X)
{
    *P = (ElmtQueue *)malloc(sizeof(ElmtQueue));
    if (*P != Nil)
    {
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi(address P)
{
    free(P);
}

boolean IsEmpty(Queue Q)
{
    return Head(Q) == Nil && Tail(Q) == Nil;
}

int NbElmt(Queue Q)
{
    int count = 0;
    address P = Head(Q);
    if (!IsEmpty(Q))
    {
        while (P != Nil)
        {
            P = Next(P);
            count++;
        }
    }
    return count;
}

void CreateEmpty(Queue *Q)
{
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
}

void Enqueue(Queue *Q, infotype X)
{
    address P;
    Alokasi(&P, X);
    if (P != Nil)
    {
        if (IsEmpty(*Q))
        {
            Head(*Q) = P;
            Tail(*Q) = P;
        }
        else
        {
            Next(Tail(*Q)) = P;
            Tail(*Q) = P;
        }
    }
}

void Dequeue(Queue *Q, infotype *X)
{
    address P = Head(*Q);
    *X = Info(Head(*Q));
    Head(*Q) = Next(Head(*Q));
    Dealokasi(P);
}






///////////////////////linkstack////////////////




#include "linkstack.h"

void Alokasi(address *P, ElType X)
{
    *P = (Node *)malloc(sizeof(Node));
    if (*P != Nil)
    {
        Info(*P) = X;
        Next(*P) = Nil;
    }
}

void Dealokasi(address P)
{
    free(P);
}

boolean IsEmpty(Stack S)
{
    return Top(S) == Nil;
}

void CreateEmpty(Stack *S)
{
    Top(*S) = Nil;
}

void Push(Stack *S, ElType X)
{
    address P;
    Alokasi(&P, X);
    if (P != Nil)
    {
        if (!IsEmpty(*S))
            Next(P) = Top(*S);
        Top(*S) = P;
    }
}

void Pop(Stack *S, ElType *X)
{
    *X = InfoTop(*S);
    address P = Top(*S);
    Top(*S) = Next(Top(*S));
    Dealokasi(P);
}





/////////////////linkdummy/////////////////////////




#include "linkdummy.h"

boolean IsEmpty(List L)
{
    return Info(First(L)) == 0 && Info(Last(L)) == 0;
}

void MakeEmpty(List *L)
{
    address P = Alokasi(0);
    First(*L) = P;
    Last(*L) = P;
}

address Alokasi(ElType X)
{
    address P = (Node *)malloc(sizeof(Node));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi(address P)
{
    free(P);
}

address Search(List L, ElType X)
{
    address P = First(L);
    while (P != Nil && Info(P) != X)
    {
        P = Next(P);
    }
    return P;
}

void InsertFirst(List *L, ElType X)
{
    address P = Alokasi(X);
    if (P != Nil)
    {
        Next(P) = First(*L);
        First(*L) = P;
    }
}

void InsertLast(List *L, ElType X)
{
    address P = Alokasi(X);
    if (P != Nil)
    {
        address loc = First(*L);
        if (IsEmpty(*L))
            InsertFirst(L, X);
        else
        {
            while (Info(Next(loc)) != 0)
            {
                loc = Next(loc);
            }
            Next(P) = Next(loc);
            Next(loc) = P;
        }
    }
}

void DeleteFirst(List *L, ElType *X)
{
    address P = First(*L);
    *X = Info(First(*L));
    First(*L) = Next(First(*L));
    Dealokasi(P);
}

void DeleteLast(List *L, ElType *X)
{
    address P = First(*L);
    if (Next(P) == Last(*L))
        DeleteFirst(L, X);
    else
    {
        while (Next(Next(P)) != Last(*L))
        {
            P = Next(P);
        }
        *X = Info(Next(P));
        Dealokasi(Next(P));
        Next(P) = Last(*L);
    }
}







///////////////////////////elemenken//////////////////////////




#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r)
{
    int i = 0;
    address P = First(L);
    while (i < r)
    {
        P = Next(P);
        i++;
    }
    return Info(P);
}

int main()
{
    List L;
    int r;
    scanf("%d", &r);
    if (r)
    {
        while (r)
        {
            InsVLast(&L, r);
            scanf("%d", &r);
        }
        scanf("%d", &r);
        printf("%d\n", ElemenKeN(L, r));
    }
    else
        printf("List Kosong\n");
    return 0;
}

/////////////////listlinear/////////////////////////////

#include "boolean.h"
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmpty (List L){
    return First(L) == Nil;
}

void CreateEmpty (List *L){
    First(*L) = Nil;
}

address Alokasi (infotype X){
    address result;
    result = (address) malloc (sizeof(ElmtList));
    if (result != Nil){
        Info(result) = X;
        Next(result) = Nil;
    }
    return result;

}

void Dealokasi (address *P){
    free(*P);
}

address Search (List L, infotype X){
    if (IsEmpty(L)) return Nil;

    address now = First(L);
    while(now != Nil && Info(now)!=X){
        now = Next(now);
    }
    return now;
}

void InsVFirst (List *L, infotype X){
    address newfirst = Alokasi(X);
    if (newfirst != Nil){
        Next(newfirst) = First(*L);
        First(*L) = newfirst;
    }
}

void InsVLast (List *L, infotype X){
    address newlast = Alokasi(X);
    if (newlast == Nil) return;

    if (IsEmpty(*L)){
        InsVFirst(L, X);
    } else {
        address now = First(*L);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(now) = newlast;
        Next(Next(now)) = Nil;
    }
}

void DelVFirst (List *L, infotype *X){
    address deleted = First(*L);
    *X = Info(deleted);
    First(*L) = Next(deleted);

    Dealokasi(&deleted);
}

void DelVLast (List *L, infotype *X){
    address now = First(*L);
    if(Next(now) != Nil){
        while(Next(Next(now)) != Nil){
            now = Next(now);
        }
        *X = Info(Next(now));
        Dealokasi(&Next(now));
        Next(now) = Nil;
    }else{
        DelVFirst(L, X);
    }
}

void InsertFirst (List *L, address P){
    address first = First(*L);
    if (P != Nil){
        Next(P) = first;
        First(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (List *L, address P){
    if (P == Nil) return;

    if (IsEmpty(*L)){
        First(*L) = P;
    } else {
        address now = First(*L);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(P) = Nil;
        Next(now) = P;
    }
}

void DelFirst (List *L, address *P){
    address deleted = First(*L);
    *P = deleted;
    First(*L) = Next(deleted);
}

void DelP (List *L, infotype X){
    if(!IsEmpty(*L)){
        address now = First(*L);
        address dummy;
        if(Info(now) == X){
            DelFirst(L, &dummy);
        }else{
            while(Next(now) != Nil && Info(Next(now)) != X){
                now = Next(now);
            }
            if(Next(now) != Nil){
                DelAfter(L, &dummy, now);
            }
        }
    }
}

void DelLast (List *L, address *P){
    address now = First(*L);
    if(Next(now) == Nil){
        DelFirst(L, P);
    }else{
        while(Next(Next(now)) != Nil){
            now = Next(now);
        }
        DelAfter(L, P, now);
    }
}

void DelAfter (List *L, address *Pdel, address Prec){

    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

void PrintInfo (List L){
    printf("[");
    if (!IsEmpty(L)){
        address now = First(L);
        while (now != Nil) {
            printf("%d", Info(now));
            now = Next(now);

            if (now != Nil)
                printf(",");
        }
    }
    printf("]");
}

int NbElmt (List L){
    int n = 0;
    if (!IsEmpty(L)){
        address now = First(L);
        while (now != Nil){
            n++;
            now = Next(now);
        }
    }
    return n;
}

infotype Min (List L){
    address now = First(L);
    infotype min = Info(now);
    while (Next(now) != Nil){
        now = Next(now);
        if (Info(now) < min){
            min = Info(now);
        }
    }
    return min;
}
infotype Max (List L){
    address now = First(L);
    infotype max = Info(now);
    while (Next(now) != Nil){
        now = Next(now);
        if (Info(now) > max){
            max = Info(now);
        }
    }
    return max;
}

void Konkat1 (List *L1, List *L2, List *L3){
    CreateEmpty(L3);
    First(*L3) = First(*L1);
    First(*L1) = Nil;
    if (IsEmpty(*L3)){
        First(*L3) = First(*L2);
    } else {
        address now = First(*L3);
        while (Next(now) != Nil){
            now = Next(now);
        }
        Next(now) = First(*L2);
    }
    First(*L2) = Nil;
}

boolean FSearch (List L, address P){
    address now = First(L);
    while (now != Nil){
        if (P == now){
            return true;
        }
        now = Next(now);
    }
    return false;
}

address SearchPrec (List L, infotype X){
    address s = Search(L, X);
    if (s != Nil){
        address P = First(L);
        while (P != Nil){
            if (Next(P) == s){
                return P;
            }
            P = Next(P);
        }
    }
    return Nil;
}
address AdrMax (List L){
	return Search(L,Max(L));
}

address AdrMin (List L){
	return Search(L,Min(L));
}

float Average (List L){
	if (IsEmpty(L)){
		return 0;
	} else {
		address P = First(L);
		float total = Info(P);
		float count = 1;
		while (Next(P) != Nil){
			P = Next(P);
			total = total + Info(P);
			count++;
		}
		return (total/count);
	} 
}

void DelAll (List *L){
    address pembuangan;
    address now = First(*L);
    while (now != Nil){
        DelFirst(L, &pembuangan);
        now = Next(now);
    }
    First(*L) = Nil;
}

void InversList (List *L){
	if (!IsEmpty(*L)){
		address P = First(*L);
		while (Next(P) != Nil){
			P = Next(P);
		}
		address last = P;
		address Prec;
		while (P != First(*L)){
			Prec = First(*L);
			while (Next(Prec) != P){
				Prec = Next(Prec);
			}
			Next(P) = Prec;
			P = Next(P);
		}
		Next(P) = Nil;
		First(*L) = last;
	}
}

void CopyList (List *L1, List *L2){
    First(*L2) = First(*L1);
}

List FCopyList (List L){
    List new;
    CreateEmpty(&new);

    boolean fail = false;
    address P = First(L);
    while (!fail && P != Nil){
        address c = Alokasi(Info(P));
        if (c == Nil){
            fail = true;
        } else {
            InsertLast(&new, c);
        }
        P = Next(P);
    }
    if (fail){
        DelAll(&new);
    }
    return new;
}

List FInversList (List L){
    List new = FCopyList(L);
    InversList(&new);
    return new;
}

void CpAlokList (List Lin, List *Lout){
    *Lout = FCopyList(Lin);
}

void PecahList (List *L1, List *L2, List L){
    CreateEmpty(L1);
    CreateEmpty(L2);
    int half = NbElmt(L)/2;
    int count = 0;
    address now = First(L);
    while (now != Nil){
        count++;
        address ins = Alokasi(Info(now));
        if (ins != Nil){
            if (count <= half){
                InsertLast(L1, ins);
            } else {
                InsertLast(L2, ins);
            }
        }
        now = Next(now);
    }

}

void Konkat (List L1, List L2, List * L3){
    CreateEmpty(L3);
    List L1new = FCopyList(L1);
    List L2new = FCopyList(L2);
    if (NbElmt(L1new) != NbElmt(L1) || NbElmt(L2new) != NbElmt(L2)){
        return;
    } else {
        Konkat1(&L1new, &L2new, L3);
    }
}




////////////////REMOVE///////////////////////////////////////////





#include "remove.h"


void RemoveDuplicates(List *L){
  if (!IsEmpty(*L)) {
        address P = First(*L);
        while (P != Nil) {
            infotype A = Info(P);
            address B = Next(P);
            address Prev = P;
            while (B != Nil) {
                if (Info(B) == A) {
                    address NextB = Next(B);
                    DelAfter(L, &B, Prev);
                    Dealokasi(&B);
                    B = NextB;
                } else {
                    Prev = B;
                    B = Next(B);
                }
            }
            P = Next(P);
        }
    }
}
/*
I.S. Variable L sudah terisi dengan nilai
Melakukan penghapusan apabila terdapat nilai yang sama

Contoh:
Input: [1,1,2,3]
Output: [1,2,3]

Input: [1,2,3,1]
Output: [1,2,3]
*/


#include <stdio.h>
#include "removeDuplicate.h"

List removeDuplicate(List l)
{
    List lu;
    address P = First(l);
    CreateEmpty(&lu);
    while (P != Nil)
    {
        if (Search(lu, Info(P)) == Nil)
            InsVLast(&lu, Info(P));
        else
            P = Next(P);
    }
    return lu;
}







///////////////////////////oddevenlist///////////////////////////////////









#include "OddEvenList.h"

void OddEvenList(List L, List *Odd, List *Even){
    CreateEmpty(Odd);
    CreateEmpty(Even);

    address P = First(L);
    while (P != Nil) {
        if (Info(P) % 2 == 0) {
            address newP = Alokasi(Info(P));
            if (newP != Nil) {
                if (IsEmpty(*Even)) {
                    InsertFirst(Even, newP);
                } else if (Info(P) <= Info(First(*Even))) {
                    InsertFirst(Even, newP);
                } else {
                    address Q = First(*Even);
                    while (Next(Q) != Nil && Info(P) > Info(Next(Q))) {
                        Q = Next(Q);
                    }
                    InsertAfter(Even, newP, Q);
                }
            }
        } else {
            address newP = Alokasi(Info(P));
            if (newP != Nil) {
                if (IsEmpty(*Odd)) {
                    InsertFirst(Odd, newP);
                } else if (Info(P) <= Info(First(*Odd))) {
                    InsertFirst(Odd, newP);
                } else {
                    address Q = First(*Odd);
                    while (Next(Q) != Nil && Info(P) > Info(Next(Q))) {
                        Q = Next(Q);
                    }
                    InsertAfter(Odd, newP, Q);
                }
            }
        }
        P = Next(P);
    }
}
    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/









///////////////////////cache/////////////////////////////







#include <stdio.h>
#include "listlinier.h"

int main()
{
    List L;
    address tempP;
    int i, N, Q, temp, tempDel;
    CreateEmpty(&L);
    scanf("%d %d", &N, &Q);
    for (i = 1; i <= N; i++)
        InsVLast(&L, i);
    for (i = 0; i < Q; i++)
    {
        scanf("%d", &temp);
        tempP = Search(L, temp);
        if (tempP == Nil)
        {
            printf("miss ");
            DelVLast(&L, &tempDel);
        }
        else
        {
            printf("hit ");
            DelP(&L, temp);
        }
        InsVFirst(&L, temp);
        PrintInfo(L);
        printf("\n");
    }
    return 0;
}











//////////////////////DAFTARNILAI///////////////////////////







#include <stdio.h>
#include "boolean.h"
#include "listlinier.h"

int main()
{
    int input;
    List nilai;
    boolean isValid = true;
    CreateEmpty(&nilai);
    while (isValid)
    {
        scanf("%d", &input);
        if (input >= 0 && input <= 100)
            InsVFirst(&nilai, input);
        else
            isValid = false;
    }

    if (NbElmt(nilai) > 0)
    {
        printf("%d\n%d\n%d\n%.2f\n", NbElmt(nilai), Max(nilai), Min(nilai), Average(nilai));
        InversList(&nilai);
        PrintInfo(nilai);
        printf("\n");
        InversList(&nilai);
        PrintInfo(nilai);
        printf("\n");
    }
    else
        printf("Daftar nilai kosong\n");
    return 0;
}









////////////////////////listfibonaci///////////////////////////





#include "listlinier.h"

int main()
{
    List fibonacci;
    address P1, P2;
    infotype i = 2, el, x1, x2;
    CreateEmpty(&fibonacci);
    scanf("%d", &el);
    if (el == 1)
    {
        scanf("%d", &x1);
        InsVFirst(&fibonacci, x1);
    }
    else if (el > 1)
    {
        scanf("%d %d", &x1, &x2);
        InsVFirst(&fibonacci, x1);
        InsVLast(&fibonacci, x2);
        P1 = First(fibonacci);
        P2 = Next(P1);
        while (i < el)
        {
            InsVLast(&fibonacci, Info(P1) + Info(P2));
            P1 = Next(P1);
            P2 = Next(P2);
            i++;
        }
    }
    PrintInfo(fibonacci);
    return 0;
}










//////////////////////////LISTLINKED//////////////////////////////





#include <stdio.h>
#include "list_linked.h"

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong */
{
    /* KAMUS */

    /* ALGORITMA */
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    /* KAMUS */
    Address p;
    int ctr;

    /* ALGORITMA */
    ctr = 0;
    p = FIRST(l);

    while (ctr < idx) {
        p = NEXT(p);
        ctr++;
    }

    return INFO(p);
}

void setElmt(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
    /* KAMUS */
    Address p;
    int ctr;

    /* ALGORITMA */
    ctr = 0;
    p = FIRST(*l);

    while (ctr < idx) {
        p = NEXT(p);
        ctr++;
    }

    INFO(p) = val;
}

int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    /* KAMUS */
    Address p;
    int i, idx;

    /* ALGORITMA */
    idx = IDX_UNDEF;
    p = FIRST(l);
    i = 0;

    while ((p != NULL) && (idx == IDX_UNDEF)) {
        if (INFO(p) == val) {
            idx = i;
        } else {
            i++;
            p = NEXT(p);
        }
    }

    return idx;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = newNode(val);
    if (p != NULL) {
        NEXT(p) = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    /* KAMUS */
    Address p, last;

    /* ALGORITMA */
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            last = FIRST(*l);
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    /* KAMUS */
    Address p, loc;
    int ctr;

    /* ALGORITMA */
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            ctr = 0;
            loc = FIRST(*l);
            while (ctr < idx - 1) {
                ctr++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    p = FIRST(*l);
    *val = INFO(p);
    FIRST(*l) = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
    /* KAMUS */
    Address p, loc;

    /* ALGORITMA */
    p = FIRST(*l);
    loc = NULL;

    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }

    if (loc == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    /* KAMUS */
    Address p, loc;
    int ctr;

    /* ALGORITMA */
    if (idx == 0) {
        deleteFirst(l, val);
     } else {
        ctr = 0;
        loc = FIRST(*l);

        while (ctr < idx - 1) {
            ctr++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    /* KAMUS */
    Address p;

    /* ALGORITMA */
    printf("[");
    p = FIRST(l);
    while (p != NULL) {
        if (NEXT(p) == NULL) {
            printf("%d", INFO(p));
        } else {
            printf("%d,", INFO(p));
        }
        p = NEXT(p);
    }
    printf("]");
}

int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    /* KAMUS */
    Address p;
    int ctr;

    /* ALGORITMA */
    ctr = 0;
    p = FIRST(l);

    while (p != NULL) {
        ctr++;
        p = NEXT(p);
    }

    return ctr;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    /* KAMUS */
    Address p;
    List l3;

    /* ALGORITMA */
    CreateList(&l3);

    p = FIRST(l1);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    p = FIRST(l2);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    return l3;
}





///////////////////NODE//////////////////







/* File: node.c */
/* Implementasi Node */

#include "node.h"
#include <stdlib.h>

Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

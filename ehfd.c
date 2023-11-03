#include "set.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/
/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S){
    (*S).Count=Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S){
    return (S).Count == Nil;
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S){
    return S.Count==MaxEl;
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt){
    if (!IsMember((*S), Elmt)) {
        (*S).Elements[(*S).Count]=Elmt;
        (*S).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, infotype Elmt){
    int i;
    for (i=0; i < S->Count; i++){
        if (S->Elements[i] == Elmt){
            break;
        }
    }
    if (!(i==S->Count)) {
        if (S->Count > 1){
            for (i=i+1; i < S->Count; i++){
                S->Elements[i-1] = S->Elements[i];
            }
        }
        S->Count--;
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, infotype Elmt){
    for (int i=0; i<S.Count; i++){
        if ((S).Elements[i]==Elmt){
            return true;
        }
    }
    return false;
}

/* Mengembalikan true jika Elmt adalah member dari S */

Set SetUnion(Set s1, Set s2)
{
	int i;
	Set s3;
	CreateEmpty(&s3);
	for (i = 0; i < s1.Count; i++)
	{
		Insert(&s3, s1.Elements[i]);
	}

	// Just insert s2 without checker IsMember(), no duplicate will be added
	for (i = 0; i < s2.Count; i++)
	{
		Insert(&s3, s2.Elements[i]);
	}
	return s3;
}

Set SetIntersection(Set s1, Set s2)
{
	int i;
	Set s3;
	CreateEmpty(&s3);
	for (i = 0; i < s1.Count; i++)
	{
		if (IsMember(s2, s1.Elements[i]))
			Insert(&s3, s1.Elements[i]);
	}
	return s3;
}

Set SetSymmetricDifference(Set s1, Set s2)
{
	int i;
	Set s3;
	CreateEmpty(&s3);
	for (i = 0; i < s1.Count; i++)
	{
		if (!IsMember(s2, s1.Elements[i]))
			Insert(&s3, s1.Elements[i]);
	}
	for (i = 0; i < s2.Count; i++)
	{
		if (!IsMember(s1, s2.Elements[i]))
			Insert(&s3, s2.Elements[i]);
	}
	return s3;
}

Set SetSubtract(Set s1, Set s2)
{
	int i;
	Set s3;
	CreateEmpty(&s3);
	for (i = 0; i < s1.Count; i++)
	{
		if (!IsMember(s2, s1.Elements[i]))
			Insert(&s3, s1.Elements[i]);
	}
	return s3;
}




///////////////////////////////map/////////////////////////









#include "map.h"

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
    M->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return (M.Count == Nil);
}

boolean IsFull(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
    return (M.Count == MaxEl);
}

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
{
    int i;
    for (i=0; i < M.Count; i++){
        if (M.Elements[i].Key == k){
            break;
        }
    }
    if (i!=M.Count){
        return M.Elements[i].Value;
    } else {
        return Undefined;
    }
}

void Insert(Map *M, keytype k, valuetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (!IsMember((*M), k)){
        M->Elements[M->Count].Key = k;
        M->Elements[M->Count].Value = v;
        M->Count ++;
    }
}

void Delete(Map *M, keytype k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    int i;
    for (i=0; i < M->Count; i++){
        if (M->Elements[i].Key == k){
            break;
        }
    }
    if (!(i==M->Count)) {
        if (M->Count > 1){
            for (i=i+1; i < M->Count; i++){
                M->Elements[i-1].Key = M->Elements[i].Key;
                M->Elements[i-1].Value = M->Elements[i].Value;
            }
        }
        M->Count--;
    }
}

boolean IsMember(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    int i;
    for (i=0; i < M.Count; i++){
        if (M.Elements[i].Key == k) {
            return true;
        }
    }
    return false;
}






//////////////////////////maphash//////////////////////







#include "hashmap.h"
/**
 * Modul Hash HashMap
 * Implementasi Hash HashMap dengan Open Addressing
*/

// #define false 0
// #define true 1

/* Definisi HashMap M kosong : M.Count = Nil */
/* M.Count = jumlah element HashMap */
/* M.Elements = tempat penyimpanan element HashMap */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(HashMap *M){
	(*M).Count=Nil;

	for (int i=0; i<MaxEl; i++){
		(*M).Elements[i].Key=Undefined;
		(*M).Elements[i].Value=Undefined;
	}
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah HashMap M kosong berkapasitas MaxEl */
/* Ciri HashMap kosong : count bernilai Nil dengan seluruh isi key & value map Undefined */

/* *** Index Penyimpanan dengan modulo *** */
address Hash(keytype K){
	return (K%MaxEl);
}
/* Menghasilkan indeks penyimpanan dengan operasi modulo ke MaxEl */

/* ********** Operator Dasar HashMap ********* */
valuetype Value(HashMap M, keytype k){
	int i = Hash(k);
    while (M.Elements[i].Key != k) {
        if (M.Elements[i].Key == Undefined){
            break;
        } else {
            i++;
        }
    }
    if (M.Elements[i].Key == k) {
        return M.Elements[i].Value;
    } else {
        return Undefined;
    }
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void Insert(HashMap *M, keytype k, valuetype v){
	int i=Hash(k);
    while ((*M).Elements[i].Key != Undefined){
        if ((*M).Elements[i].Key == k){
            break;
        } else {
            i = (i+1)%MaxEl;
        }
    }
    if ((*M).Elements[i].Key == Undefined){
        (*M).Elements[i].Key = k;
        (*M).Elements[i].Value = v;
        (*M).Count++;
    } 
}
/* Menambahkan Elmt sebagai elemen HashMap M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan 
        index yang digunakan untuk menyimpan v adalah hash dari k
        gunakan open addressing linear probing dengan interval 1 jika index sudah terisi    */






///////////////duplicate//////////////





// NIM             : 18221048
// Nama            : Syafiq Ziyadul Arifin
// Tanggal         : 31 Oktober 2022
// Topik praktikum : Praktikum 8
// Deskripsi       : Implementasi dari duplicate.h

#include "duplicate.h"

Set arrToSet(int *arr, int arrSize)
{
	int i;
	Set S;
	CreateEmpty(&S);
	for (i = 0; i < arrSize; i++)
	{
		Insert(&S, arr[i]);
	}
	return S;
}

void removeDuplicateDesc(int *arr, int arrSize, int *arrRes, int *arrResSize)
{
	int i, j, temp;
	Set S = arrToSet(arr, arrSize);
	for (i = 0; i < S.Count; i++)
	{
		arrRes[i] = S.Elements[i];
	}
	*arrResSize = S.Count;

	// Sort set secara descending
	for (i = 0; i < S.Count; i++)
	{
		for (j = i; j < S.Count; j++)
		{
			if (arrRes[i] < arrRes[j])
			{
				temp = arrRes[i];
				arrRes[i] = arrRes[j];
				arrRes[j] = temp;
			}
		}
	}
}




///////////////union/////////////////




// NIM             : 18221048
// Nama            : Syafiq Ziyadul Arifin
// Tanggal         : 31 Oktober 2022
// Topik praktikum : Praktikum 8
// Deskripsi       : Implementasi fungsi UnionMap

#include "union_map.h"

Map UnionMap(Map m1, Map m2, boolean key_based)
{
	int i, j;
	infotype temp;
	Map m3;
	CreateEmpty(&m3);

	// Insert m1 first
	for (i = 0; i < m1.Count; i++)
	{
		Insert(&m3, m1.Elements[i].Key, m1.Elements[i].Value);
	}

	// Insert m2
	for (i = 0; i < m2.Count; i++)
	{
		Insert(&m3, m2.Elements[i].Key, m2.Elements[i].Value);
	}

	// Sort map secara ascending
	// key_based = true -> sort berdasarkan Key
	// key_based = false -> sort berdasarkan Value (tidak unik)
	//                      sort berdasarkan Key jika ada Value yg sama
	for (i = 0; i < m3.Count; i++)
	{
		for (j = i; j < m3.Count; j++)
		{
			temp = m3.Elements[i];
			if ((key_based && temp.Key > m3.Elements[j].Key) || (!key_based && temp.Value > m3.Elements[j].Value) || (!key_based && temp.Value == m3.Elements[j].Value && temp.Key > m3.Elements[j].Key))
			{
				m3.Elements[i] = m3.Elements[j];
				m3.Elements[j] = temp;
			}
		}
	}
	return m3;
}

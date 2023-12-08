1. Soal List
KAMUS UMUM
type ElType: integer
type Address: pointer to Node
type Node: < info: ElType,
next: Address >
type List: < first: Address >
Soal Bagian 1
Cari isEmpty, Average, Max Value, Min Value
function isEmpty(input L: List) -> boolean
-> L.first = Nil
function average(input L: List) -> float
Count: integer
Total: integer
if (IsEmpty(L)) then
-> 0
Else
Count <- 0
Total <- 0
P <- L.First
while P != Nil do
Count <- Count + 1
Total <- Total + P.info
P <- P.next
-> Total/Count
function averagerange(input L: List) -> float
Count: integer
Total: integer
if (IsEmpty(L)) then
-> 0
else
count <- 0
total <- 0
P <- L.First
while P != Nil do
if P.info > min and P.info < max then
count <- count + 1
total <- total + P.info
P <- P.next
-> total/count
function max(input L: List) -> integer
Max: integer
if (IsEmpty(L)) then
-> 0
else
P <- L.First
Max <- P.Info
while P != Nil do
If P.info > Max then
Max <- P.info
P <- P.next
-> Max
function min(input L: List) -> integer
Min: integer
if (IsEmpty(L)) then
-> 0
Else
P <- L.First
Min <- P.Info
while P != Nil do
If P.info < Max then
Min <- P.info
P <- P.next
-> Min
procedure InsertX (input/output L: List, input x: ElType, output idx: integer)
KAMUS DATA
prev, p, new : address
found : boolean
ALGORITMA
if (IsEmpty(L)) then
new ← Alokasi(x)
if (new ≠ Nil) then
First(L) ← new
idx ← 0
else
p ← First(L)
prev ← p
found ← false
idx ← 0
while (p ≠ Nil and not(found)) do
if (Info(p) >= x) then
found ← true
else
prev ← p
p ← Next(p)
idx ← idx + 1
if (Info(p) = x) then {sudah ada}
idx ← -1
else
new ← Alokasi(x)
if (new ≠ Nil) then
Next(new) ← p
if (idx = 0) then
First(L) ← new
else
Next(prev) ← new
2. Bagian 2
Queue dengan pointer
procedure Enqueue(input/output Q: Queue, input X: ElType)
KAMUS LOKAL
p : address
ALGORITMA
p <- Alokasi(X)
if (p != Nil) then
if (isEmpty(Q))
Addr_Head(Q) <- p
else
Next(Addr_Tail(Q)) <- p
Addr_Tail(Q) <- p
procedure Dequeque(input/output Q: Queue, output X: ElType)
KAMUS LOKAL
ALGORITMA
X <- Info(Q)
p <- Addr_Head(Q)
Addr_Head(Q) <- Next(Addr_Head(Q))
if (Addr_Head(Q) = Nil) then
Addr_Head(Q) <- Nil
Next(p) <- Nil
Dealokasi(p)
Priority Queue
#define Nil NULL
/* Deklarasi type elemen */
typedef int ElType;
/* Priority Queue dengan representasi berkait dengan pointer */
typedef struct tNode *address;
typedef struct tNode {
ElType info;
int prio;
address next;
} Node;
/* Type PrioQueue dengan HEAD */
typedef struct {
address addrHead; /* alamat elemen pertama */
} PrioQueue;
void enqueue(PrioQueue *q, ElType x, int pr){
/* Proses: Mengalokasi x dengan prio pr dan menambahkan x pada q
jika alokasi berhasil; jika alokasi gagal q tetap */
address P;
P = newNode(x, pr);
if (P != Nil){
if (isEmpty(*q)) ADDR_HEAD(*q) = P;
else{
address loc;
loc = ADDR_HEAD(*q);
if (PRIO(P) < PRIO(loc)) {
NEXT(P) = loc;
ADDR_HEAD(*q) = P;
}
else{
while ((NEXT(loc) != Nil) && (PRIO(P) >= PRIO(NEXT(loc)))){
loc = NEXT(loc);
}
NEXT(P) = NEXT(loc);
NEXT(loc) = P;
}
}
}
}
void dequeue(PrioQueue *q, ElType *x, int *pr){
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
address P,del;
*pr = PRIO(ADDR_HEAD(*q));
*x = HEAD(*q);
del = ADDR_HEAD(*q);
P = NEXT(del);
ADDR_HEAD(*q) = P;
delNode(del);
}
3. Binary Tree
boolean IsTreeEmpty (BinTree P){
/* Mengirimkan true jika P adalah pohon biner kosong */
return P == Nil;
}
boolean IsTreeOneElmt (BinTree P){
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
return !IsTreeEmpty(P) && (Left(P) == Nil) && (Right(P) == Nil);
}
boolean IsUnerLeft (BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri
*/
if(IsTreeEmpty(P)) return false;
else return Left(P) != Nil && Right(P) == Nil;
}
boolean IsUnerRight (BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon
kanan*/
if(IsTreeEmpty(P)) return false;
else return Left(P) == Nil && Right(P) != Nil;
}
boolean IsBiner (BinTree P){
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan
subpohon kanan*/
if(IsTreeEmpty(P)) return false;
else return Left(P) != Nil && Right(P) != Nil;
}
boolean SearchTree (BinTree P, infotype X){
/* Mengirimkan true jika ada node dari P yang bernilai X */
if(IsTreeEmpty(P)) return false;
else{
if (Akar(P) == X) return true;
else{
if (SearchTree(Left(P), X)) return true;
else return (SearchTree(Right(P), X));
}
}
}
int NbElmt (BinTree P){
/* Mengirimkan banyaknya elemen (node) pohon biner P */
if(IsTreeEmpty(P)) return 0;
else return 1 + NbElmt(Left(P)) + NbElmt(Right(P));
}
int NbDaun (BinTree P){
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
if(IsTreeEmpty(P)) return 0;
if(IsTreeOneElmt(P)) return 1;
else{
if (IsUnerLeft(P)) return NbDaun(Left(P));
else if (IsUnerRight(P)) return NbDaun(Right(P));
else return NbDaun(Left(P)) + NbDaun(Right(P));
}
}
boolean IsSkewLeft (BinTree P){
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
if (IsTreeEmpty(P)){
return true;
}
else if (IsTreeOneElmt(P)){
return true;
}
else{
return IsSkewLeft(Left(P)) && (Right(P) == Nil);
}
}
boolean IsSkewRight (BinTree P){
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
if (IsTreeEmpty(P)){
return true;
}
else if (IsTreeOneElmt(P)){
return true;
}
else{
return IsSkewRight(Right(P)) && (Left(P) == Nil);
}
}
int Level (BinTree P, infotype X){
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
if (Akar(P) == X) return 1;
else{
if(SearchTree(Left(P), X)) return 1 + Level(Left(P), X);
else if (SearchTree(Right(P), X)) return 1 + Level(Right(P), X);
}
}
int Tinggi (BinTree P){
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
Mengirim "height" yaitu tinggi dari pohon */
if(IsTreeEmpty(P)) return 0;
else{
if (Tinggi(Left(P)) > Tinggi(Right(P))) return 1 + Tinggi(Left(P));
else return 1 + Tinggi(Right(P));
}
}
void AddDaunTerkiri (BinTree *P, infotype X){
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
if (IsTreeEmpty(*P)) *P = Tree(X, Nil, Nil);
else AddDaunTerkiri(&Left(*P), X);
}
void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri){
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
sebagai anak Kanan X (jika Kiri = false) */
/* Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
if (IsTreeOneElmt(*P) && Akar(*P) == X)
if (Kiri) Left(*P) = Tree(Y, Nil, Nil);
else Right(*P) = Tree(Y, Nil, Nil);
else{
if (SearchTree(Left(*P), X)) AddDaun(&Left(*P), X, Y, Kiri);
else AddDaun(&Right(*P), X, Y, Kiri);
}
}
Function bSearch (BinTree p, x: ElType)
Soal A1. Realisasikan prosedur setElmt dengan spesifikasi yang diberikan di atas (􀆟dak perlu menulis ulang spesifikasi). Semua primi􀆟f lain yang disediakan dapat dipakai tanpa perlu direalisasikan. Jika perlu membuat fungsi/prosedur lain, buatlah definisi, spesifikasi, dan realisasinya.
procedure setElmt(input/output l: List, input idx: integer, input val:ElType)
{}
KAMUS LOKAL
p : Address
i : integer
ALGORITMA
p ← l
i ← 0
while (i < idx)
p ← p↑.next
i ← i + 1
{ i = idx }
p↑.info ← val
Soal A2. Realisasikan fungsi CountPos dengan spesifikasi yang diberikan di atas (􀆟dak perlu menulis ulang spesifikasi). Semua primi􀆟f lain yang disediakan dapat dipakai tanpa perlu direalisasikan. Jika perlu membuat fungsi/prosedur lain, buatlah definisi, spesifikasi, dan realisasinya.
func􀆟on CountPos(L: List) → integer
{}
KAMUS LOKAL
p : Address
count : integer
ALGORITMA
p ← l
count ← 0
while (p ≠ Nil) do
if (p↑.info > 0) then
count ← count + 1
p ← p↑.next
{ p = Nil }
→ count
Soal B1. Realisasikan procedure insertFirst dalam bahasa C dengan spesifikasi yang diberikan di atas (􀆟dak perlu menulis ulang spesifikasi). Semua primi􀆟f lain yang disediakan dapat dipakai tanpa perlu direalisasikan. Jika perlu membuat fungsi/prosedur lain, buatlah definisi, spesifikasi, dan realisasinya.
void insertFirst(List *l; ElType x)
{
Address p = Alokasi(x);
if (p != Nil) // berhasil dialokasi
{
if (isEmpty(*l))
{
First(*l) = p;
Last(*l) = p;
} else
{
Next(p) = First(*l);
Prev(First(*l)) = p;
First(*l) = p;
}
}
}
Soal B2. Realisasikan procedure insertLast dalam bahasa C dengan spesifikasi yang diberikan di atas (􀆟dak perlu menulis ulang spesifikasi). Semua primi􀆟f lain yang disediakan dapat dipakai tanpa perlu direalisasikan. Jika perlu membuat fungsi/prosedur lain, buatlah definisi, spesifikasi, dan realisasinya.
void insertLast(List *l; ElType x)
{
Address p = Alokasi(x);
if (p != Nil) // berhasil dialokasi
{
if (isEmpty(*l))
{
insertFirst(l, x);
} else
{
Prev(p) = Last(*l);
Next(Last(*l)) = p;
Last(*l) = p;
}
}
}
Soal B3. Realisasikan procedure deleteAt dalam bahasa C dengan spesifikasi yang diberikan di atas (􀆟dak perlu menulis ulang spesifikasi). Semua primi􀆟f lain yang disediakan dapat dipakai tanpa perlu direalisasikan. Jika perlu membuat fungsi/prosedur lain, buatlah definisi, spesifikasi, dan realisasinya.
void deleteAt(List *l; int idx)
{
int i = 0;
Address p = First(*l);
Address loc = First(*l);
ElType temp;
while (i < idx)
{
loc = p;
p = Next(p);
i += 1;
}
// i = idx
if (p == loc) // bisa jadi kasus satu elemen atau elemen pertama yang dihapus
{
deleteFirst(*l, &temp);
} else if (p == Last(*L))
{
deleteLast(*l, &temp);
} else
{
Prev(Next(p)) = loc;
Next(loc) = Next(p);
}
Dealokasi(p);
}
Soal C1. Realisasikan func􀆟on search dengan spesifikasi yang diberikan di atas (􀆟dak perlu menulis ulang spesifikasi). Semua primi􀆟f lain yang disediakan dapat dipakai tanpa perlu direalisasikan. Jika perlu membuat fungsi/prosedur lain, buatlah definisi, spesifikasi, dan realisasinya.
func􀆟on search (P: BinTree, X: ElType) --> boolean
{}
KAMUS LOKAL
p : Address
ALGORITMA
p <-- P
if (isOneElmt(p)) then
{ karena X yang dicari belum tentu ada pada Tree, maka infonya harus diperiksa terlebih dahulu }
if (p^.info = X) then
--> True
else
--> False
else
depend on p :
isUnerLe􀆟(p) : --> search(p^.le􀆟, X)
isUnerRight(p) : --> search(p^.right, X)
isBiner(p) : --> search(p^.le􀆟, X) or search(p^.right, X)
Soal C2. Realisasikan func􀆟on Level dengan spesifikasi yang diberikan di atas (􀆟dak perlu menulis ulang spesifikasi). Semua primi􀆟f lain yang disediakan dapat dipakai tanpa perlu direalisasikan. Jika perlu membuat fungsi/prosedur lain, buatlah definisi, spesifikasi, dan realisasinya.
func􀆟on Level (P: BinTree, X: ElType) --> integer
{}
KAMUS LOKAL
p : Address
ALGORITMA
p <-- P
if (isOneElmt(p)) then
if (p^.info = X) then
--> 1
else
depend on p :
isUnerLe􀆟(p) : --> 1 + Level(p^.le􀆟, X)
isUnerRight(p) : --> 1 + Level(p^.right, X)
isBiner(p) :
if (search(p^.le􀆟, X)) then
--> 1 + Level(p^.le􀆟, X)
else if (search(p^.right, X)) then
--> 1 + Level(p^.right)
Soal C3. Realisasikan fungsi isSkewLe􀆟 dengan spesifikasi yang diberikan di atas (􀆟dak perlu menulis ulang spesifikasi). Semua primi􀆟f lain yang disediakan dapat dipakai tanpa perlu direalisasikan. Jika perlu membuat fungsi/prosedur lain, buatlah definisi, spesifikasi, dan realisasinya.
func􀆟on isSkewLe􀆟 (p : BinTree) --> boolean
{}
KAMUS LOKAL
pt : Address
ALGORITMA
pt <-- p
if (isOneElmt(pt)) then
--> True
else
depend on p :
isUnerLe􀆟(p) : --> isSkewLe􀆟(p^.le􀆟)
isUnerRight(p) : --> False
isBiner(p) : --> (pt^.right = Nil and isSkewLe􀆟(pt^.le􀆟))
TREE
<<<<< SEARCH >>>>>
function search (P: BinTree, X: ElType) -> boolean
{ Mengirimkan true jika ada node dari P yang bernilai X }
KAMUS LOKAL
ALGORITMA
if (isTreeEmpty(P)) then { basis 0 }
-> false
else { rekurens }
if (P↑.info = X) then
→ true
else
→ search(P↑.left, X) or search(P↑.right, X)
<<<<< isSkewLeft >>>>>
function isSkewLeft(P: BinTree) → boolean
{ Mengirimkan true jika P adalah pohon condong kiri }
KAMUS LOKAL
ALGORITMA
if (isOneElmt(P)) then { basis 1 }
→ true
else { rekurens }
if ( not (IsTreeEmpty(P↑.right)) ) then
→ false
else
→ isSkewLeft(P↑.left)
<<<<< isSkewRight >>>>>
function isSkewRight(P: BinTree) → boolean
{ Mengirimkan true jika P adalah pohon condong kanan }
KAMUS LOKAL
ALGORITMA
if (isOneElmt(P)) then { basis 1 }
→ true
else { rekurens }
if ( not (isTreeEmpty(P↑.left)) ) then
→ false
else
→ isSkewRight(P↑.right)
<<<<< level >>>>>
function level (P: BinTree, X: ElType) → integer
{ Mengirimkan level dari node X yang merupakan salah satu daun dari pohon biner P.
Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. }
KAMUS LOKAL
ALGORITMA
if (isOneElmt(P)) then { Basis 1 }
→ 1
else { Rekurens }
if (search(P↑.left, X)) then
→ 1 + level(P↑.left)
else
→ 1 + level(P↑.right)
<<<<< addDaun >>>>>
procedure addDaun (input/output P: BinTree, input X,Y: ElType, input Kiri: boolean)
{ I.S. P tidak kosong, X adalah daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai
anak Kanan X (jika not Kiri). Jika ada lebih dari satu daun bernilai X, Y
ditambahkan pada daun paling kiri. }
KAMUS LOKAL
newNode : Address
ALGORITMA
newNode ← newTreeNode(Y)
if (isOneElmt(P)) then { Basis 1 }
if (Kiri) then
P↑.left ← newNode
else
P↑.right ← newNode
else { rekurens }
if (search(P↑.left, X)) then
→ addDaun(P↑.left, X, Y, Kiri)
else
→ addDaun(P↑.right, X, Y, Kiri)
<<<<< delDaun >>>>>
procedure delDaun (input/output P: BinTree, input X: ElType)
{ I.S. P tidak kosong, minimum 1 daun bernilai X }
{ F.S. Semua daun yang bernilai X dihapus dari P }
KAMUS LOKAL
ALGORITMA
if (isOneElmt(P)) then { Basis 1 }
if (P↑.info = X) then
dealokasi(P)
else { rekurens }
delDaun(P↑.left, X)
delDaun(P↑.right, X)
<<<<< bSearch >>>>>
function bSearch (p: BinTree, x: ElType) → boolean
{ Mengirimkan true jika ada node dari p (BST) yang bernilai x }
KAMUS LOKAL
ALGORITMA
if (isTreeEmpty(p)) then { basis-0 }
-> false
else { rekurens }
if (x = p^.info) then
-> true
else
if (x > p^.info) then
-> bSearch(p^.right, x)
else
-> bSearch(p^.left, x)
<<<<< isBTree >>>>>
function isBTree (p: BinTree) → boolean
{ Mengirimkan true jika p adalah balanced tree. Asumsi: p tidak kosong }
KAMUS LOKAL
ALGORITMA
if (isOneElmt(p)) then { basis-1 }
-> true
else { rekurens }
depend on p:
isUnerLeft(p): -> isOneElmt(p^.left)
isUnerRight(p): -> isOneElmt(p^.right)
isBiner(p): -> (isBTree(p^.left) and isBTree(p^.right))
<<<<< buildBST >>>>>
function buildBST (infos: array [0..99] of integer, nEff: integer) → BinTree
{ Mengirimkan BST yang semua elemennya ada di infos (tidak terurut dan tidak unik).
nEff adalah jumlah elemen infos yang terdefinisi, 0 jika kosong. }
KAMUS LOKAL
i : integer
new : ElType
pT : BinTree
ALGORITMA
pT <- Nil
if (nEff > 0)
new.key <- infos[0]
new.count <- 1
CreateTree(new, Nil, Nil, pT)
i <- 1
while (i < nEff) do
new.key <- infos[i]
new.count <- 1
insSearchTree(new, pT)
i <- i+1
-> pT
GRAPH
<<<<< searchNode >>>>>
function searchNode (g: Graph, x: integer) → AdrNode
{ mengembalikan address simpul dengan id=x jika sudah ada pada graph g,
NIL jika belum }
KAMUS LOKAL
p : AdrNode
found : boolean
ALGORITMA
p <- g.first
found <- false
while (p != Nil and not(found)) do
if (p^.id = x) then
found <- true
else
p <- p^.next
if (found) then
-> p
else
-> Nil
<<<<< searchEdge >>>>>
function searchEdge (g: Graph, prec: integer, succ: integer) → adrSuccNode
{ mengembalikan address trailer yang menyimpan info busur <prec,succ>
jika sudah ada pada graph g, NIL jika belum }
KAMUS LOKAL
found : boolean
pN : AdrNode
pSuc : AdrSuccNode
ALGORITMA
pN <- g.first
found <- false
while (pN != Nil and not(found)) do
if (pN^.id = prec) then
pSuc <- pN^.trail
while (pSuc != Nil and not(found)) do
if (pSuc^.succ^.id = succ) then
found <- true
else
pSuc <- pSuc^.next
else
pN <- pN^.next
if (found) then
-> pSuc
else
-> Nil
<<<<< insertNode >>>>>
procedure insertNode (input/output g: Graph, input x: integer, output pn: adrNode)
{ Menambahkan simpul x ke dalam graph g, jika alokasi x berhasil. }
{ I.S. g terdefinisi, x terdefinisi dan belum ada pada g. }
{ F.S. Jika alokasi berhasil, x menjadi elemen terakhir g, pn berisi
address simpul x. Jika alokasi gagal, g tetap, pn berisi NIL }
KAMUS LOKAL
p : AdrNode
ALGORITMA
pn <- newGraphNode(x)
if (pn != Nil)
p <- g.first
while (p^.next != Nil) do
p <- p^.next
p^.next <- pn
<<<<< insertEdge >>>>>
procedure insertEdge (input/output g: Graph, input prec, succ: integer)
{ Menambahkan busur dari prec menuju succ ke dalam G }
{ I.S. g, prec, succ terdefinisi. }
{ F.S. Jika belum ada busur <prec,succ> di g, maka tambahkan busur
<prec,succ> ke g. Jika simpul prec/succ belum ada pada g,
tambahkan simpul tersebut dahulu. Jika sudah ada busur <prec,succ>
di g, maka g tetap. }
KAMUS LOKAL
pNp, pNs : AdrNode
pSucc, pNSucc : AdrSuccNode
ALGORITMA
if (searchEdge(g, prec, succ) = Nil) then
pNp <- searchNode(g, prec)
if (pNp = Nil) then
insertNode(g, prec, pNp)
pNs <- searchNode(g, succ)
if (pNs = Nil) then
insertNode(g, succ, pNs)
pNSucc <- newSuccNode(pNs)
pSucc <- pNp^.trail
while (pSucc^.next != Nil) do
pSucc <- pSucc^.next
pSucc^.next <- pNSucc
pNs.nPred <- pNs.nPred + 1
<<<<< deleteNode >>>>>
procedure deleteNode (input/output g: Graph, input x: integer)
{ Menghapus simpul x dari g }
{ I.S. g terdefinisi, x terdefinisi dan ada pada g, jumlah simpul
pada g lebih dari 1. }
{ F.S. simpul x dan semua busur yang terhubung ke x dihapus
dari g. }
KAMUS LOKAL
pN, NLag : AdrNode
pSucc, SuccLag : AdrSuccNode
ALGORITMA
pN <- g.first
while (pN != Nil) do { iterasi ke semua node yang mungkin terhubung ke x }
pSucc <- pN^.trail
SuccLag <- pN^.trail
while (pSucc^.next != Nil) do { iterasi trail di node untuk mencari edge ke x }
if (pSucc^.succ^.id = x) then
SuccLag^.next <- pSucc^.next
SuccLag <- pSucc^.next
if (pSucc = pN^.trail) then
pN^.trail <- SuccLag
deallocSuccNode(pSucc)
pSucc <- SuccLag
else
SuccLag <- pSucc
pSucc <- pSucc^.next
pN <- pN^.next
pN <- g.first
NLag <- g.first
while (pN^.id != x) do { syarat while bisa gitu karena I.S. x terdefinisi dan ada pada g }
NLag <- pN
pN <- pN^.next
{ pN^.id = x }
pSucc <- pN^.trail
while (pSucc != Nil) do { menghapus semua succNode di trailnya node x }
pN^.trail <- pSucc^.next
dealoccSuccNode(pSucc)
pSucc <- pN^.trail
NLag^.next <- pN^.next
NLag <- pN^.next
if (pN = g.first) then
g.first <- NLag
deallocGraphNode(pN)
pN <- NLag
LINKED LIST
>>>>>>>>>> SOAL 1 <<<<<<<<<<<
function countPos(l: List) -> integer
{ menghitung banyaknya kemunculan bilangan positif dari sebuah list of integer l }
KAMUS LOKAL
ctr : integer
p : Address
ALGORITMA
ctr <- 0
p <- l
while (p ≠ NIL) do
if (p↑.info > 0) then
ctr <- ctr + 1
else { p↑.info <= 0 }
ctr <- ctr + 0
p <- p↑.next
-> ctr
>>>>>>>>>> SOAL 2 <<<<<<<<<<<
function max(l: list) -> integer
{ menghasilkan nilai maksimum dari suatu list of integer l yang tidak kosong }
KAMUS LOKAL
p : Address
max : integer
ALGORITMA
p <- l
max <- p↑.info
p <- p↑.next
while (p ≠ NIL) do
if (p↑.info > max) then
max <- p↑.info
else { p↑.info <= max }
max <- max + 0
p <- p↑.next
-> max
>>>>>>>>>> SOAL 3 <<<<<<<<<<<
function searchPos(l: List) -> address
{ menghasilkan address di mana nilai positif pertama ditemukan di list of integer l }
KAMUS LOKAL
found : boolean
p : Address
ALGORITMA
found <- false
p <- l
while (p ≠ NIL and not(found)) do
if (p↑.info > 0)
found <- true
else { p↑.info <= 0 }
p <- p↑.next
-> p
>>>>>>>>>> SOAL 4 <<<<<<<<<<<
procedure deleteNeg(input/output l: List)
{ menghapus semua elemen bernilai negatif (<0) pada sebuah list of integer l.
List l boleh kosong dan setiap elemen yang dihapus harus dilakukan dealokasi }
{ I.S. l sembarang, boleh kosong }
{ F.S. semua elemen negatif di l terhapus dan terdealokasi }
KAMUS LOKAL
p, lag : Address
ALGORITMA
p <- l
lag <- l
while (p ≠ NIL) do
if (p↑.info < 0) then
lag↑.next <- p↑.next
lag <- p↑.next
if (p = l) then
l <- lag
dealokasi(p)
p <- lag
else { p↑.info >= 0 }
lag <- p
p <- p↑.next
>>>>>>>>>> SOAL 5 <<<<<<<<<<<
procedure copyPos(input l1: List, output l2: List)
{ menyalin semua elemen bernilai positif (>0) dari sebuah list of integer l1 menjadi l2 }
{ I.S. l1 terdefinisi dan minimal berisi satu elemen dan l2 terdefinisi dan kosong }
{ F.S. l1 mungkin kosong dan l2 berisi semua elemen bernilai positif dari l1. l2 mungkin kosong }
KAMUS LOKAL
p1 : Address
ALGORITMA
CreateList(l2)
p1 <- searchPos(l1)
while (p1 ≠ NIL) do
insertLast(l2, p1↑.info)
{ atau bisa pakai insertFirst(l2, p1↑.info)
karena tidak dispesifikasikan bahwa urutan
nilai positif di l1 harus tetap dipertahankan di l2 }
{ operasi insertFirst lebih "murah" secara komputasi }
p1 <- searchPos(p1)
>>>>>>>>>> SOAL 6 <<<<<<<<<<<
procedure sortedInsert(input/output l: List, input x: ElType)
{ menambahkan sebuah elemen x pada sebuah list of integer l yang terurut menaik }
{ I.S. list l terdefinisi dan sudah terurut menaik, l mungkin kosong. x terdefinisi dan belum ada di l }
{ F.S. x dimasukkan menjadi elemen dari l dengan tidak mengubah keterurutan dari l }
KAMUS LOKAL
p : Address
found : boolean
insert_idx : integer
ALGORITMA
p <- l
found <- false
insert_idx <- 0
while (p ≠ NIL and not(found)) do
if (p↑.info > x) then
found <- true
else
p <- p↑.next
insert_idx <- insert_idx + 1
if (found) then
insertAt(l, x, insert_idx)
else { not found }
insertLast(l, x)
>>>>>>>>>> SOAL 7 <<<<<<<<<<<
procedure updateList(input x, y: infotype, input/output l: List)
{ menerima infotype x dan y dan sebuah list l dan kemudian mengganti elemen pertama l
yang bernilai x dengan y jika x ada di l. Jika x tidak ada di l, l tetap }
{ I.S. l terdefinisi, mungkin kosong }
{ F.S. Jika x ada di l, elemen pertama yang bernilai x diganti dengan y
Jika x tidak ada di l, l tetap }
KAMUS LOKAL
p : Address
idx : integer
ALGORITMA
idx <- indexOf(l, x)
if (idx ≠ IDX_UNDEF) then
setElmt(l, idx, y)
else { idx = IDX_UNDEF }
{ do nothing }
VARIASI LINKED LIST
<<<<< SOAL 1 >>>>>
procedure insertFirst(input/output l: List, input x: ElType)
{ I.S. List l terdefinisi dan mungkin kosong }
{ F.S. x menjadi info dari node yang ditunjuk oleh First dari l }
KAMUS LOKAL
nn : address
ALGORITMA
nn <- newNode(x)
if (nn ≠ NIL) then
if (isEmpty(l)) then
l.first <- nn
l.last <- nn
else { not isEmpty(l) }
nn↑.next <- l.first
l.first <- nn
<<<<< SOAL 2 >>>>>
procedure insertLast(input/output l: List, input x: ElType)
{ I.S. List l terdefinisi dan mungkin kosong }
{ F.S. x menjadi info dari node yang ditunjuk oleh Last dari l }
KAMUS LOKAL
nn : address
ALGORITMA
nn <- newNode(x)
if (nn ≠ NIL) then
if (not(isEmpty(l))) then
l.last↑.next <- nn
l.last <- nn
else { isEmpty(l) }
l.first <- nn
l.last <- nn
<<<<< SOAL 3 >>>>>
function search(l: List, x: ElType) -> boolean
{ mencari apakah sebuah nilai x terdapat dalam sebuah list l.
l adalah List yang mencatata elemen pertama (First) dan elemen terakhir (Last)
dan elemen terakhir adalah dummy.
List l mungkin kosong }
KAMUS LOKAL
p : address
found : boolean
ALGORITMA
found <- false
p <- l.first
while (not found and p↑.info ≠ l.last↑.info) do
if (p↑.info = x) then
found <- true
else
p <- p↑.next
→ found
QUEUE DENGAN LINKED LIST
/* Prototype manajemen memori */
address newNode(ElType x, int pr)
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x dan prio = pr,
atau NIL jika alokasi gagal */
{
address p = (address) malloc(sizeof(Node));
if (p!=NULL){
INFO(p) = x;
PRIO(p) = pr;
NEXT(p) = NULL;
}
return p;
}
void delNode(address P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
free(P);
}
boolean isEmpty(PrioQueue q)
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NIL and ADDR_TAIL(q)=NIL */
{
return (ADDR_HEAD(q)=NULL);
}
int length(PrioQueue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
{
int ctr=0;
address p = ADDR_HEAD(q);
if (p==NULL){
return 0;
} else {
ctr = 1;
while (NEXT(p) != NULL){
ctr++;
p = NEXT(p);
}
return ctr;
}
}
/*** Kreator ***/
void CreateQueue(PrioQueue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
{
ADDR_HEAD(*q) = NULL;
}
/*** Primitif Enqueue/Dequeue ***/
void enqueue(PrioQueue *q, ElType x, int pr)
/* Proses: Mengalokasi x dengan prio pr dan menambahkan x pada q
jika alokasi berhasil; jika alokasi gagal q tetap */
/* I.S. q mungkin kosong */
/* F.S. x menjadi elemen q sesuai dengan urutan prioritas */
{
address p = newNode(x, pr);
if (isEmpty(*q)){
ADDR_HEAD(*q) = p;
} else {
address current = ADDR_HEAD(*q);
address prev = ADDR_HEAD(*q);
if (NEXT(current) == NULL){
if (PRIO(current) <= PRIO(p)){
NEXT(current) = p;
} else {
NEXT(p) = ADDR_HEAD(*q);
ADDR_HEAD(*q) = p;
}
} else {
while (NEXT(current) != NULL && PRIO(current) <= PRIO(p)){
prev = NEXT(prev);
current = NEXT(current);
}
// if (NEXT(current) == NULL) {
// }
if (PRIO(current) > PRIO(p)) {
NEXT(p) = current;
NEXT(prev) = p;
} else {
NEXT(current) = p;
}
}
}
}
void dequeue(PrioQueue *q, ElType *x, int *pr)
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
*x = HEAD(*q);
*pr = PRIO(ADDR_HEAD(*q));
address new_head = NEXT(ADDR_HEAD(*q));
delNode(ADDR_HEAD(*q));
ADDR_HEAD(*q) = new_head;
}
POLINOM
addpol(polinom A, polinom B, polinom *C)
address p <- A
address q <- B
while (p != Nil and q != Nil) do
Suku tambahan
depend on p, q
p^.degree = qn.degree
tambahan.coef <- pa.coef + qn.coef
If (tambahan.coef != 0) then
tambahan.degree <- p^.degree
insertLast(*C, tambahan)
p <- p^.next
q <- q^.next
p^.degree > q^.degree
tambahan.coef <- p^.coef
tambahan.degree <- p^.degree
insertLast(*C, tambahan)
p <- p^.next
p^.degree < q^.degree
tambahan.coef <- q^.coef
tambahan.degree <- q^.degree
insertLast(*C, tambahan)
q <- q^.next
turunanpol(polinom)
address p <- A
while (p != Nil) do
p^.coef <- p^coef * p^degree
p^.degree <- p^.degree – 1
p<-next(p)

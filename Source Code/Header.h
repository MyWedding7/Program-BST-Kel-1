/* Header */
#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include "boolean.h"

#define Nil NULL
#define Info(P) (P)->info
#define Left(P) (P)->left
#define Parent(P) (P)->parent
#define Right(P) (P)->right
#define Count(P) (P)->count

typedef struct tElmtNode *address;
typedef struct{
	int key;
	char name[50];
}infotype;

typedef struct tElmtNode{
    infotype info;
    address left;
    address right;
}ElmtNode;
typedef address BinTree;


/*
	i.s 	: Node belum dialokasikan
	F.S 	: Mengembalikan node hasil alokasi, Jika alokasi berhasil, maka address tidak Nil 
	Author  : Gefi Sanjaya
*/
address Alokasi(infotype X);

/*
	i.s 	: Node belum dicek
	F.S 	: Mengembalikan true jika pohon kosong 
	Author  : M Aziz Taufiqurrahman
*/
boolean IsEmpty(BinTree P);

/*
	i.s 	: Node belum ditambahkan
	F.S 	: Menambahkan node baru
	Author  : M Aziz Taufiqurrahman
*/
BinTree Tambah_pegawai(BinTree* node, infotype x);

/*
	i.s 	: Node belum terbentuk
	F.S 	: Tree sudah terbentuk
	Author  : Fanny Putria Agustina
*/
void MakeTree(infotype X,BinTree L,BinTree R,BinTree *P);

/*
	i.s 	: P terdefinisi
	F.S 	: semua simpul P sudah terhapus
	Author  : Dhiya Fakhar nafi
*/
void HapusDaftarTree(BinTree *P);

/*
	i.s 	: alamat node yang dicari belum ditemukan
	F.S 	: Mengembalikan alamat node jika ditemukan
	Author  : Salma Syawala
*/
BinTree* search_byID(BinTree* root, int key);

/*
	i.s 	: Node masih terdefinisi
	F.S 	: Node sudah terhapus
	Author  : Nabiilah Nada Iswari
*/
BinTree* HapusPegawai(Node* root, int k);

/*
	i.s 	: Node belum tersusun secara PostOrder
	F.S 	: Node Sudah tersusun secara PostOrder 
	Author  : Diana Fauziah
*/
void PrintPostorder(BinTree P);

/*
	i.s 	: Node belum tersusun secara InOrder
	F.S 	: Node Sudah tersusun secara InOrder
	Author  : Anna Kurniaty
*/
void PrintInorder(BinTree P);

/*
	i.s 	: Node belum tersusun secara PreOrder
	F.S 	: Node Sudah tersusun secara PreOrder
	Author  : Difa 
*/
void PrintPreorder(BinTree P);

/*
	i.s 	: Semua daftar anak kanan belum terdefinisi
	F.S 	: Semua daftar anak kanan sudah terdefinisi
	Author  : 
*/
BinTree GetRight(BinTree P);

/*
	i.s 	: Semua daftar anak kiri belum terdefinisi
	F.S 	: Semua daftar anak kiri sudah terdefinisi
	Author  : 
*/
BinTree GetLeft(BinTree P);

/*
	i.s 	: 
	F.S 	: 
	Author  : 
*/
boolean IsUnerRight(BinTree P);

boolean IsUnerLeft(BinTree P);

BinTree Tree(infotype X,BinTree L,BinTree R);

// infotype GetAkar(BinTree P);

//void PrintTree(BinTree P);
//BinTree BuildBalanceTree(int n);
#endif

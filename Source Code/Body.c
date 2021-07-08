/* Body */
#ifndef TREE_C
#define TREE_C

#include "tree.h"
#include <string.h>
#include <stdio.h>
// #include "mesinkar1.h"

// extern char C1;
// extern char C2;

/* ***** Manajemen Memory ******* */
address Alokasi(infotype X)
{ /* menghasilkan address hasil alokasi sebuah Node */
	/* Jika alokasi berhasil, maka address tidak Nil  */
	/* Info(P)=X, Left(P)=Nil,Rigr(P)=Nil; Count(P)=0 */
	/* Jika alokasi gagal ; mengembalikan  Nil 	     */
	address P;

	P = (address)malloc(sizeof(ElmtNode));
	if (P != Nil)
	{
		strcpy(Info(P), X);
		Left(P) = Nil;
		Right(P) = Nil;
		Count(P) = 0;
		Parent(P) = Nil;
	}
	return P;
}

boolean IsEmpty(BinTree P)
{ /*  Mengembalikan true jika pohon kosong  */
	return (P == Nil);
}

BinTree Tambah_pegawai(BinTree* node, infotype x){
	 /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}

BinTree search_byID(BinTree root, int key){
	// Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
    	return root;
    
    // Key is greater than root's key
    if (root->key < key)
    	return search(root->right, key);
 
    // Key is smaller than root's key
    	return search(root->left, key);
}

BinTree* HapusPegawai(BinTree* root, int k){
	// Base case
    if (root == NULL)
        return root;
 
    // Recursive calls for ancestors of
    // node to be deleted
    if (root->key > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->key < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
 
    // We reach here when root is the node
    // to be deleted.
 
    // If one of the children is empty
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
 
    // If both children exist
    else {
 
        Node* succParent = root;
 
        // Find successor
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        // Copy Successor Data to root
        root->key = succ->key;
 
        // Delete Successor and return root
        delete succ;
        return root;
    }
}

void HapusDaftarTree(BinTree *P)
{ /* I.S  : P terdefinisi                          	*/
	/* F.S  : semua simpul P sudah ditulis / preorder	*/

	if (!IsEmpty(*P))
	{
		DestroyTree(&(Left(*P)));
		DestroyTree(&(Right(*P)));
		free(*P);
		*P = Nil;
	}
}


BinTree GetLeft(BinTree P)
{ /* Mengirimkan anak kiri dari pohon biner P yang tidak kosong */
	return Left(P);
}

BinTree GetRight(BinTree P)
{ /* Mengirimkan anak kanan dari pohon pohon biner P yang tidak kosong */
	return Right(P);
}

/* ***************** KONSTRUKTOR ****************  */

BinTree Tree(infotype X, BinTree L, BinTree R)
{ /* Menghasilkan sebuah pohon Biner dari A, L, dan R jika Alokasi berhasil */
	/* Menghasilkan pohon kosong Nil, jika alokasi gagal 			  */
	address P;
	P = Alokasi(X);
	if (P != Nil)
	{
		strcpy(Info(P), X);
		Left(P) = L;
		Right(P) = R;
		Parent(P) = P;
	}
	return (P);
}

void MakeTree(BinTree *P)
{ 
	P = Nill;
	P.left =Nill;
	
}

void PrintPreorder(BinTree P)
{ /* I.S  : P terdefinisi   					       */
	/* F.S  : semua simpul P sudah diproses secara Preorder; akar, kiri */
	/*        kanan (dengan Proses (P)) 				       */
	/* Basis : pohon kosong  : tidak ada yang diproses		       */
	/* Rekurens : Prosees Akar(P); Proses secara Preorder(Left(P));     */
	/*            Proses secara  Preorder(Right(P)); 		       */
	if (P != Nil)
	{
		printf("%s", Info(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
	}
}

void PrintInorder(BinTree P)
{ /* I.S  : P terdefinisi   					      */
	/* F.S  : semua simpul P sudah diproses secara Inorder; kiri, akar */
	/*        kanan (dengan Proses (P)) 				      */
	if (P != Nil)
	{
		Inorder(Left(P));
		printf("%s, ", Info(P));
		Inorder(Right(P));
	}
}

void PrintPostorder(BinTree P)
{ /* I.S  : P terdefinisi   					    */
	/* F.S  : semua simpul P sudah diproses secara Postorder; kiri,  */
	/* 	     kanan, akar (dengan Proses (P)) 			    */
	if (P != Nil)
	{
		Postorder(Left(P));
		Postorder(Right(P));
		printf("%s", Info(P));
	}
}

/* ********* PREDIKAT PENTING  **************  */
boolean IsUnerLeft(BinTree P)
{ /* Mengirimkan True jika pohon biner tidak kosong; P adalah pohon  */
	/* unerleft : hanya mempunyai subpohon kiri 			      */

	return ((Right(P) == Nil) && (Left(P) != Nil));
}

boolean IsUnerRight(BinTree P)
{ /* Mengirimkan True jika pohon biner tidak kosong; P adalah pohon  */
	/* unerright : hanya mempunyai subpohon kanan          	      */

	return ((Right(P) != Nil) && (Left(P) == Nil));
}

//boolean IsBiner(BinTree P)
//{ /* Mengirimkan true jika pohon biner tidak kosong; P adalah pohon */
//	/* biner : mempunyai subpohon kiri dan subpohon kanan 	     */
//	return ((Left(P) != Nil) && (Right(P) != Nil));
//}

/* ************* TRAVERSAL   ************* */



//void PrintTree(BinTree P)
//{ /* I.S  : P terdefinisi                          	*/
//	/* F.S  : semua simpul P sudah ditulis / preorder	*/
//	if (IsEmpty(P))
//	{
//		printf("()");
//	}
//	else
//	{
//		printf("(%s", Info(P));
//		PrintTree(Left(P));
//		PrintTree(Right(P));
//		printf(")");
//	};
//}

//address Search2(BinTree T, infotype X)
//{
//	address L, R;
//
//	if (T == Nil)
//	{
//		return Nil;
//	}
//	else
//	{
//		if (strcmp(Info(T), X) != 0)
//		{
//			L = Search2(Left(T), X);
//			if (L == Nil)
//				return Search2(Right(T), X);
//			else
//				return L;
//		}
//		else
//		{
//			return T;
//		};
//	};
//};

/* *********** MEMBENTUK BALANCE TREE ************* */

//BinTree BuildBalanceTree(int n)
//{ /* Menghasilkan sebuah balance tree dengan n node, nilai setiap */
//	/* node dibaca 						   */
//	/* Kamus */
//	address P;
//	infotype X;
//	int nL, nR;
//	BinTree L, R;
//
//	/* Algoritma */
//	if (n == 0)
//	{
//		return Nil;
//	}
//	else
//	{
//		printf("Masukkan data : ");
//		scanf(" %[^\n]", X);
//
//		printf("Test  -  test !\n");
//		P = Alokasi(X);
//		printf("test 2\n");
//		if (P != Nil)
//		{
//			printf("di dalam if \n");
//			nL = n / 2;
//			nR = n - nL - 1;
//			L = BuildBalanceTree(nL);
//			R = BuildBalanceTree(nR);
//			Left(P) = L;
//			Right(P) = R;
//			printf("selesai if \n");
//		}
//	}
//	return P;
//}

//void InsSearchTree(BinTree *P, infotype X)
//{ /* Menambahkan sebuah node X, ke  pohon biner pencarian P */
//	/* infotype terdiri dsari key dan count. Key menunjukkan  */
//	/* nilai unik, dan Count berapa kali muncul  ; */
//	/* Basis :  pohon kosong */
//	/* Rekurens  : jika pohon tidak kosong, insert  ke anak   */
//	/*         	   kiri jika nilai  < info(P); insert ke anak */
//	/*             kanan jika nilai > info(Akar); 	      */
//	/* Alokasi selalu berhasil 				      */
//	if (IsEmpty(*P))
//	{
//		MakeTree(X, Nil, Nil, &(*P));
//	}
//	else
//	{
//		if (strcmp(X, Info(*P)) == 0) // X == Info(*P)
//		{
//			Count(*P)++;
//		}
//		else
//		{
//			if (strcmp(X, Info(*P)) < 0) // X < Info(*P)
//			{
//				InsSearchTree(&(Left(*P)), X);
//			}
//			else
//			{ /* X > Info(P)  */
//				InsSearchTree(&(Right(*P)), X);
//			}
//		}
//	}
//}


#endif

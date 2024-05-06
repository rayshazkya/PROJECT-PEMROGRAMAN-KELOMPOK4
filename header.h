#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main_menu_admin ();
char Login_user (  char username [] ,  char password[] );
char Login_Admin (  char username [] ,  char password[] );
void main_menu_admin ();
void main_menu_user();
void kembali_main_admin(char back);
void kembali_main_user(char back);
void showlistPeminjaman();
int bacaDataBuku(Buku *daftar_buku);
void pinjamBuku(buku *daftar_buku, int jumlah_buku, int id_user, unsigned int id);
void kembalikanBuku(unsigned int id);
int tampilkanMenu();
void tambahBuku(struct Buku bukuArray[], int *jumlahBuku);
void hapusBuku(struct Buku bukuArray[], int *jumlahBuku, int id);
void editBuku(struct Buku bukuArray[], int *jumlahBuku, int id);
void simpanKeFile(struct Buku bukuArray[], int jumlahBuku);

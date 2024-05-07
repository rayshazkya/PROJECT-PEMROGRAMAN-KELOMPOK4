#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct buku {
    unsigned int id;
    char judul[100]; 
    char penulis[100];
    char penerbit[100];
    unsigned int halaman;
    unsigned int tahun_terbit;
    unsigned int jumlah_bukutersedia;
} buku;

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

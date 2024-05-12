#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_BOOKS 100
#define MAX 256
#define MAX_LINE 2048
#define FILENAME_SIZE 1024

// Definisi struktur untuk menyimpan data buku
typedef struct {
    unsigned int id;
    char judul[100];
    char penulis[100];
    char penerbit[100];
    unsigned int jumlah_halaman;
    unsigned int tahun_terbit;
    unsigned int jumlah_buku_tersedia;
} Buku;

// Definisi struktur untuk menyimpan data peminjaman buku
typedef struct {
    int id_user;
    unsigned int id_buku;
    char judul[100];
} BukuDipinjam;

// Fungsi untuk meminjam buku
void pinjamBuku(Buku *daftar_buku, int jumlah_buku, int id_user, unsigned int id);

// Fungsi untuk mengembalikan buku
void kembalikanBuku(unsigned int id_buku);

// Fungsi untuk menampilkan daftar buku yang tersedia
void showBukuTersedia( );
//int hitung_jumlah_buku(Buku *daftar_buku);

// Fungsi untuk menampilkan daftar peminjaman buku
void showlistPeminjaman();

// Fungsi untuk membaca data buku dari file


//admin 
char admin_Akses_buku_tambah ();
char admin_Akses_buku_hapus();


void editBuku();


//login dan menu
void fungsi_login_admin();
void fungsi_login_user();
void kembali_main_admin();
void kembali_main_user();
void main_menu_admin ();
void main_menu_user ();

//data akun
struct login
{
   char username [25];
   char password [25];
   
};
//struct untuk login
struct login akun_login [1];
Buku daftar_buku[MAX_BOOKS];

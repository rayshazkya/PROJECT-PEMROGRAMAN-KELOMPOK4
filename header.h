#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mendefinisikan struktur untuk menyimpan data buku
typedef struct {
    unsigned int id;
    char judul[100];
    char penulis[100];
    char penerbit[100];
    unsigned int jumlah_halaman;
    unsigned int tahun_terbit;
    unsigned int jumlah_buku_tersedia;
} Buku;

// Mendefinisikan struktur untuk menyimpan data peminjaman buku
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
void showBukuTersedia(Buku *daftar_buku, int jumlah_buku);

// Fungsi untuk menampilkan daftar peminjaman buku
void showlistPeminjaman();

// Fungsi untuk membaca data buku dari file
int bacaDataBuku(Buku *daftar_buku);


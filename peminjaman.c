#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

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
void pinjamBuku(Buku *daftar_buku, int jumlah_buku, int id_user, unsigned int id) {
    int k = -1;

    for (int i = 0; i < jumlah_buku; i++) {
        if (daftar_buku[i].id == id) {
            k = i;
            break;
        }
    }

    if (k == -1) {
        printf("Buku dengan ID %u tidak ditemukan.\n", id);
        return;
    }

    if (daftar_buku[k].jumlah_buku_tersedia > 0) {
        daftar_buku[k].jumlah_buku_tersedia--;
        printf("Buku '%s' berhasil dipinjam.\n", daftar_buku[k].judul);

        // Simpan data peminjaman buku
        BukuDipinjam buku_dipinjam;
        buku_dipinjam.id_user = id_user;
        buku_dipinjam.id_buku = daftar_buku[k].id;
        strcpy(buku_dipinjam.judul, daftar_buku[k].judul);

        // Tulis data peminjaman ke file listpeminjaman.txt
        FILE *file = fopen("listpeminjaman.txt", "a");
        if (file == NULL) {
            printf("Gagal membuka file untuk mencatat peminjaman.\n");
            return;
        }
        fprintf(file, "%d,%u,%s\n", buku_dipinjam.id_user, buku_dipinjam.id_buku, buku_dipinjam.judul);
        fclose(file);

    } else {
        printf("Maaf, buku '%s' sedang tidak tersedia.\n", daftar_buku[k].judul);
    }
}

// Fungsi untuk menampilkan daftar buku yang tersedia
void showAvailableBooks(Buku *daftar_buku, int jumlah_buku) {
    printf("Buku yang tersedia:\n");
    printf("ID Buku\tJudul\tPenulis\tPenerbit\tJumlah Halaman\tTahun Terbit\tJumlah Tersedia\n");
    for (int i = 0; i < jumlah_buku; i++) {
        printf("%u\t%s\t%s\t%s\t%u\t%u\t%u\n", 
                daftar_buku[i].id, 
                daftar_buku[i].judul, 
                daftar_buku[i].penulis, 
                daftar_buku[i].penerbit, 
                daftar_buku[i].jumlah_halaman, 
                daftar_buku[i].tahun_terbit, 
                daftar_buku[i].jumlah_buku_tersedia);
    }
}

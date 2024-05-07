#include <stdio.h>
#include "header.h"

// Fungsi untuk menampilkan daftar buku yang tersedia
void showBukuTersedia(Buku *daftar_buku, int jumlah_buku) {
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

// Fungsi untuk menampilkan daftar peminjaman buku
void showlistPeminjaman() {
    FILE *file = fopen("listpeminjaman.txt", "r");
    if (file == NULL) {
        printf("Belum ada buku yang dipinjam.\n");
        return;
    }

    printf("Daftar Buku yang Dipinjam:\n");
    printf("ID User\tID Buku\tJudul Buku\n");
    printf("------------------------------------------\n");

    int id_user;
    unsigned int id;
    char judul[100];

    while (fscanf(file, "%d,%u,%99[^\n]", &id_user, &id, judul) == 3) {
        printf("%d\t%u\t%s\n", id_user, id, judul);
    }

    fclose(file);
}

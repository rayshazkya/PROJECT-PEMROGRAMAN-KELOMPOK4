#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk menampilkan daftar buku yang tersedia
void showBukuTersedia(Buku *daftar_buku, int jumlah_buku) {
    printf("Buku yang tersedia:\n");
    printf("ID Buku\tJudul\t\tPenulis\t\tPenerbit\t\tJumlah Halaman\t\tTahun Terbit\t\tJumlah Tersedia\n");
    for (int i = 0; i < jumlah_buku; i++) {
        printf("ID Buku: %u\n", daftar_buku[i].id);
        printf("Judul Buku: %s\n", daftar_buku[i].judul);
        printf("Penulis: %s\n", daftar_buku[i].penulis);
        printf("Penerbit: %s\n", daftar_buku[i].penerbit);
        printf("Jumlah Halaman: %u\n", daftar_buku[i].jumlah_halaman);
        printf("Tahun Terbit: %u\n", daftar_buku[i].tahun_terbit);
        printf("Jumlah Tersedia: %u\n", daftar_buku[i].jumlah_buku_tersedia);
        printf("\n");
    }
}


// Fungsi untuk menampilkan daftar peminjaman buku
void showlistPeminjaman() {
    FILE *file = fopen("listpeminjaman.txt", "r");
    if (file == NULL) {
        printf("Belum ada buku yang dipinjam.\n");
        return;
    }

    printf("\nDaftar Buku yang Dipinjam:\n");
    printf("ID User\tID Buku\tJudul Buku\n");
    printf("----------------------------------------------------------------\n");

    BukuDipinjam buku_dipinjam;
    while (fscanf(file, "%d,%u,%99[^\n]", &buku_dipinjam.id_user, &buku_dipinjam.id_buku, buku_dipinjam.judul) == 3) {
        printf("ID User: %d\n", buku_dipinjam.id_user);
        printf("ID Buku: %u\n", buku_dipinjam.id_buku);
        printf("Judul Buku: %s\n", buku_dipinjam.judul);
        printf("================================================================\n");
    }

    fclose(file);
}
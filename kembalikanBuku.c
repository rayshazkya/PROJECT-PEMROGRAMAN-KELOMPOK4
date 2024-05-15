#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk mengembalikan buku
void kembalikanBuku(unsigned int id_buku) {
    FILE *fileInput = fopen("listpeminjaman.txt", "r");
    FILE *fileOutput = fopen("temp.txt", "w");

    if (fileInput == NULL || fileOutput == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    int id_user;
    unsigned int id;
    char judul[100];

    int bukuDitemukan = 0;

    while (fscanf(fileInput, "%d,%u,%99[^\n]", &id_user, &id, judul) == 3) {
        if (id == id_buku) {
            printf("Buku '%s' telah dikembalikan.\n", judul);
            bukuDitemukan = 1;
        } else {
            fprintf(fileOutput, "%d,%u,%s\n", id_user, id, judul);
        }
    }

    fclose(fileInput);
    fclose(fileOutput);

    remove("listpeminjaman.txt");
    rename("temp.txt", "listpeminjaman.txt");

    if (!bukuDitemukan) {
        printf("Buku dengan ID %u tidak ditemukan dalam daftar peminjaman.\n", id_buku);
    }
    kembali_main_user();
}

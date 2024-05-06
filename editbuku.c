#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk mengedit data buku berdasarkan ID
void editBuku(struct Buku buku[], int *jumlahBuku, int id) {
    int i, found = 0;
    // Mencari buku dengan ID yang sesuai
    for (i = 0; i < *jumlahBuku; i++) {
        if (buku[i].id == id) {
            found = 1;
            break;
        }
    }
    if (found) { // Jika buku ditemukan
        // Meminta pengguna untuk memasukkan data baru
        printf("Masukkan judul baru: ");
        scanf("%s", buku[i].judul);
        printf("Masukkan penulis baru: ");
        scanf("%s", buku[i].penulis);
        printf("Masukkan penerbit baru: ");
        scanf("%s", buku[i].penerbit);
        printf("Masukkan jumlah halaman baru: ");
        scanf("%d", &buku[i].jumlah_halaman);
        printf("Masukkan tahun terbit baru: ");
        scanf("%d", &buku[i].tahun_terbit);
        printf("Masukkan jumlah buku yang tersedia: ");
        scanf("%d", &buku[i].jumlah_tersedia);
        
        printf("Data buku dengan ID %d berhasil diubah.\n", id);
    } else {
        printf("Buku dengan ID %d tidak ditemukan.\n", id);
    }
}
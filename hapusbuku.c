#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk menghapus buku berdasarkan ID
void hapusBuku(struct Buku buku[], int *jumlahBuku, int id) {
    int i, found = 0;
    // Mencari buku dengan ID yang sesuai
    for (i = 0; i < *jumlahBuku; i++) {
        if (buku[i].id == id) {
            found = 1;
            break;
        }
    }
    if (found) { // Jika buku ditemukan
        // Menggeser array untuk menghapus buku yang dipilih
        for (; i < *jumlahBuku - 1; i++) {
            buku[i] = buku[i + 1];
        }
        (*jumlahBuku)--; // Mengurangi jumlah buku yang tersimpan
        printf("Buku dengan ID %d berhasil dihapus.\n", id);
    } else {
        printf("Buku dengan ID %d tidak ditemukan.\n", id);
    }
}
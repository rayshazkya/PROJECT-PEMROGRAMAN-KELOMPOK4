#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi menghapus buku berdasarkan ID
void hapusBuku(struct Buku buku[], int *jumlahBuku, int id) {
    int i, found = 0;
    //buku dicari dengan ID yang sesuai
    for (i = 0; i < *jumlahBuku; i++) {
        if (buku[i].id == id) {
            found = 1;
            break;
        }
    }
    if (found) { // Jika buku ditemukan
        //array digeser untuk menghapus buku yang dipilih
        for (; i < *jumlahBuku - 1; i++) {
            buku[i] = buku[i + 1];
        }
        (*jumlahBuku)--; // untuk mengurangi jumlah buku yang tersimpan
        printf("Buku dengan ID %d berhasil dihapus.\n", id);
    } else {
        printf("Buku dengan ID %d tidak ditemukan.\n", id);
    }
}

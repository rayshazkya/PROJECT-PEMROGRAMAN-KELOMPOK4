#include <stdio.h>
#include "header.h"

// Fungsi untuk menampilkan menu dan meminta input dari pengguna
int tampilkanMenu() {
    int choice;

    printf("\nPilih operasi yang ingin dilakukan:\n");
    printf("1. Tambah buku\n");
    printf("2. Hapus buku\n");
    printf("3. Edit buku\n");
    printf("4. Keluar\n");
    printf("Pilih: ");
    scanf("%d", &choice);
    return choice;
}


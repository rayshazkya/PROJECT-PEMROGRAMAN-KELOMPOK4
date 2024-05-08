#include <stdio.h>
#include "header.h"

// Fungsi untuk menampilkan menu dan meminta input dari user
int tampilkanMenu() {
    int pilihan;

    printf("\nPilih operasi yang ingin dilakukan:\n");
    printf("1. Tambah buku\n");
    printf("2. Hapus buku\n");
    printf("3. Edit buku\n");
    printf("4. Keluar\n");
    printf("Pilih: ");
    scanf("%d", &pilihan);
    return pilihan;
}


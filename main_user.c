#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAX_BOOKS 100

int bacaDataBuku(Buku *daftar_buku) {
    FILE *file = fopen("databuku.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file databuku.txt\n");
        exit(1);
    }

    int jumlah_buku = 0;
    while (fscanf(file, "%u \"%99[^\"]\" \"%99[^\"]\" \"%99[^\"]\" %u %u %u\n", 
                    &daftar_buku[jumlah_buku].id, 
                    daftar_buku[jumlah_buku].judul, 
                    daftar_buku[jumlah_buku].penulis, 
                    daftar_buku[jumlah_buku].penerbit, 
                    &daftar_buku[jumlah_buku].jumlah_halaman, 
                    &daftar_buku[jumlah_buku].tahun_terbit, 
                    &daftar_buku[jumlah_buku].jumlah_buku_tersedia) == 7) {
        jumlah_buku++;
    }
    fclose(file);
    return jumlah_buku;
}
int main() {
    Buku daftar_buku[MAX_BOOKS];
    int jumlah_buku = bacaDataBuku(daftar_buku);

    int pilihan;
    int id_user;
    unsigned int id_buku;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Lihat Buku Tersedia\n");
        printf("2. Pinjam Buku\n");
        printf("3. Lihat List Buku yang Terpinjam\n");
        printf("4. Kembalikan Buku\n");
        printf("0. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                showBukuTersedia(daftar_buku, jumlah_buku);
                break;
            case 2:
                printf("\nMasukkan ID User: ");
                scanf("%d", &id_user);

                printf("Masukkan ID Buku yang ingin dipinjam: ");
                scanf("%u", &id_buku);

                pinjamBuku(daftar_buku, jumlah_buku, id_user, id_buku);
                break;
            case 3:
                showlistPeminjaman();
                break;
            case 4:
                printf("\nMasukkan ID Buku yang ingin dikembalikan: ");
                scanf("%u", &id_buku);

                kembalikanBuku(id_buku);
                break;
            case 0:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Menu tidak valid.\n");
                break;
        }
    } while (pilihan != 0);

    return 0;
}

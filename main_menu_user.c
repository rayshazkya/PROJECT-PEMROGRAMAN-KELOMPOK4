#include <stdio.h>
#include "header.h"

#define MAX_BOOKS 100

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

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define MAX_LINE_LENGTH 1024

void showBukuTersedia() {
    Buku book[MAX];
    FILE *file = fopen("databuku.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Gagal membuka file databuku.txt\n");
        return;
    }
    printf("\n'id buku' 'judul buku' 'penulis' 'penerbit' 'jumlah halaman' 'tahun terbit' 'jumlah buku tersedia'\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    int i = 0;
    while (fscanf(file, "%u \"%[^\"]\" \"%[^\"]\" \"%[^\"]\" %u %u %u", //scan data dari file databuku.txt
                  &book[i].id, book[i].judul, book[i].penulis, book[i].penerbit,
                  &book[i].jumlah_halaman, &book[i].tahun_terbit, &book[i].jumlah_buku_tersedia) == 7) {
        printf("Buku %d:\n", i+1);
        printf("'%u' '%s' '%s' '%s' '%u' '%u' '%u'\n", book[i].id, book[i].judul, book[i].penulis, book[i].penerbit, book[i].jumlah_halaman, book[i].tahun_terbit, book[i].jumlah_buku_tersedia);
        i++;
    }

    fclose(file);
    main_menu_user();
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
    main_menu_user();
}

#include <stdio.h>
#include <stdlib.h>
#define maks 100
#include "header.h"

void  pinjambuku() {
    buku Buku[maks];
    int id;

    printf("Masukkan ID buku yang ingin Anda pinjam: ");
    scanf("%d", &id);
    FILE *file = fopen("databuku.txt", "r");
    if (file == NULL) {
        printf("error");
    }
    int index = 0;
   while (fscanf(file, "%u \"%99[^\"]\" \"%99[^\"]\" \"%99[^\"]\" %u %u %u", &Buku[index].id, Buku[index].judul, Buku[index].penulis, Buku[index].penerbit, &Buku[index].halaman, &Buku[index].tahun_terbit, &Buku[index].jumlah_bukutersedia) == 7 && index < maks) {
        if (id == Buku[index].id) {
            if (Buku[index].jumlah_bukutersedia > 0) {
                printf("Peminjaman berhasil\n");
                Buku[index].jumlah_bukutersedia--;
            } else {
                printf("Maaf, buku tidak ada stok lagi\n");
            }
            break;
        } else if (index = maks)
        {
        printf("Maaf, buku tidak ada di daftar kami\n");
        }
        index++;
        }
    fclose(file);
}
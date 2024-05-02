#include "header.c"
#include <stdio.h>

void showBuku(const struct buku * buku) {
    printf("Judul: %s\n", buku->judul);
    printf("Pengarang: %s\n", buku->penulis);
    printf("Penerbit: %s\n", buku->penerbit);
    printf("Jumlah Halaman: %d\n", buku->halaman);
    printf("Tahun Terbit: %d\n", buku->tahun_terbit);
    printf("Jumlah buku tersedia: %d\n", buku->jumlahbuku);
    printf("\n");
}

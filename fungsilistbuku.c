#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#define maks 100

void listbukuuser() {
    FILE *baca = fopen("databuku.txt", "r");
    buku Buku[maks];
    int count = 0;

    if (baca == NULL) {
        perror("Error opening file");
        return 1;
    }
   
    int w =0;
    while (fscanf(baca, "%u \"%99[^\"]\" \"%99[^\"]\" \"%99[^\"]\" %u %u %u", &Buku[count].id, Buku[count].judul, Buku[count].penulis, Buku[count].penerbit, &Buku[count].halaman, &Buku[count].tahun_terbit, &Buku[count].jumlah_bukutersedia) == 7 && count < sizeof(Buku)) {
    printf("\n**DATA BUKU ke -%d**\n", w+1);
    printf("id : %u\n", Buku->id);
    printf("Judul: %s\n", Buku->judul);
    printf("Pengarang: %s\n", Buku->penulis);
    printf("Jumlah Halaman: %u\n", Buku->halaman);
    printf("Penerbit: %s\n", Buku->penerbit);
    printf("Tahun Terbit: %u\n", Buku->tahun_terbit);
    printf("Jumlah buku yang tersedia: %u\n", Buku->jumlah_bukutersedia);
    w++;
    }
    printf("\n***Ushakan ingat id dan jumlah buku yang tersedia untuk peminjaman***\n");
    printf("Mau kembali? (home/keluar): "); char opsi[6];
    scanf("%s", opsi);
    if(strcmp("keluar",opsi)==0 ||(strcmp("Keluar",opsi )==0))
    {
        return EXIT_SUCCESS;
    }

    fclose(baca);
}
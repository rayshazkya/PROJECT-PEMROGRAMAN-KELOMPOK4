#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAX_BUKU 100 // jumlah maksimal buku yang dapat disimpan

// Fungsi menambahkan buku baru ke dalam array buku
void tambahBuku(){
struct Buku buku[];
int *jumlahBuku);
    if (*jumlahBuku < MAX_BUKU) { // array diperiksa apakah array buku belum penuh 
        // Meminta user untuk memasukkan data buku
        printf("Masukkan ID buku: ");
        scanf("%d", &buku[*jumlahBuku].id);
        getchar();
        printf("Masukkan judul buku: ");
        scanf("%[^\n]", buku[*jumlahBuku].judul);
        getchar();
        printf("Masukkan penulis buku: ");
        scanf("%[^\n]", buku[*jumlahBuku].penulis);
        getchar();
        printf("Masukkan penerbit buku: ");
        scanf("%[^\n]", buku[*jumlahBuku].penerbit);
        getchar();
        printf("Masukkan jumlah halaman: ");
        scanf("%d", &buku[*jumlahBuku].jumlah_halaman);
        getchar();
        printf("Masukkan tahun terbit: ");
        scanf("%d", &buku[*jumlahBuku].tahun_terbit);
        getchar();
        printf("Masukkan jumlah buku yang tersedia: ");
        scanf("%d", &buku[*jumlahBuku].jumlah_tersedia);
        getchar();
        
        (*jumlahBuku)++; // Menambahkan jumlah buku yang tersimpan
        printf("Buku berhasil ditambahkan.\n");
    } else {
        printf("Daftar buku sudah penuh.\n");
    }
}

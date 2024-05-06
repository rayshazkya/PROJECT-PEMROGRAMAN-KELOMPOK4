#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Buku {
    unsigned int id;
    char judul[100];
    char penulis[100];
    char penerbit[100];
    unsigned int jumlah_halaman;
    unsigned tahun_terbit;
    unsigned jumlah_tersedia;
};

//Deklarasi fungsi file menu_admin.c
int tampilkanMenu();

//Deklarasi fungsi file admin.c
void tambahBuku(struct Buku buku[], int *jumlahBuku);
void hapusBuku(struct Buku buku[], int *jumlahBuku, int id);
void editBuku(struct Buku buku[], int *jumlahBuku, int id);
void simpanKeFile(struct Buku buku[], int jumlahBuku);
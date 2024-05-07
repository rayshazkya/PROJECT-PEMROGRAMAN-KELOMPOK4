#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maks 100

typedef struct buku {
    unsigned int id;
    char judul[100]; 
    char penulis[100];
    char penerbit[100];
    unsigned int halaman;
    unsigned int tahun_terbit;
    unsigned int jumlah_bukutersedia;
} buku;

void  pinjambuku(); 
void listbukuuser();
#include "header.h"

typedef struct {
    unsigned int id_buku;
    char judul[n];
    char penulis[n];
    char penerbit[n];
    unsigned int jumlah_halaman;
    unsigned int tahun_terbit;
    unsigned int jumlah_buku_tersedia;
} daftar_buku;

void admin_Akses_buku() {
    FILE *buku_akses = fopen("daftarbuku.txt", "a+"); 
    if (buku_akses == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    int k; // jumlah data yg ingin di tambah
    printf("Berapa jumlah data buku yang ingin anda tambah? : ");
    scanf("%i", &k);
    daftar_buku buku[k];

    for (int i = 0; i < k; i++) {
        printf("--TAMBAH BUKU--\n");
        printf("id_buku: ");
        scanf("%u", &buku[i].id_buku);
        printf("judul: ");
        getchar();
        fgets(buku[i].judul, sizeof(buku[i].judul), stdin);
        printf("penulis: ");
        fgets(buku[i].penulis, sizeof(buku[i].penulis), stdin);
        printf("penerbit: ");
        fgets(buku[i].penerbit, sizeof(buku[i].penerbit), stdin);
        printf("jumlah halaman: ");
        scanf("%u", &buku[i].jumlah_halaman);
        printf("Tahun terbit: ");
        scanf("%u", &buku[i].tahun_terbit);
        printf("jumlah buku tersedia: ");
        scanf("%u", &buku[i].jumlah_buku_tersedia);

        // Write book data to file
        fprintf(buku_akses, "%u\n%s%s%s%u%u%u\n", 
                buku[i].id_buku, 
                buku[i].judul, buku[i].penulis, buku[i].penerbit, 
                buku[i].jumlah_halaman, 
                buku[i].tahun_terbit, 
                buku[i].jumlah_buku_tersedia);
    }

    fclose(buku_akses);
}

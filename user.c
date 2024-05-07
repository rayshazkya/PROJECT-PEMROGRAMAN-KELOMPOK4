#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

// Definisi struktur untuk menyimpan data buku
typedef struct {
    unsigned int id;
    char judul[100];
    char penulis[100];
    char penerbit[100];
    unsigned int jumlah_halaman;
    unsigned int tahun_terbit;
    unsigned int jumlah_buku_tersedia;
} Buku;

// Definisi struktur untuk menyimpan data peminjaman buku
typedef struct {
    int id_user;
    unsigned int id_buku;
    char judul[100];
} BukuDipinjam;

// Fungsi untuk meminjam buku
void pinjamBuku(Buku *daftar_buku, int jumlah_buku, int id_user, unsigned int id) {
    int k = -1;

    for (int i = 0; i < jumlah_buku; i++) {
        if (daftar_buku[i].id == id) {
            k = i;
            break;
        }
    }

    if (k == -1) {
        printf("Buku dengan ID %u tidak ditemukan.\n", id);
        return;
    }

    if (daftar_buku[k].jumlah_buku_tersedia > 0) {
        daftar_buku[k].jumlah_buku_tersedia--;
        printf("Buku '%s' berhasil dipinjam.\n", daftar_buku[k].judul);

        // Simpan data peminjaman buku
        BukuDipinjam buku_dipinjam;
        buku_dipinjam.id_user = id_user;
        buku_dipinjam.id_buku = daftar_buku[k].id;
        strcpy(buku_dipinjam.judul, daftar_buku[k].judul);

        // Tulis data peminjaman ke file listpeminjaman.txt
        FILE *file = fopen("listpeminjaman.txt", "a");
        if (file == NULL) {
            printf("Gagal membuka file untuk mencatat peminjaman.\n");
            return;
        }
        fprintf(file, "%d,%u,%s\n", buku_dipinjam.id_user, buku_dipinjam.id_buku, buku_dipinjam.judul);
        fclose(file);

    } else {
        printf("Maaf, buku '%s' sedang tidak tersedia.\n", daftar_buku[k].judul);
    }
}

// Fungsi untuk menampilkan daftar buku yang tersedia
void showBukuTersedia(Buku *daftar_buku, int jumlah_buku) {
    printf("Buku yang tersedia:\n");
    printf("ID Buku\tJudul\t\tPenulis\t\tPenerbit\t\tJumlah Halaman\t\tTahun Terbit\t\tJumlah Tersedia\n");
    for (int i = 0; i < jumlah_buku; i++) {
        printf("ID Buku: %u\n", daftar_buku[i].id);
        printf("Judul Buku: %s\n", daftar_buku[i].judul);
        printf("Penulis: %s\n", daftar_buku[i].penulis);
        printf("Penerbit: %s\n", daftar_buku[i].penerbit);
        printf("Jumlah Halaman: %u\n", daftar_buku[i].jumlah_halaman);
        printf("Tahun Terbit: %u\n", daftar_buku[i].tahun_terbit);
        printf("Jumlah Tersedia: %u\n", daftar_buku[i].jumlah_buku_tersedia);
        printf("\n");
    }
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
}


// Fungsi untuk mengembalikan buku
void kembalikanBuku(unsigned int id_buku) {
    FILE *fileInput = fopen("listpeminjaman.txt", "r");
    FILE *fileOutput = fopen("temp.txt", "w");

    if (fileInput == NULL || fileOutput == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    int id_user;
    unsigned int id;
    char judul[100];

    int bukuDitemukan = 0;

    while (fscanf(fileInput, "%d,%u,%99[^\n]", &id_user, &id, judul) == 3) {
        if (id == id_buku) {
            printf("Buku '%s' telah dikembalikan.\n", judul);
            bukuDitemukan = 1;
        } else {
            fprintf(fileOutput, "%d,%u,%s\n", id_user, id, judul);
        }
    }

    fclose(fileInput);
    fclose(fileOutput);

    remove("listpeminjaman.txt");
    rename("temp.txt", "listpeminjaman.txt");

    if (!bukuDitemukan) {
        printf("Buku dengan ID %u tidak ditemukan dalam daftar peminjaman.\n", id_buku);
    }
}

// Fungsi untuk membaca data buku dari file
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

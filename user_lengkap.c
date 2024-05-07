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

// Prototipe fungsi bacaDataBuku
int bacaDataBuku();

// Fungsi untuk meminjam buku
void pinjamBuku() {
    Buku daftar_buku[MAX_BOOKS];
    int jumlah_buku = bacaDataBuku();

    int id_user;
    unsigned int id_buku;

    printf("Masukkan ID User: ");
    scanf("%d", &id_user);

    printf("Masukkan ID Buku yang ingin dipinjam: ");
    scanf("%u", &id_buku);

    int k = -1;

    for (int i = 0; i < jumlah_buku; i++) {
        if (daftar_buku[i].id == id_buku) {
            k = i;
            break;
        }
    }

    if (k == -1) {
        printf("Buku dengan ID %u tidak ditemukan.\n", id_buku);
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
void showBukuTersedia() {
    FILE *baca = fopen("databuku.txt", "r");
    Buku Buku[MAX_BOOKS];
    int count = 0;

    if (baca == NULL) {
        perror("Error opening file");
        return;
    }
   
    int w =0;
    while (fscanf(baca, "%u \"%99[^\"]\" \"%99[^\"]\" \"%99[^\"]\" %u %u %u", &Buku[count].id, Buku[count].judul, Buku[count].penulis, Buku[count].penerbit, &Buku[count].jumlah_halaman, &Buku[count].tahun_terbit, &Buku[count].jumlah_buku_tersedia) == 7 && count < sizeof(Buku)) {
    printf("\n**DATA BUKU ke -%d**\n", w+1);
    printf("id : %u\n", Buku->id);
    printf("Judul: %s\n", Buku->judul);
    printf("Pengarang: %s\n", Buku->penulis);
    printf("Jumlah Halaman: %u\n", Buku->jumlah_halaman);
    printf("Penerbit: %s\n", Buku->penerbit);
    printf("Tahun Terbit: %u\n", Buku->tahun_terbit);
    printf("Jumlah buku yang tersedia: %u\n", Buku->jumlah_buku_tersedia);
    w++;
    }

    fclose(baca);
}

// Fungsi untuk menampilkan daftar peminjaman buku
void showListPeminjaman() {
    FILE *file = fopen("listpeminjaman.txt", "r");
    if (file == NULL) {
        printf("Belum ada buku yang dipinjam.\n");
        return;
    }

    printf("Daftar Buku yang Dipinjam:\n");
    printf("ID User\tID Buku\tJudul Buku\n");
    printf("------------------------------------------\n");

    BukuDipinjam buku_dipinjam;
    while (fscanf(file, "%d,%u,%99[^\n]", &buku_dipinjam.id_user, &buku_dipinjam.id_buku, buku_dipinjam.judul) == 3) {
        printf("%d\t%u\t%s\n", buku_dipinjam.id_user, buku_dipinjam.id_buku, buku_dipinjam.judul);
    }

    fclose(file);
}

// Fungsi untuk mengembalikan buku
void kembalikanBuku() {
    unsigned int id_buku;

    printf("Masukkan ID Buku yang ingin dikembalikan: ");
    scanf("%u", &id_buku);

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
int bacaDataBuku() {
    FILE *file = fopen("databuku.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file databuku.txt\n");
        exit(1);
    }

    Buku daftar_buku[MAX_BOOKS];
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
    int pilihan;

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
                showBukuTersedia();
                break;
            case 2:
                pinjamBuku();
                break;
            case 3:
                showListPeminjaman();
                break;
            case 4:
                kembalikanBuku();
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAX_BUKU 100 // Maksimum jumlah buku yang dapat disimpan

// Fungsi untuk menyimpan data buku ke dalam file
void simpanKeFile(struct Buku buku[], int jumlahBuku) {
    FILE *file = fopen("databuku.txt", "w");
    if (file == NULL) { // Memeriksa apakah file berhasil dibuka
        printf("Gagal membuka file.\n");
        return;
    }
    // Menulis data buku ke dalam file
    for (int i = 0; i < jumlahBuku; i++) {
        fprintf(file, "%d %s %s %s %d %d %d\n", buku[i].id, buku[i].judul, buku[i].penulis, buku[i].penerbit, buku[i].jumlah_halaman, buku[i].tahun_terbit, buku[i].jumlah_tersedia);
    }
    fclose(file); // Menutup file setelah selesai
}

int main() {
    struct Buku buku[MAX_BUKU]; // Array untuk menyimpan data buku
    int jumlahBuku = 0;
    FILE *file = fopen("databuku.txt", "r");
    if (file != NULL) {
        // Membaca data buku dari file jika ada
        while (fscanf(file, "%d %s %s %s %d %d %d", &buku[jumlahBuku].id, buku[jumlahBuku].judul, buku[jumlahBuku].penulis, buku[jumlahBuku].penerbit, &buku[jumlahBuku].jumlah_halaman, &buku[jumlahBuku].tahun_terbit, &buku[jumlahBuku].jumlah_tersedia) != EOF) {
            jumlahBuku++;
        }
        fclose(file);
    }
    
    int choice;
    int id;

    printf("Selamat datang di program admin buku!\n");

    // Menu utama
     do {
        choice = tampilkanMenu(); // Memanggil fungsi untuk menampilkan menu
        switch (choice) {
            case 1:
                tambahBuku(buku, &jumlahBuku);
                break;
            case 2:
                printf("Masukkan ID buku yang ingin dihapus: ");
                scanf("%d", &id);
                hapusBuku(buku, &jumlahBuku, id);
                break;
            case 3:
                printf("Masukkan ID buku yang ingin diubah: ");
                scanf("%d", &id);
                editBuku(buku, &jumlahBuku, id);
                break;
            case 4:
                simpanKeFile(buku, jumlahBuku); // Menyimpan data buku ke dalam file sebelum keluar
                printf("Terima kasih telah menggunakan program admin buku.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan pilih kembali.\n");
        }
    } while (choice != 4);

    return 0;
}

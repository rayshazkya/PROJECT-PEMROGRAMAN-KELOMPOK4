#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Fungsi untuk mengembalikan buku
void kembalikanBuku(unsigned int id_buku, Buku *daftar_buku, int jumlah_buku) {
    // Buka file input (listpeminjaman.txt) untuk membaca daftar peminjaman
    FILE *fileInput = fopen("listpeminjaman.txt", "r");
    // Buka file output (temp.txt) untuk menulis daftar peminjaman yang diperbarui
    FILE *fileOutput = fopen("temp.txt", "w");

    // Periksa apakah kedua file berhasil dibuka
    if (fileInput == NULL || fileOutput == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }

    int id_user;
    unsigned int id;
    char judul[100];
   
    // Inisialisasi variabel untuk menandai apakah buku telah ditemukan
    int bukuDitemukan = 0;
    int i = 0;

    // Baca baris-baris dari file listpeminjaman.txt
    while (fscanf(fileInput, "%d,%u,%99[^\n]", &id_user, &id, judul) == 3) {
        // Periksa apakah ID buku pada baris saat ini sesuai dengan ID buku yang ingin dikembalikan
        if (id == id_buku) {
            // Jika sesuai, tandai buku telah ditemukan dan tambahkan kembali jumlah buku yang tersedia
            printf("Buku '%s' telah dikembalikan.\n", judul);
            bukuDitemukan = 1;
            daftar_buku[i].jumlah_buku_tersedia++;
        } else {
            // Jika tidak sesuai, tulis baris tersebut ke file output (temp.txt)
            fprintf(fileOutput, "%d,%u,%s\n", id_user, id, judul);
        }
        i++;
    }

    // Tutup file input dan output
    fclose(fileInput);
    fclose(fileOutput);

    // Buka file databuku.txt dengan mode write ("w+")
    FILE *file_buku = fopen("databuku.txt", "w+");
    // Periksa apakah file berhasil dibuka
    if (file_buku == NULL) {
        printf("Gagal membuka file databuku.txt\n");
        return;
    }
    
    // Tulis kembali seluruh data buku ke dalam file databuku.txt
    for (int i = 0; i < jumlah_buku; i++) {
        fprintf(file_buku, "%u \"%s\" \"%s\" \"%s\" %u %u %u\n",
                daftar_buku[i].id, daftar_buku[i].judul, daftar_buku[i].penulis,
                daftar_buku[i].penerbit, daftar_buku[i].jumlah_halaman,
                daftar_buku[i].tahun_terbit, daftar_buku[i].jumlah_buku_tersedia);
    }
    // Tutup file databuku.txt
    fclose(file_buku);

    // Hapus file listpeminjaman.txt dan ganti namanya dengan temp.txt
    remove("listpeminjaman.txt");
    rename("temp.txt", "listpeminjaman.txt");

    // Jika buku tidak ditemukan dalam daftar peminjaman, cetak pesan kesalahan
    if (!bukuDitemukan) {
        printf("Buku dengan ID %u tidak ditemukan dalam daftar peminjaman.\n", id_buku);
    }

    // Kembali ke menu utama pengguna setelah proses selesai
    kembali_main_user();
}

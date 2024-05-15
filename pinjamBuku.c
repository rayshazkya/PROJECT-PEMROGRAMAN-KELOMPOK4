
#include "header.h"

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
        main_menu_user();

    } else {
        printf("Maaf, buku '%s' sedang tidak tersedia.\n", daftar_buku[k].judul);
    }
}

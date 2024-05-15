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

void pinjamBuku(Buku *daftar_buku, int jumlah_buku, int id_user, unsigned int id) {
    int k = -1; //menulis kembali ke file baru
    FILE *files = fopen("databukusemntr.txt", "w");

    // Cari buku berdasarkan ID
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
        for(int i =0; i < jumlah_buku; i++){
        daftar_buku[k].jumlah_buku_tersedia--; //mengurangi file
        fprintf(files,"%u \"%s %s %s %u %u %u\n", daftar_buku[i].id, 
                    daftar_buku[i].judul, 
                    daftar_buku[i].penulis, 
                    daftar_buku[i].penerbit, 
                    daftar_buku[i].jumlah_halaman, 
                    daftar_buku[i].tahun_terbit, 
                    daftar_buku[i].jumlah_buku_tersedia);
        }

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
    fclose(files);
}

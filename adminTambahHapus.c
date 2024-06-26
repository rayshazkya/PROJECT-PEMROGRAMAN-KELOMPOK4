#include "header.h"


char admin_Akses_buku_tambah ( ){
    FILE *buku_akses = fopen ("databuku.txt", "a+");
    int k; //jumlah data yg ingin di tambah
    printf ("Berapa jumlah data buku yang ingin anda tambah? : ");
    scanf("%i",&k);
    Buku buku[k];
    for (int i =0 ; i<k; i++){
    printf("--TAMBAH BUKU--\n");
    printf("id_buku: ");
    scanf(" %u",&buku[i].id);
    getchar();
    printf("\njudul: ");
    scanf("%[^\n]", buku[i].judul);
    getchar ();
    printf("\npenulis: ");
    scanf("%[^\n]", buku[i].penulis);
    getchar();
    printf("\npenerbit: ");
    scanf("%[^\n]", buku[i].penerbit);
    getchar();
    printf("\njumlah halaman: ");
    scanf("%u",&buku[i].jumlah_halaman);
    getchar();
    printf("\nTahun terbit: ");
    scanf("%u",&buku[i].tahun_terbit);
    getchar();
    printf("\njumlah buku tersedia: ");
    scanf("%u",&buku[i].jumlah_buku_tersedia);
    
    fprintf(buku_akses, "%u %s %s %s %u %u, %u", buku[i].id , buku[i].judul,buku[i].penulis,buku[i].penerbit,buku[i].jumlah_halaman,buku[i].tahun_terbit,buku[i].jumlah_buku_tersedia);
    fprintf(buku_akses , "\n"); 
    printf("Buku telah ditambahkan!");
    }

    fclose(buku_akses);
    main_menu_admin();
}

char admin_Akses_buku_hapus() {
    FILE *fileAsli = fopen("databuku.txt", "r");
    if (fileAsli == NULL) {
        printf("Gagal membuka file!\n");
        return 1;
    }

    FILE *fileSementara = fopen("temp_file.txt", "w");
    if (fileSementara == NULL) {
        printf("Gagal membuat file sementara!\n");
        fclose(fileSementara);
        return 1;
    }

    int hapusNomor; // mengganti baris
    printf("masukkan kode buku: ");
    scanf("%d",&hapusNomor);
    char baris[1024];
    int kode = 1000;
    //semua data dari databuku.txt di copy kecuali data yg id nya sama dengan id yang ingin di hapus
    while (fgets(baris, 1024, fileAsli) != NULL) {
        kode++;
        if (kode != hapusNomor) {
            fprintf(fileSementara, "%s", baris);
        }
    }

    fclose(fileAsli);
    fclose(fileSementara);

    
    if (remove("databuku.txt") != 0) {
        printf("Gagal menghapus file asli!\n");
        return 1;
    }
    if (rename("temp_file.txt", "databuku.txt") != 0) {
        printf("Gagal mengubah nama file sementara!\n");
        return 1;
    }

    printf("Buku berhasil di hapus!\n");
    main_menu_admin();
}

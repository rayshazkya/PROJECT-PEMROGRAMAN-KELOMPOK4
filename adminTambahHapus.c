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
    fprintf(buku_akses , "\n"); }

    fclose(buku_akses);
    main_menu_admin();
}

char admin_Akses_buku_hapus() {
    FILE *original_file = fopen("databuku.txt", "r");
    if (original_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    FILE *temp_file = fopen("temp_file.txt", "w");
    if (temp_file == NULL) {
        printf("Error creating temporary file!\n");
        fclose(original_file);
        return 1;
    }

    int delete_line_number; // mengganti baris
    printf("masukkan kode buku: ");
    scanf("%d",&delete_line_number);
    char line[1024];
    int line_number = 1000;
    //semua data dari databuku.txt di copy kecuali data yg id nya sama dengan id yang ingin di hapus
    while (fgets(line, 1024, original_file) != NULL) {
        line_number++;
        if (line_number != delete_line_number) {
            fprintf(temp_file, "%s", line);
        }
    }

    fclose(original_file);
    fclose(temp_file);

    
    if (remove("databuku.txt") != 0) {
        printf("Error deleting original file!\n");
        return 1;
    }
    if (rename("temp_file.txt", "databuku.txt") != 0) {
        printf("Error renaming temporary file!\n");
        return 1;
    }

    printf("Line deleted successfully!\n");
    main_menu_admin();
}


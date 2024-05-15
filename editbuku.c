
#include "header.h"

// fungsi edit buku
void editBuku() {
    FILE *file = fopen("databuku.txt", "r");
    FILE *temp = fopen("tempfile.txt", "w");
    if (file == NULL || temp== NULL){
        printf("Eror Mebuka file!");
        exit (EXIT_FAILURE);
    }
    
    int edit;
    int id = 1000;
    Buku buku[MAX_BOOKS];
    int i=0;
    int *jumlah_buku;
    
    printf("Masukkan ID buku yang ingin di edit: ");
    scanf("%d", &edit);
    

    char line[1024];
    
    while (fgets(line, 1024, file) != NULL) {
        id++;
        if (id != edit) {
            fprintf(temp, "%s", line); //jika id tidak sama maka akan di print ke temp
        }
        
        i++; //jika id sama , maka program memninta user memasukkan data buku 
        if (id == edit) {
            
            printf("\n--EDIT BUKU--\n");
            printf("ID buku: ");
            scanf("%d", &buku[i].id);
            getchar();
            printf("\nJudul: ");
            scanf("%[^\n]", buku[i].judul);
            getchar();
            printf("\nPenulis: ");
            scanf("%[^\n]", buku[i].penulis);
            getchar();
            printf("\nPenerbit: ");
            scanf("%[^\n]", buku[i].penerbit);
            getchar();
            printf("\nJumlah halaman: ");
            scanf("%u", &buku[i].jumlah_halaman);
            getchar();
            printf("\nTahun terbit: ");
            scanf("%u", &buku[i].tahun_terbit);
            getchar();
            printf("\nJumlah buku tersedia: ");
            scanf("%u", &buku[i].jumlah_buku_tersedia);
            getchar();
            
            fprintf(temp, "%d %s %s %s %u %u %u\n", buku[i].id, buku[i].judul, buku[i].penulis, buku[i].penerbit, buku[i].jumlah_halaman, buku[i].tahun_terbit, buku[i].jumlah_buku_tersedia);
        } 
    }
  
    fclose(file);
    fclose(temp);

     
    // databuku yang lama di hapus , kemudian di rename ,jdi tempfile= databuku baru

   if (remove("databuku.txt") != 0) {
        printf("Error deleting original file!\n");
        exit (EXIT_FAILURE);
    }

    if (rename("tempfile.txt", "databuku.txt") != 0) {
        printf("Error renaming temporary file!\n");
        exit (EXIT_FAILURE);
    }
   

    printf("Buku berhasil diedit!\n");
    main_menu_admin();
}

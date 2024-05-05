#include "header.h"
void kembali_main_admin(char back);
void kembali_main_user(char back);

void main_menu_admin (){
    int opt;
    printf("--MAIN MENU ADMIN--\n");
    printf("Pilih opsi aksi:\n1.Menambah\n2.Menghapus\n3.Mengedit\n aksi: ");
    scanf("%i",&opt);

    switch (opt)
    {
        case 1 : 
        printf("\n");
        admin_Akses_buku();
        printf("kembali ke menu utama (y) atau keluar (n) [y/n]?");
        char back;
        scanf("%c",&back);
        getchar();
        kembali_main_admin(back);
        break;
        

        case 2: 
        printf("opsi2");
        break;
    }


}

void main_menu_user (){
    int opt;
    printf("--MAIN MENU USER--\n");
    printf("Pilih opsi aksi:\n1.Melihat buku\n2.Meminjam buku\n3.Mengembalikan buku\n aksi: ");
    scanf("%i",&opt);

    switch (opt)
    {
        case 1 : 
        printf("\n");
        admin_Akses_buku();
        printf("kembali [y/n]?");
        char back;
        scanf("%c",&back);
        getchar();
        kembali_main_user(back);

        break;

        case 2: 
        printf("opsi2");
        break;
    }


}

void kembali_main_admin(char back){
    if (back == 'y' || back == 'Y'){
        main_menu_admin ();
    }
    else {
        EXIT_SUCCESS;
    }
}

void kembali_main_user(char back){
    if (back == 'y' || back == 'Y'){
        main_menu_user ();
    }
    else {
        EXIT_SUCCESS;
    }
}



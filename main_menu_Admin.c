#include "header.h"

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
        printf("kembali [y/n]?");
        char back;
        scanf("%c",&back);
        return main_menu_admin;
        break;

        case 2: 
        printf("opsi2");
        break;

        case 3: 
        printf("opsi 3");
        break;
    }
}
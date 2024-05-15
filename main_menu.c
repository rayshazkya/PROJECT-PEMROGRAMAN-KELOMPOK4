#include "header.h"


void main_menu_admin (){
    int opt;
    printf("\n--MAIN MENU ADMIN--\n");
    printf("Pilih opsi aksi:\n1.Menambah\n2.Menghapus\n3.Mengedit\n0.keluar\nAksi: "); 
    scanf("%i",&opt);
    
    switch (opt)
    {
        case 1 : 
        printf("\n");
        admin_Akses_buku_tambah();
        
        break;
        

        case 2: 
        printf("\n");
        admin_Akses_buku_hapus();
        
        break;

        case 3 :
        printf("\n");
        editBuku();
        
        break;

        case 0:
        printf("Terimakasih");
    }


}



void main_menu_user () {
    
    
    Buku buku[MAX_BOOKS];
    

    int pilihan;
    int id_user;
    unsigned int id_buku;
    int jumlah_buku = bacaDataBuku(daftar_buku);
    
        printf("\n--MENU USER--\n");
        printf("1. Lihat Buku Tersedia\n");
        printf("2. Pinjam Buku\n");
        printf("3. Lihat List Buku yang Terpinjam\n");
        printf("4. Kembalikan Buku\n");
        printf("0. Keluar\n");
        printf("Aksi: ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
            
                
                showBukuTersedia();
                
                break;
            case 2:
                printf("Id user harus dengan angka!");
                printf("\nMasukkan ID User: ");
                scanf("%d", &id_user);

                printf("Masukkan ID Buku yang ingin dipinjam: ");
                scanf("%u", &id_buku);

                pinjamBuku(daftar_buku, jumlah_buku, id_user, id_buku);
                
                break;
            case 3:
                showlistPeminjaman();
                
                break;
            case 4:
                printf("\nMasukkan ID Buku yang ingin dikembalikan: ");
                scanf("%u", &id_buku);
                kembalikanBuku(id_buku, daftar_buku, jumlah_buku);
                
                break;
            case 0:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Menu tidak valid.\n");
                break;
        }
   

}

    





//kembali ke main menu , semua sudah rampung
void kembali_main_admin(){
        printf("kembali ke menu utama (y) atau keluar (n) [y/n]?");
        char back;
        scanf("%c",&back);
        getchar();
    if (back == 'y' || back == 'Y'){
        main_menu_admin ();
    }
    else {
        EXIT_SUCCESS;
    }
}

void kembali_main_user(){
        printf("kembali ke menu utama (y) atau keluar (n) [y/n]?");
        char back;
        scanf("%c",&back);
        getchar();
    if (back == 'y' || back == 'Y'){
        main_menu_user ();
    }
    else {
        EXIT_SUCCESS;
    }
}

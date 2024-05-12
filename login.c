#include "header.h"

void fungsi_login_admin(){
    akun_login;
    FILE *akun = fopen("data_akun.txt","r");
    if (akun == NULL){
        printf("gagal membuka file!");
    }
    char username [MAX];
    char pass [MAX];

   for (int i = 0 ; i<2;i++){
     fscanf(akun, "%s %s", akun_login[i].username,akun_login[i].password);
     if( feof(akun)){
        break;
     }
   }

    printf("USERNAME: ");
    scanf ("%s",username);
    printf("PASSWORD: ");
    scanf("%s",pass);


   if ( strcmp (username,akun_login[0].username)== 0 && strcmp(pass,akun_login[0].password )==0){
        printf("Berhasil login");
        main_menu_admin();
    }
    else {
        printf("username atau password anda salah!");
        exit(EXIT_FAILURE);
    }
    fclose(akun);

}

void fungsi_login_user(){
    akun_login ;
    FILE *akun = fopen("data_akun.txt","r");
    if (akun == NULL){
        printf("gagal membuka file!");
    }
    char username [MAX];
    char pass [MAX];
    
   for (int i = 0 ; i<2;i++){
     fscanf(akun, "%s %s", akun_login[i].username,akun_login[i].password);
     if( feof(akun)){
        break;
     }
   }
    printf("USERNAME: ");
    scanf ("%s",username);
    printf("PASSWORD: ");
    scanf("%s",pass);


   if ( strcmp (username,akun_login[1].username)== 0 && strcmp(pass,akun_login[1].password )==0){
        printf("Berhasil login");
        main_menu_user();
    }
    else {
        printf("username atau password anda salah!");
        exit( EXIT_FAILURE);
    }
    fclose(akun);

}










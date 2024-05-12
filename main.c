#include"header.h"
#define n 256
#define MAX 256
//password dan akun telah tertera pada file data_akun.txt

int main () {
    char pick;
    char username [n] ; 
    char password[n];
    Buku daftar_buku[MAX_BOOKS];
    printf( "login akun Admin atau user ? [a/u] ");
    scanf(" %c", &pick);
    
    switch (pick) {
        case 'a':
            
            printf("\n--LOGIN ADMIN--\n");
            fungsi_login_admin();
            
            break;


        case  'u':
            
            printf("\n--LOGIN USER--\n");
            fungsi_login_user();
        
            
            break;

    }
  
}


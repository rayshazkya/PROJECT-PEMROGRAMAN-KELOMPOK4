#include "header.h"
#define n 256
//untuk user gunakan password : userlog
//untukk admin gunakan password : adminlog
//kalo emang klean mau buat file.txt untuk password dan username , tinggalkan comments di login.c
char Login_user (  char username [] ,  char password[] );
int main () {
    char pick;
    char username [n] ; 
    char password[n];
    printf( "login akun Admin atau user ? [a/u] ");
    scanf(" %c", &pick);
    
    switch (pick) {
        case 'a':
            Login_Admin (  username ,   password );
            break;

        case  'u':
            Login_user(  username  ,   password);
            break;

    }
  
}
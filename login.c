#include "header.h"
#include "header.c"
//username: pengguna
//password :userlog
char Login_user (  char username [] ,  char password[] ) {
    char pass [ ] = {"userlog"};
    printf ("--LOGIN USER--\n");
    printf("USERNAME: ");
    scanf (" %s", username);
    printf("\nPASSWORD: ");
     scanf (" %s", password);
    

    if (strcmp(password , pass ) == 0) {
         printf("Login success!!");
        
    }
    else {
        printf("ERROR!PASSWORD ATAU USERNAME SALAH!");
        EXIT_FAILURE;
    }
}

char Login_Admin (  char username [] ,  char password[] ) {
    char pass [ ] = {"adminlog"};
    printf ("--LOGIN ADMIN--\n");
    printf("USERNAME: ");
    scanf (" %s", username);
    printf("\nPASSWORD: ");
     scanf (" %s", password);
    

    if (strcmp(password , pass ) == 0) {
        printf("Login success!!");
        
    }
    else {
        printf("ERROR!PASSWORD ATAU USERNAME SALAH!");
        EXIT_FAILURE;
    }


}
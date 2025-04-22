#include "header.h"
#include <time.h> 

int main(){
    int choice;
    while(1){
    printf("============ SELAMAT DATANG ===========\n");
    printf("Apa yang ingin kamu lakukan\n");
    printf("(1) Urutkan angka\n");
    printf("(2) Urutkan kata\n");
    printf("(3) Keluar\n");
    printf("Masukkan pilihanmu: ");
    scanf("%d", &choice);

        if (choice == 1){
            handleNumericSorting();
        }
        else if(choice == 2){
            handleStringSorting();
        }
        else if(choice == 3){
            printf("Terima kasih sudah menggunakan program ini\n");
            break;
        }
        else {
            printf("Input invalid\n");
        }
    }

    return 0;
}
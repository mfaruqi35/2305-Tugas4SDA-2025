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
            printf("Belum tersedia\n");
        }
        else if(choice == 3){
            printf("Terima kasih sudah menggunakan program ini\n");
            break;
        }
        else {
            printf("Input invalid\n");
        }
    }

    // int* data = malloc(sizeof(int) * MAXSIZE);
    // if (data == NULL){
    //     printf("Memory allocation failed\n");
    //     return 1;
    // }

    // FILE* file = fopen("data_angka.txt", "r");
    // if (file == NULL){
    //     printf("File tidak ditemukan\n");
    //     return 1;
    // }

    // int count = 0;
    // while(fscanf(file, "%d", &data[count]) != EOF && count < MAXSIZE){
    //     count++;
    // }
    // fclose(file);

    // clock_t start = clock();

    // // bubbleSort(data, count);
    // // selectionSort(data, count);
    // // insertionSort(data, count);

    // clock_t end = clock();
    // double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // printArray(data, count);
    // printf("Total data dibaca: %d\n", count);
    // printf("Waktu eksekusi: %.6f detik\n", time_taken);
    // printMemoryUsage();
    
    // free(data);

    return 0;
}
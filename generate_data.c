#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_numbers(const char *filename, int count, int max_value){
    FILE *fp = fopen(filename, "w");
    if(!fp){
        perror("Teks file tidak dapat dibuat");
        return;
    }

    srand(time(NULL)); //Inisialisasi seed

    for (int i = 0; i< count; i++){
        int num = rand() % max_value;
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);
    printf("Teks file angka berhasil dibuat\n");
}

void random_word(char *word, int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyz"; 
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        word[i] = charset[key];
    }
    word[length] = '\0';
}

void generate_random_words(const char *filename, int count, int max_word_length) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("File tidak dapat dibuat");
        return;
    }

    srand(time(NULL));

    char word[100]; 
    for (int i = 0; i < count; i++) {
        int length = (rand() % (max_word_length - 3)) + 3; // panjang kata minimal 3
        random_word(word, length);
        fprintf(fp, "%s\n", word);
    }

    fclose(fp);
    printf("Teks file kata berhasil dibuat\n");
}

int main() {
    generate_random_numbers("data_angka.txt", 2000000, 2000000);
    generate_random_words("data_kata.txt", 2000000, 20);
    return 0;
} 
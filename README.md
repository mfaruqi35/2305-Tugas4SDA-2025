# 2305-Tugas4SDA-2025

## Muhammad Faruqi (2308107010005)

### Struktur Program
Program ini terdiri dari beberapa file utama:
- `main.c` - Program utama yang menjalankan menu
- `functions.c` - Implementasi semua fungsi sorting dan utilitas
- `header.h` - Deklarasi semua fungsi yang digunakan
- `generate_data.c`- Program untuk membuat data acak untuk pengujian

### Fitur Utama
Program ini mampu melakukan sorting (pengurutan) untuk dua jenis data:
1. Data angka (numerik)
2. Data kata (string)

### Algoritma Sorting yang Diimplementasikan
Program ini mengimplementasikan 6 algoritma sorting:
1. **Bubble Sort** - Membandingkan pasangan elemen berurutan
2. **Selection Sort** - Mencari elemen minimum dan menempatkannya di posisi yang tepat
3. **Insertion Sort** - Membangun array terurut secara bertahap
4. **Merge Sort** - Algoritma divide and conquer dengan penggabungan
5. **Quick Sort** - Algoritma divide and conquer dengan pemisahan
6. **Shell Sort** - Perbaikan dari insertion sort dengan perbandingan elemen berjarak

### Fungsi Utilitas
Program memiliki bebrapa fungsi utilitas penting:
- `readNumFromFile` - Membaca data angka dari file
- `readWordFromFile` - Membaca data kata dari file
- `printMemoryUsage` - Menampilkan penggunaan memori
- Fungsi untuk mengukur waktu ekseskusi

### Program Generate Data
File `generate_data.c` berisi program untuk membuat data uji:
- `generate_random_numbers`- Membuat file dengan angka acak
- `generate_random_words` - Membuat file dengan kata acak

### Cara Kerja Program
1. Program menampilkan menu utama dengan 3 pilihan
2. Jika memilih sort angka/kata, program akan:
- Meminta jumlah baris data yang ingin diurutkan
- Meminta algoritma sorting yang ingin digunakan
- Membaca data dari file yang sesuai
- Menjalankan algoritma sorting
- Menampilkan statistik (waktu eksekusi dan penggunaan memori)

3. Setelah selesai, program kembali ke menu utama

### Performa
Program akan menampilkan:
- Total data yang diurutkan
- Waktu eksekusi dalam detik
- Penggunaan memori dalam KB

Program didesain untuk menangani data dalam jumlah besar (hingga 2 juta entri) dan membandingkan efisiensi algoritma sorting yang berbeda.

Compile program dengan `gcc main.c functions.c header.h -o main -lpsapi`
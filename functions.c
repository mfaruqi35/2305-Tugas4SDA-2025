#include "header.h"

#define MAXSIZE 2000000 // Ukuran maksimum array yang dapat diproses (2 juta elemen)

/* NUMERIC SORTING - Bagian fungsi pengurutan data numerik*/
// Membaca data numerik dari file
int readNumFromFile(const char *filename, int* data, int maxsize, int rows){
  FILE *file = fopen(filename, "r");
  if (file == NULL){
    printf("file tidak ditemukan: %s\n", filename);
    return -1;
  }
  int count = 0;
  // Membaca data selama belum EOF dan belum mencapai batas
  while(fscanf(file, "%d", &data[count]) != EOF && count < maxsize && count < rows){
    count++;
  }
  fclose(file);
  return count; // Mengembalikan jumlah data yang berhasil dibaca
}

// Algoritma Bubble Sort - O(n^2)
// Metode pengurutan dengan membandingkan pasangan elemen bersebelahan
void bubbleSort(int array[], int size) {

  // loop untuk mengakses setiap elemen array
  for (int step = 0; step < size - 1; ++step) {
      
    // loop untuk membandingkan elemen array
    for (int i = 0; i < size - step - 1; ++i) {
      
      // membandingkan dua elemen array bersebelahan
      if (array[i] > array[i + 1]) {
        
        // menukar psisi jika elemen tidak dalam
        // urutan yang diinginkan
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

// Algoritma Selection Sort - O(n^2)
// Fungsi untuk menukar posisi dua elemen
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Metode pengurutan dengan mencari elemen minimum pada setiap iterasi
void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    // Mencari nilai minimum dalam array yang belum terurut
    for (int i = step + 1; i < size; i++) {

      // Memlih elemen minimum untuk tiap loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // Memempatkan elemen minimum pada posisi yang benar
    swap(&array[min_idx], &array[step]);
  }
}

// Algoritma Insertion Sort - O(n^2)
// Metode pengurutan dengan membangun array terurut satu pes satu
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Membandingkan key dengan setiap elemen di sebelah kirinya
    // sampai menemukan elemen yang lebih kecil
    while (j >=0 && key < array[j]) {
      array[j + 1] = array[j]; // Menggeser elemen ke kanan
      --j;
    }
    array[j + 1] = key; // Menempatkan key pada posisi yang benar
  }
}

// Algoritma Merge Sort - O(n log n)
// Menggabungkan dua subarray L dan M ke dalam arr
void merge(int arr[], int p, int q, int r) {

  // Membuat L ← A[p..q] dan M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int* L = (int*)malloc(n1 * sizeof(int));
  int* M = (int*)malloc(n2 * sizeof(int)); // Array sementara

  // Menyalin data ke array sementara
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Mempertahankan index saat ini dari subarray dan array utama
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Sampai kita mencapai ujung L atau M, pilih yang lebih besar di antara
  // elemen L dan M dan tempatkan pada posisi yang benar di A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

   // Ketika kita kehabisan elemen di L atau M,
  // ambil elemen yang tersisa dan masukkan ke A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
  free(L);
  free(M);
}

// Membagi array menjadi dua subarray, mengurutkannya dan menggabungkannya
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

     // m adalah titik di mana array dibagi menjadi dua subarray
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

     // Menggabungkan subarray yang telah diurutkan
    merge(arr, l, m, r);
  }
}

// Algoritma Quick Sort - O(n log n) rata-rata, O(n²) kasus terburuk
// Fungsi untuk menemukan posisi partisi
int partition(int array[], int low, int high) {
  
 // Memilih elemen paling kanan sebagai pivot
  int pivot = array[high];
  
  // Pointer untuk elemen yang lebih besar
  int i = (low - 1);

  // Melintasi setiap elemen array
  // membandingkannya dengan pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // Jika elemen yang lebih kecil dari pivot ditemukan
      // tukar dengan elemen yang lebih besar yang ditunjuk oleh i
      i++;
      
      // Menukar elemen di i dengan elemen di j
      swap(&array[i], &array[j]);
    }
  }

 // Menukar elemen pivot dengan elemen yang lebih besar di i
  swap(&array[i + 1], &array[high]);
  
 // Mengembalikan titik partisi
  return (i + 1);
}

// Fungsi utama Quick Sort yang memanggil partition
void quickSort(int array[], int low, int high) {
  if (low < high) {
    
   // Menemukan elemen pivot sehingga
    // elemen yang lebih kecil dari pivot ada di kiri pivot
    // elemen yang lebih besar dari pivot ada di kanan pivot
    int pi = partition(array, low, high);
    
     // Panggilan rekursif di kiri pivot
    quickSort(array, low, pi - 1);
    
     // Panggilan rekursif di kanan pivot
    quickSort(array, pi + 1, high);
  }
}

// Algoritma Shell Sort - Perbaikan dari Insertion Sort
void shellSort(int array[], int n) {
  // Mengatur ulang elemen pada setiap interval n/2, n/4, n/8, ...
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      // Insertion sort untuk interval tertentu
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}

// Menampilkan penggunaan memori saat ini
void printMemoryUsage() {
  PROCESS_MEMORY_COUNTERS memInfo;
  GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));

  SIZE_T physMemUsed = memInfo.WorkingSetSize;
  printf("Penggunaan memori: %.2f KB\n", physMemUsed / 1024.0);
}
  
// Handler untuk pengurutan data numerik
void handleNumericSorting(){
  int rows;
  printf("\nMasukkan jumlah baris data angka: ");
  scanf("%d", &rows);

  printf("\nPilih metode sorting:\n");
  printf("(1) Bubble Sort\n(2) Selection Sort\n(3) Insertion Sort\n(4) Merge Sort\n(5) Quick Sort\n(6) Shell Sort\n");
  int method;
  printf("Pilihan: ");
  scanf("%d", &method);

  // Alokasi memori untuk data
  int* data = malloc(sizeof(int) * MAXSIZE);
  if (data == NULL){
    printf("Memory allocation failed\n");
    return;
  }

  // Membaca data dari file
  int count = readNumFromFile("data_angka.txt", data, MAXSIZE, rows);
  if(count == -1){
    free(data);
    return;
  }

  // Mulai penghitungan waktu
  clock_t start = clock();

  // Memilih algoritma sorting yang akan digunakan
  switch (method) {
    case 1: bubbleSort(data, count); break;
    case 2: selectionSort(data, count); break;
    case 3: insertionSort(data, count); break;
    case 4: mergeSort(data, 0, count - 1); break;
    case 5: quickSort(data, 0, count - 1); break;
    case 6: shellSort(data, count); break;
    default:
        printf("Metode tidak valid\n");
        free(data);
        return;
  }

  // Akhir penghitungan waktu
  clock_t end = clock();
  double duration = (double)(end - start) / CLOCKS_PER_SEC;

  //Print 10 data pertama
  printf("Hasil sorting (10 pertama):\n");
  for (int i = 0; i < 10; i++) {
    printf("%d\n", data[i]);
  }
  printf("\n");
  printf("Data pertama: %d\n", data[0]);
  printf("Data terakhir: %d\n", data[count - 1]);
  printf("Total data yang disorting: %d\n", count);
  printf("Waktu eksekusi: %.6f detik\n", duration);
  printMemoryUsage();
  free(data);
}

/* WORDS SORTING - Bagian fungsi pengurutan data string */
// Membaca kata dari file teks
int readWordFromFile(const char* filename, char** data, int maxsize, int rows){
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
      printf("File tidak ditemukan: %s\n", filename);
      return -1;
  }

  int count = 0;
  char buffer[100];

  // Membaca kata baris per baris
  while (fgets(buffer, sizeof(buffer), file) != NULL && count < maxsize && count < rows) {
      buffer[strcspn(buffer, "\n")] = 0; // Menghapus karakter newline
      // Alokasi memori untuk setiap kata
      data[count] = malloc(strlen(buffer) + 1);
      if (data[count] != NULL)
          strcpy(data[count], buffer);
      count++;
  }

  fclose(file);
  return count; // Mengembalikan jumlah kata yang berhasil dibaca
}

// Bubble Sort untuk string
void bubbleSortString(char** arr, int n){
  for (int i = 0; i < n-1; i++)
      for (int j = 0; j < n-i-1; j++)
          // Bandingkan dua string menggunakan strcmp
          if (strcmp(arr[j], arr[j+1]) > 0) {
              char* temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1] = temp;
          }
}

// Selection Sort untuk string
void selectionSortString(char** arr, int n){
  for (int i = 0; i < n - 1; i++) {
      int minIdx = i;
      // Mencari string "terkecil" berdasarkan perbandingan leksikografis
      for (int j = i + 1; j < n; j++) {
          if (strcmp(arr[j], arr[minIdx]) < 0) {
              minIdx = j;
          }
      }
      if (minIdx != i) {
          char* temp = arr[i];
          arr[i] = arr[minIdx];
          arr[minIdx] = temp;
      }
  }
}

// Insertion Sort untuk string
void insertionSortString(char** arr, int n) {
  for (int i = 1; i < n; i++) {
      char* key = arr[i];
      int j = i - 1;
      // Geser elemen yang lebih besar dari key
      while (j >= 0 && strcmp(arr[j], key) > 0) {
          arr[j + 1] = arr[j];
          j--;
      }
      arr[j + 1] = key;
  }
}

// Merge untuk Merge Sort string
void mergeString(char** arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Alokasi array sementara
  char** L = malloc(n1 * sizeof(char*));
  char** R = malloc(n2 * sizeof(char*));

  // Salin data ke array sementara
  for (int i = 0; i < n1; i++) L[i] = arr[left + i];
  for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

  // Gabungkan array kembali
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
      if (strcmp(L[i], R[j]) <= 0) arr[k++] = L[i++];
      else arr[k++] = R[j++];
  }

  // Salin elemen yang tersisa
  while (i < n1) arr[k++] = L[i++];
  while (j < n2) arr[k++] = R[j++];

  // Bebaskan memori sementara
  free(L);
  free(R);
}

// Merge Sort untuk string
void mergeSortString(char** arr, int left, int right) {
  if (left < right) {
      int mid = left + (right - left) / 2;
      mergeSortString(arr, left, mid);       // Urutkan subarray kiri
      mergeSortString(arr, mid + 1, right);  // Urutkan subarray kanan
      mergeString(arr, left, mid, right);    // Gabungkan hasil
  }
}

// Partition untuk Quick Sort string
int partitionString(char** arr, int low, int high) {
  char* pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
      if (strcmp(arr[j], pivot) < 0) {
          i++;
          char* temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
      }
  }
  char* temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return i + 1;
}

// Quick Sort untuk string
void quickSortString(char** arr, int low, int high) {
  if (low < high) {
      int pi = partitionString(arr, low, high);
      quickSortString(arr, low, pi - 1);     // Urutkan elemen sebelum pivot
      quickSortString(arr, pi + 1, high);    // Urutkan elemen setelah pivot
  }
}

// Shell Sort untuk string
void shellSortString(char** arr, int n){
 // Atur interval secara bertahap: n/2, n/4, ..., 1
 for (int interval = n / 2; interval > 0; interval /= 2) {
  for (int i = interval; i < n; i++) {
      char* temp = arr[i];
      int j = i;

      // Insertion sort untuk elemen berjarak interval
      while (j >= interval && strcmp(arr[j - interval], temp) > 0) {
          arr[j] = arr[j - interval];
          j -= interval;
      }
      arr[j] = temp;
  }
}
}

// Handler untuk pengurutan data string
void handleStringSorting(){
  // Alokasi array pointer untuk data string
  char** data = malloc(sizeof(char*) * MAXSIZE);
  if(data == NULL){
    printf("Gagal alokasi memori untuk array pointer\n");
    return;
  }
  
  int rows;
  printf("Masukkan jumlah baris data kata: ");
  
  // Validasi input
  if (scanf("%d", &rows) != 1) {
      printf("Input tidak valid!\n");
      while (getchar() != '\n'); // Bersihkan buffer input
      free(data);
      return;
  }
  while (getchar() != '\n'); // Flush sisa input
  // printf("Rows: %d\n", rows);

  // Baca data dari file
  int count = readWordFromFile("data_kata.txt", data, MAXSIZE, rows);
  if (count == -1){
    free(data);
    return;
  }

  printf("\nPilih metode Sorting\n");
  printf("(1) Bubble Sort\n(2) Selection Sort\n(3) Insertion Sort\n(4) Merge Sort\n(5) Quick Sort\n(6) Shell Sort\n");
  int method;
  printf("Pilihan: ");
  scanf("%d", &method);
  while (getchar() != '\n'); // Flush input buffer

  // Mulai penghitungan waktu
  clock_t start = clock();

  // Pilih algoritma sorting
  switch (method) {
      case 1: bubbleSortString(data, count); break;
      case 2: selectionSortString(data, count); break;
      case 3: insertionSortString(data, count); break;
      case 4: mergeSortString(data, 0, count - 1); break;
      case 5: quickSortString(data, 0, count - 1); break;
      case 6: shellSortString(data, count); break;
      default:
          printf("Metode tidak valid\n");
          return;
  }

  // Akhir penghitungan waktu
  clock_t end = clock();
  double durasi = (double)(end - start) / CLOCKS_PER_SEC;
  
  // Kode untuk mencetak 10 data pertama
  printf("\nHasil sorting (10 pertama):\n");
  for (int i = 0; i < 10; i++) {
      printf("%s\n", data[i]);
  }
  
  // Menampilkan statistik hasil pengurutan
  printf("Total data yang disorting: %d\n", count);
  printf("Waktu eksekusi: %.6f detik\n", durasi);
  printMemoryUsage();

  // Bebaskan memori untuk setiap string
  for (int i = 0; i < count; i++) {
      free(data[i]);
  }
  free(data); // Bebaskan array pointer
}
#include "header.h"

#define MAXSIZE 2000000

/* NUMERIC SORTING */

// Generate Random Numbers
void generate_random_numbers(const char *filename, int count, int max_value){
    FILE *fp = fopen(filename, "w");
    if(!fp){
        perror("file tidak ditemukan");
        return;
    }

    srand(time(NULL)); //Inisialisasi seed

    for (int i = 0; i< count; i++){
        int num = rand() % max_value;
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);
}

// Read Data From File
int readNumFromFile(const char *filename, int* data, int maxsize){
  FILE *file = fopen(filename, "r");
  if (file == NULL){
    printf("file tidak ditemukan: %s\n", filename);
    return -1;
  }
  int count = 0;
  while(fscanf(file, "%d", &data[count]) != EOF && count < maxsize){
    count++;
  }
  fclose(file);
  return count;
}

// Bubble sort
// perform the bubble sort
void bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < size - 1; ++step) {
      
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {
      
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {
        
        // swapping occurs if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

// Selection sort
// function to swap the the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
}

// Insertion sort
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (j >=0 && key < array[j]) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

// Merge sort
// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
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

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
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
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Quick sort
// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

// Shell sort
void shellSort(int array[], int n) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}

// Print Array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// Print Memory Usage
void printMemoryUsage() {
  PROCESS_MEMORY_COUNTERS memInfo;
  GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));

  SIZE_T physMemUsed = memInfo.WorkingSetSize;
  printf("Penggunaan memori: %.2f KB\n", physMemUsed / 1024.0);
}
  
//Numeric Sorting
void handleNumericSorting(){
  int rows;
  printf("\nMasukkan jumlah baris data angka: ");
  scanf("%d", &rows);

  generate_random_numbers("data_angka.txt", rows, MAXSIZE);

  printf("\nPilih metode sorting:\n");
  printf("(1) Bubble Sort\n(2) Selection Sort\n(3) Insertion Sort\n(4) Merge Sort\n(5) Quick Sort\n(6) Shell Sort\n");
  int method;
  printf("Pilihan: ");
  scanf("%d", &method);

  int* data = malloc(sizeof(int) * MAXSIZE);
  if (data == NULL){
    printf("Memory allocation failed\n");
    return;
  }

  int count = readNumFromFile("data_angka.txt", data, MAXSIZE);
  if(count == -1){
    free(data);
    return;
  }
  clock_t start = clock();

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

  clock_t end = clock();
  double duration = (double)(end - start) / CLOCKS_PER_SEC;
  printArray(data, count);
  printf("Total data yang disorting: %d\n", count);
  printf("Waktu eksekusi: %.6f detik\n", duration);
  printMemoryUsage();
  free(data);
}

/* WORDS SORTING */
void random_word(char *word, int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyz"; 
    for (int i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        word[i] = charset[key];
    }
    word[length] = '\0';
}

// Generate Randow Words
void generate_random_words(const char *filename, int count, int max_word_length) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("File tidak dapat dibuka");
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
}

// Read Word from Text File
int readWordFromFile(const char* filename, char** data, int maxsize){
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File tidak ditemukan: %s\n", filename);
        return -1;
    }

    int count = 0;
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), file) != NULL && count < maxsize) {
        buffer[strcspn(buffer, "\n")] = 0; // hapus newline
        data[count] = malloc(strlen(buffer) + 1);
        if (data[count] != NULL)
            strcpy(data[count], buffer);
        count++;
    }

    fclose(file);
    return count;
}


void bubbleSortString(char** arr, int n){
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (strcmp(arr[j], arr[j+1]) > 0) {
                char* temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void selectionSortString(char** arr, int n){
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
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

void insertionSortString(char** arr, int n) {
    for (int i = 1; i < n; i++) {
        char* key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeString(char** arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char** L = malloc(n1 * sizeof(char*));
    char** R = malloc(n2 * sizeof(char*));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSortString(char** arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortString(arr, left, mid);
        mergeSortString(arr, mid + 1, right);
        mergeString(arr, left, mid, right);
    }
}

// Quick Sort Helpers
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

void quickSortString(char** arr, int low, int high) {
    if (low < high) {
        int pi = partitionString(arr, low, high);
        quickSortString(arr, low, pi - 1);
        quickSortString(arr, pi + 1, high);
    }
}

void handleStringSorting(){
    char** data = malloc(sizeof(char*) * MAXSIZE);
    if(data == NULL){
      printf("Gagal alokasi memori untuk array pointer\n");
      return;
    }
    
    int rows;
    printf("Masukkan jumlah baris data kata: ");
    
    if (scanf("%d", &rows) != 1) {
        printf("Input tidak valid!\n");
        while (getchar() != '\n'); // bersihkan buffer
        free(data);
        return;
    }
    while (getchar() != '\n'); // flush sisa input
    printf("Rows: %d\n", rows);

    generate_random_words("data_kata.txt", rows, 20);
    printf("Generate random words done\n");

    int count = readWordFromFile("data_kata.txt", data, MAXSIZE);
    if (count == -1){
      free(data);
      return;
    }

    printf("\nPilih metode Sorting\n");
    printf("(1) Bubble Sort\n(2) Selection Sort\n(3) Insertion Sort\n(4) Merge Sort\n(5)Quick Sort\n");
    int method;
    printf("Pilihan: ");
    scanf("%d", &method);
    while (getchar() != '\n'); // flush

    clock_t start = clock();

    switch (method) {
        case 1: bubbleSortString(data, count); break;
        case 2: selectionSortString(data, count); break;
        case 3: insertionSortString(data, count); break;
        case 4: mergeSortString(data, 0, count - 1); break;
        case 5: quickSortString(data, 0, count - 1); break;
        default:
            printf("Metode tidak valid\n");
            return;
    }

    clock_t end = clock();
    double durasi = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nHasil sorting (10 pertama):\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", data[i]);
    }
    printf("Total data yang disorting: %d\n", count);
    printf("Waktu eksekusi: %.6f detik\n", durasi);
    printMemoryUsage();

    for (int i = 0; i < count; i++) {
        free(data[i]);
    }
}

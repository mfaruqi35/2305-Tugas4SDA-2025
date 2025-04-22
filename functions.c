#include "header.h"

#define MAXSIZE 2000000

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
int readDataFromFile(const char *filename, int* data, int maxsize){
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
  printf("(1) Bubble Sort\n(2) Selection Sort\n(3) Insertion Sort\n(4) Merge Sort\n(5)Quick Sort\n");
  int method;
  printf("Pilihan: ");
  scanf("%d", &method);

  int* data = malloc(sizeof(int) * MAXSIZE);
  if (data == NULL){
    printf("Memory allocation failed\n");
    return;
  }

  int count = readDataFromFile("data_angka.txt", data, MAXSIZE);
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

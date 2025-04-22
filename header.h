#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <psapi.h>

#define MAXSIZE 2000000

// Generate Random Numbers
void generate_random_numbers(const char *filename, int count, int max_value);

// Generate Random Words
void random_word(char *word, int length);
void generate_random_words(const char *filename, int count, int max_word_length);

// Read Data From File
int readNumFromFile(const char *filename, int* data, int maxsize);
int readWordFromFile(const char* filename, char** data, int maxsize);

// Declare sorting functions

// Bubble sort
void bubbleSort(int array[], int size);
void bubbleSortString(char* arr[], int n);

// Selection sort
void swap(int *a, int *b);
void selectionSort(int array[], int size);
void selectionSortString(char* arr[], int n);

// Insertion sort
void insertionSort(int array[], int size);
void insertionSortString(char* arr[], int n);

// Merge sort

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r);
void mergeString(char* arr[], int left, int mid, int right);

// Run the merge sort
void mergeSort(int arr[], int l, int r);
void mergeSortString(char* arr[], int left, int right);

// Quick sort
// function to find the partition position
int partition(int array[], int low, int high);
int partitionString(char* arr[], int low, int high);

// Run the quick sort
void quickSort(int array[], int low, int high);
void quickSortString(char* arr[], int low, int high);

// Shell sort
void shellSort(int array[], int n);

// Print Array
void printArray(int array[], int size);

// Print Memory Usage
void printMemoryUsage();
  
//Handling Sorting
void handleNumericSorting();
void handleStringSorting();
#endif
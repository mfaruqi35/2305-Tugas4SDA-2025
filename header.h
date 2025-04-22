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

// Read Data From File
int readDataFromFile(const char *filename, int* data, int maxsize);

// Declare sorting functions

// Bubble sort
// perform the bubble sort
void bubbleSort(int array[], int size);

// Selection sort
// function to swap the the position of two elements
void swap(int *a, int *b);
void selectionSort(int array[], int size);

// Insertion sort
void insertionSort(int array[], int size);

// Merge sort
// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r);

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r);

// Quick sort
// function to find the partition position
int partition(int array[], int low, int high);

void quickSort(int array[], int low, int high);

// Print Array
void printArray(int array[], int size);

// Print Memory Usage
void printMemoryUsage();
  
//Numeric Sorting
void handleNumericSorting();
#endif
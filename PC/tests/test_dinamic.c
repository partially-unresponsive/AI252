#include <stdlib.h>
#include <stdio.h>
#include "timeit.h" // Credit to https://github.com/stephen-wang/ctimeit
#include <time.h>
#include <stdint.h>

int64_t** allocMatrix(size_t rows, size_t columns){ // rows = number lines, columns = number columns
  /* Dynamically allocates a matrix of rows x columns size, but does not give any of its elements values */
  int64_t** a = (int64_t **) malloc(rows * sizeof(int64_t*));
  if (a == NULL){ // Checks the matrix is allocated
    return NULL;
  }
  for (size_t i = 0; i < rows; i++){
    if (a[i] == NULL){ // Checks the array is allocated
      return NULL;
    } 
  }
  return a;
}

void printMatrix(int64_t** mat, size_t rows, size_t columns){
  /* Prints out a matrix of rows x columns size */
  for (size_t i = 0; i < rows; i++){
    for (size_t j = 0; j < columns; j++){
      printf("%ld\t", mat[i][j]);
      printf("\n");
    }
  }
  return;
}

void digits(int64_t num, size_t n, uint64_t* c){
  /* num = number (49642), n = num. digits (5), int* c = pointer to be written to ([4, 9, 6, 4, 2]) */
  for (size_t k = n; k >= 0; k--){
    c[k] = num % 10;
    num = num / 10;
  }
}

// TODO: Figure out how modulus (%) works for negative values

/* Ex. 4 Algoritmi de sortare */

void selectionSort(int64_t* arr, size_t n){
  // Generic selection sort algorithm
  int64_t i, j, min, aux;
  for (i = 0; i < n - 1; i++){
    min = i;
    for (j = i + 1; j < n; j++){
      if (arr[j] < arr[min]){
        min = j;
      }
    }
    if (min != i){
      aux = arr[i];
      arr[i] = arr[min];
      arr[min] = aux;
    }
  }
}


void insertionSort(int64_t* arr, size_t n){
  // Generic insertion sorting algorithm
  int64_t i, j, aux;
  for (i = 1; i < n; i++){
    j = i;
    while (j > 0 && arr[j-1] > arr[j]){
      aux = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = aux;
      j--;
    }
  }
}

void bubbleSort(int64_t* arr, size_t n){
  // TODO: Figure out how this works
  int ok = 1;
  size_t j = 0;
  int64_t aux;
  while (ok){
    ok = 0;
    j++;
    for (size_t i = 0; i < n - j; i++){
      if (arr[i] > arr[i + 1]){
        aux = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = aux;
        ok = 1;
      }
    }
  }
}

void shellSort(int64_t* arr, size_t n){
  // FIXME: This does not work.
  size_t i, j, h, x;
  h = 1;
  while (h < n){
    h = h*3 + 1;
  }
  while(h >= 1){
    h = h / 3;
    for (i = h; i < n; i++){
      x = arr[i];
      j = i;
      while (arr[j-h] > x){
        arr[j] = arr[j-h];
        j = j - h;
        if (j < h){
          break;
        }
        arr[j] = x;
      }
    }
  }
}

// Begin quickSort helper functions:

int64_t compare(const void* a, const void* b){
  /* 
     a < b  => res > 0
     a > b  => res < 0
     a == b => res = 0
  */
  return (*(int64_t*)a - *(int64_t*)b); // *(int64_t*)a == Turn the void pointer into a int64_t pointer, and then dereference it
}

void swap(int64_t* a, int64_t* b){
  int64_t temp = *a;
  *a = *b;
  *b = temp;
}

int64_t partition(int64_t* arr, int64_t low, int64_t high){
  // Initialize pivot to be the first element
  int64_t pivot = arr[low];
  int64_t i = low;
  int64_t j = high;

  while (i < j){
    // Find the first element greater than the pivot (from starting)
    while (arr[i] <= pivot && i <= high - 1){
      i++;
    }

    // Find the first element smaller than the pivot (from last)
    while (arr[j] > pivot && j >= low + 1){
      j--;
    }
    if (i < j){
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[low], &arr[j]);
  return j;
}

void quickSort(int64_t* arr, int64_t low, int64_t high){
  if (low < high){
    // Call partition function to find partition index (j)
    int64_t pi = partition(arr, low, high);

    // Recursively call quickSort() for left and right half based on pi
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// End quickSort helper functions


void merge(int64_t* arr, size_t l, size_t m, size_t r){
  size_t i, j, k; // Index variables for L, R, and arr vectors
  size_t n1 = m - l + 1; // End index for L?
  size_t n2 = r - m; // End index for R?

  // Create temp arrays
  int64_t L[n1], R[n2]; // L[] is the left array, and R[] is the right array. They should recursively merge until they are sorted

  // Copy data to temp arrays L[] and R[]
  for (i = 0; i < n1; i++){
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++){
    R[j] = arr[m + 1 + j];
  }

  // Merge the temp arrays back into arr[l..r]
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2){
    if (L[i] <= R[j]){ // If the left temp array's element is smaller, place that in the sorted array 
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j]; // Otherwise, the right temp array's element goes there
      j++;
    }
    k++; // We advance arr's index regardless 
  }

  // Copy the remaining elements of L[], if there are any
  while (i < n1){
    arr[k] = L[i];
    i++;
    k++;
  }

  // Same with R[]
  while (j < n2){
    arr[k] = R[j];
    j++;
    k++;
  }
  return;
}

void mergeSort(int64_t* arr, size_t l, size_t r){
  // l => starting index (0), r => ending index (arr_size - 1)
  // Popular merge sorting algorithm, known for its efficiency and stability
  // Recursive implementation 
  if (l < r){ // Only perform the sort if start < end for the indexes, which should usually be the case unless array OOB
    size_t m = l + (r - l) / 2; // m => The middle point of the split, will probably floor() the value rather than ceil() it, so an array of 7 indices will get split into a size of 3 and 4
    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r); // This is why we need the l and r variables: we don't perform the merging operation on the *entire* array, just on both halves of it consecutively

    merge(arr, l, m, r); // And then we simply merge them together, basically:
    // 1. Start off with the untouched elements of arr*
    // 2. Then from index l, add elements of min(L[i], R[j])
    // 3. Do this until you reach arr[arr_size - 1], aka arr[untouched_array_size + (r - l)]
  }
  return;
}

void resetArray(int64_t* arr){
  int64_t dummy[10] = {3, -4, 8, -12, 503, -32, 44, 12, 950, 420};
  for (size_t i = 0; i < 10; i++){
    arr[i] = dummy[i];
  }
}


void printArray(int64_t* arr, size_t n){ // Ex. 5
  for (size_t i = 0; i < n; i++){
    printf("%ld  ", arr[i]);
  }
  printf("\n");
}

int64_t* RNGArray(size_t n){
  /* Dynamically fills an array of size n with pseudo-random values <= 1000 */
  int64_t* tmp = (int64_t *) malloc(n * sizeof(int64_t));
  if (tmp == NULL){ // The array wasn't initialized correctly
    return NULL;
  }
  for (size_t i = 0; i < n; i++){
    tmp[i] = rand() % 1000; // The magic happens here
  }
  return tmp; // Returns a pointer!
}

void XSortTesting(int n, char t){
  int64_t* arr = RNGArray(n);
  if (arr == NULL){
    printf("[ERROR]: Dynamic array failed to initialize.\n");
  } else {
    switch (t) {
      case 'm':
        mergeSort(arr, 0, n - 1);
        break;
      case 'q':
        quickSort(arr, 0, n - 1);
        break;
      case 'b':
        bubbleSort(arr, n);
        break;
      case 's':
        selectionSort(arr, n);
        break;
      case 'i':
        insertionSort(arr, n);
        break;
      default:
        printf("[ERROR]: Sorting algorithm not defined.\n");
    }
    free(arr); // Ex. 6
    arr = NULL;
  }
}

int main(){
  srand(time(NULL));
  int n = 1000; // Number of values in each array

  // TODO: Create my own marks (similar to TODO:) which light up in different colors, like DONE: (green highlight) for completed tasks and RANT: (black highlight) for rants (they will be necessary :p)

  // Using the timeit.h module from https://github.com/stephen-wang/ctimeit/blob/59cda8c5831d704a96a0664a36280af05c0f74e7/timeit.h
  printf("RepeatCount: ");
  int repeatCount;
  scanf("%d", &repeatCount);
  
  printf("MergeSort: ");
  timeit(repeatCount, XSortTesting, n, 'm');
  printf("QuickSort: ");
  timeit(repeatCount, XSortTesting, n, 'q');
  printf("InsertionSort: ");
  timeit(repeatCount, XSortTesting, n, 'i');
  printf("SelectionSort: ");
  timeit(repeatCount, XSortTesting, n, 's');
  printf("BubbleSort: ");
  timeit(repeatCount, XSortTesting, n, 'b');
}
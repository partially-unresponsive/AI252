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


void quickSort(int64_t* arr, size_t l, size_t r){
  // TODO: Write a better implementation of this
  size_t i = l, j = r;
  int64_t aux;
  int64_t pivot = arr[(l + r)/2];
  while (i <= j){
    while(arr[i] < pivot){
      i++;
    }
    while(arr[j] > pivot){
      j--;
    }
    if (i <= j){
      aux = arr[i];
      arr[i] = arr[j];
      arr[j] = aux;
      i++;
      j--;
    } 
  }
  if (l < j) { quickSort(arr, l, j); }
  if (i < r) { quickSort(arr, i, r);}
}

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

void RNGArray(int64_t* arr, size_t n){
  /* Fills an array of size n with pseudo-random values */

}

void printArray(int64_t* arr, size_t n){ // Ex. 5
  for (size_t i = 0; i < n; i++){
    printf("%ld  ", arr[i]);
  }
  printf("\n");
}

int main(){
  srand(time(NULL));
  // TODO: Create my own marks (similar to TODO:) which light up in different colors, like DONE: (green highlight) for completed tasks and RANT: (black highlight) for rants (they will be necessary :p)

  /* TESTING: Algoritmi de sortare */
  int n = 10;
  // int dummy[10] = {3, -4, 8, -12, 503, -32, 44, 12, 950, 420};
  int64_t* myarr = (int64_t*) malloc(n * sizeof(int64_t)); // DONE: Ex. 1
  resetArray(myarr); // Sets the initial dummy values to myarr

  selectionSort(myarr, n);
  printf("====\nPrelucrat (SelectionSort):\n");
  printArray(myarr, n);

  resetArray(myarr);
  insertionSort(myarr, 10);
  printf("====\nPrelucrat (InsertionSort):\n");
  printArray(myarr, n);

  resetArray(myarr);
  bubbleSort(myarr, 10);
  printf("====\nPrelucrat (BubbleSort):\n");
  printArray(myarr, n);

  resetArray(myarr);
  shellSort(myarr, 10);
  printf("====\nFIXME: Prelucrat (ShellSort):\n");
  printArray(myarr, n);

  resetArray(myarr);
  mergeSort(myarr, 0, n - 1);
  printf("====\nPrelucrat (MergeSort):\n");
  printArray(myarr, n);

  // TODO: Use <time.h> module (or timeit) or similar to test the execution speed of 1000 sorting operations of each sorting algorithm (linear, selection, insertion, quick, merge)
  // Using the timeit.h module from https://github.com/stephen-wang/ctimeit/blob/59cda8c5831d704a96a0664a36280af05c0f74e7/timeit.h

  timeit(1000, mergeSort, myarr, 0, n - 1);

  free(myarr); // Ex. 6
}
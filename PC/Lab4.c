// #include "timeit.h" // Credit to https://github.com/stephen-wang/ctimeit
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
// #include <math.h>

#define END_LOOP_FEED 666

void swap(int64_t *a, int64_t *b) {
  int64_t temp = *a;
  *a = *b;
  *b = temp;
}

int64_t **
allocMatrix(size_t rows,
            size_t columns) { // rows = number lines, columns = number columns
  /* Dynamically allocates a matrix of rows x columns size, but does not give
   * any of its elements values */
  int64_t **a = (int64_t **)malloc(rows * sizeof(int64_t *));
  if (a == NULL) { // Checks the matrix is allocated
    return NULL;
  }
  for (size_t i = 0; i < rows; i++) {
    int64_t *tmp = (int64_t *)malloc(columns * sizeof(int64_t));
    if (tmp == NULL) { // Checks the array is allocated
      return NULL;
    }
    a[i] = tmp;
  }
  return a;
}

void printMatrix(int64_t **mat, size_t rows, size_t columns) {
  /* Prints out a matrix of rows x columns size */
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < columns; j++) {
      printf("%ld\t", mat[i][j]);
    }
    printf("\n");
  }
}

void digits(int64_t num, size_t n, uint64_t *c) {
  /* num = number (49642), n = num. digits (5), int* c = pointer to be written
   * to ([4, 9, 6, 4, 2]) */
  for (size_t k = n; k >= 0; k--) {
    c[k] = num % 10;
    num = num / 10;
  }
}

// TODO: Figure out how modulus (%) works for negative values

/* Ex. 4 Algoritmi de sortare */

void selectionSort(int64_t *arr, size_t n) {
  /* Generic selectionSort algorithm, slightly faster than insertionSort */
  int64_t i, j, min;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (min != i) {
      swap(&arr[i], &arr[min]);
    }
  }
}

void insertionSort(int64_t *arr, size_t n) {
  /* Generic insertion sorting algorithm, slightly faster than bubbleSort */
  int64_t i, j;
  for (i = 1; i < n; i++) {
    j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      // aux = arr[j];
      // arr[j] = arr[j-1];
      // arr[j-1] = aux;
      swap(&arr[j], &arr[j - 1]);
      j--;
    }
  }
}

void bubbleSort(int64_t *arr, size_t n) {
  /* Simplistic sorting algorithm, just checks if arr[i] > arr[i+1], and swaps
   * them if they are */
  int ok = 1;
  size_t j = 0;
  while (ok) {
    ok = 0;
    j++;
    for (size_t i = 0; i < n - j; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(&arr[i], &arr[i + 1]);
        ok = 1;
      }
    }
  }
}

void shellSort(int64_t *arr, size_t n) {
  /* Sorting algorithm improving on insertionSort */
  for (size_t gap = n / 2; gap > 0; gap /= 2) {
    // Perform a "gapped" insertion sort for this gap size
    for (int64_t i = gap; i < n; i++) {
      // Current element to be placed correctly
      int64_t temp = arr[i];
      size_t j = i;

      // Shift elements that are greater than temp to make space
      while (j >= gap && arr[j - gap] > temp) {
        arr[j] = arr[j - gap];
        j -= gap;
      }

      // Place temp in its correct location
      arr[j] = temp;
    }
  }
}

// Begin quickSort helper functions:

int64_t compare(const void *a, const void *b) {
  /*
     a < b  => res > 0
     a > b  => res < 0
     a == b => res = 0
  */
  return (*(int64_t *)a -
          *(int64_t *)b); // *(int64_t*)a == Turn the void pointer into a
                          // int64_t pointer, and then dereference it
}

int64_t partition(int64_t *arr, int64_t low, int64_t high) {
  // Initialize pivot to be the first element
  int64_t pivot = arr[low];
  int64_t i = low;
  int64_t j = high;

  while (i < j) {
    // Find the first element greater than the pivot (from starting)
    while (arr[i] <= pivot && i <= high - 1) {
      i++;
    }

    // Find the first element smaller than the pivot (from last)
    while (arr[j] > pivot && j >= low + 1) {
      j--;
    }
    if (i < j) {
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[low], &arr[j]);
  return j;
}

void quickSort(int64_t *arr, int64_t low, int64_t high) {
  if (low < high) {
    // Call partition function to find partition index (j)
    int64_t pi = partition(arr, low, high);

    // Recursively call quickSort() for left and right half based on pi
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// End quickSort helper functions

// Begin mergeSort helper functions

void merge(int64_t *arr, size_t l, size_t m, size_t r) {
  size_t i, j, k;        // Index variables for L, R, and arr vectors
  size_t n1 = m - l + 1; // End index for L?
  size_t n2 = r - m;     // End index for R?

  // Create temp arrays
  int64_t L[n1], R[n2]; // L[] is the left array, and R[] is the right array.
                        // They should recursively merge until they are sorted

  // Copy data to temp arrays L[] and R[]
  for (i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }

  // Merge the temp arrays back into arr[l..r]
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) { // If the left temp array's element is smaller, place
                        // that in the sorted array
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j]; // Otherwise, the right temp array's element goes there
      j++;
    }
    k++; // We advance arr's index regardless
  }

  // Copy the remaining elements of L[], if there are any
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Same with R[]
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
  return;
}

void mergeSort(int64_t *arr, size_t l, size_t r) {
  // l => starting index (0), r => ending index (arr_size - 1)
  // Popular merge sorting algorithm, known for its efficiency and stability
  // Recursive implementation
  if (l < r) { // Only perform the sort if start < end for the indexes, which
               // should usually be the case unless array OOB
    size_t m =
        l + (r - l) / 2; // m => The middle point of the split, will probably
                         // floor() the value rather than ceil() it, so an array
                         // of 7 indices will get split into a size of 3 and 4
    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1,
              r); // This is why we need the l and r variables: we don't perform
                  // the merging operation on the *entire* array, just on both
                  // halves of it consecutively

    merge(arr, l, m, r); // And then we simply merge them together, basically:
    // 1. Start off with the untouched elements of arr*
    // 2. Then from index l, add elements of min(L[i], R[j])
    // 3. Do this until you reach arr[arr_size - 1], aka
    // arr[untouched_array_size + (r - l)]
  }
  return;
}

// End mergeSort helper functions

void printArray(int64_t *arr, size_t n) { // Ex. 5
  for (size_t i = 0; i < n; i++) {
    printf("%ld  ", arr[i]);
  }
  printf("\n");
}

int64_t *RNGArray(size_t n) {
  /* Dynamically fills an array of size n with pseudo-random values <= 1000 */
  int64_t *tmp = (int64_t *)malloc(n * sizeof(int64_t));
  if (tmp == NULL) { // The array wasn't initialized correctly
    return NULL;
  }
  for (size_t i = 0; i < n; i++) {
    tmp[i] = rand() % 256; // The magic happens here
  }
  return tmp; // Returns a pointer!
}

void XSortTesting(int n, char t) {
  /* Used to test sorting algorithms with random values. */
  int64_t *arr = RNGArray(n);
  if (arr == NULL) {
    printf("[ERROR]: Dynamic array failed to initialize.\n");
  } else {
    switch (tolower(t)) {
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
    case 'h':
      shellSort(arr, n);
      break;
    default:
      printf("[ERROR]: Sorting algorithm not defined.\n");
    }
    free(arr); // Ex. 6
    arr = NULL;
  }
}

void XSortArray(int64_t* arr, size_t n, char t){
  /* Actually sorts and replaces the array */
  switch (tolower(t)) {
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
    case 'h':
      shellSort(arr, n);
      break;
    default:
      printf("[ERROR]: Sorting algorithm not defined.\n");
    }
}

int main() {
  srand(time(NULL));
  
  // TODO: Create my own marks (similar to TODO:) which light up in different
  // colors, like DONE: (green highlight) for completed tasks and RANT: (black
  // highlight) for rants (they will be necessary :p)

  // Using the timeit.h module from
  // https://github.com/stephen-wang/ctimeit/blob/59cda8c5831d704a96a0664a36280af05c0f74e7/timeit.h

  // NOTE: START BENCH-TESTING ZONE

  // int n = 1000; // Number of values in each array

  // printf("RepeatCount: ");
  // int repeatCount;
  // scanf("%d", &repeatCount);

  // printf("BubbleSort: ");
  // timeit(repeatCount, XSortTesting, n, 'b');
  // printf("InsertionSort: ");
  // timeit(repeatCount, XSortTesting, n, 'i');
  // printf("SelectionSort: ");
  // timeit(repeatCount, XSortTesting, n, 's');
  // printf("MergeSort: ");
  // timeit(repeatCount, XSortTesting, n, 'm');
  // printf("ShellSort: ");
  // timeit(repeatCount, XSortTesting, n, 'h');
  // printf("QuickSort: ");
  // timeit(repeatCount, XSortTesting, n, 'q');

  // NOTE: END BENCH-TESTING ZONE

  // TODO: Make this work for 2D matrices, not just 1D arrays (required)
  // TODO: Create a prettyPrint function to print out the results in a table,
  // use Unicode characters too (so it needs support for wchar?)

  // START LAB 4.c KULEV
  /* START Matrix support area */

  // size_t rows, cols;
  char choice;
  printf("Alegeti metoda de sortare:\n- (B)ubbleSort\n- (I)nsertionSort\n- (S)electionSort\n- (M)ergeSort\n- S(h)ellSort\n- (Q)uickSort\nAlegere: ");
  scanf("%c", &choice);

  // printf("Dimensiuni tablou (n, m): ");
  // scanf("%zu %zu", &rows, &cols);
  // printf("rows: %zu, cols: %zu\n", rows, cols);

  // int64_t **res = allocMatrix(rows, cols); // Ex. 1
  // int64_t last_row, last_col;
  // last_row = -1;
  // last_col = -1;
  // // short int ok = 1;

  // // while (ok) {
  //   for (size_t i = 0; i < rows; i++) { // Ex. 2
  //     for (size_t j = 0; j < cols; j++) {
  //       printf("arr[%zu][%zu]: ", i, j);
  //       scanf("%ld", &res[i][j]);
  //       // TODO: Allow for an "end of feed" character that tells the program to
  //       // populate the remaining slots with RNG values
  //       if (res[i][j] == END_LOOP_FEED) { // Assume the user wants the rest of
  //                                         // the values to be generated
  //         last_row = i;
  //         last_col = j;
  //         // ok = -1;
  //         break;
  //       }
  //     }
  //   // }
  //   // ok = -1;
  // }

  size_t max_indx;
  printf("Dimensiune tablou: ");
  scanf("%zu", &max_indx);
  // int64_t *res = (int64_t *) malloc(max_indx * sizeof(int64_t)); // Ex. 1
  int64_t *res = calloc(max_indx, sizeof(int64_t));

  int64_t last_indx = 0;
  int64_t tmp;
  for (size_t i = 0; i < max_indx; i++){
    printf("arr[%zu]: ", i);
    scanf("%zu", &tmp); // Ex. 2
    res[i] = tmp;
    if (res[i] == END_LOOP_FEED) { // Assume the user wants the rest of
        //                                   // the values to be generated
      last_indx = i;
      break;
    }
  }
  /* Populate the remaining arrays with RNG values */
  int64_t *tmp_a = RNGArray(max_indx - last_indx); // Ex. 3
  for (size_t i = 0; i < max_indx - last_indx; i++){
    printf("tmp_a[%zu] = %zu\n", i, tmp_a[i]);
    res[i + last_indx] = tmp_a[i];
  }
  printf("Nesortat: \n");
  printArray(res, max_indx);

  FILE *fp;
  fp = fopen("unsorted.txt", "w");

  for (size_t i = 0; i < max_indx; i++){
    fprintf(fp, "%zu %zu\n", i, res[i]);
  }
  fclose(fp);

  system("gnuplot -e \"set terminal png; set output 'unsorted.png'; plot 'unsorted.txt' with lines\"");


  XSortArray(res, max_indx, choice); // Ex. 4
  printf("Sortat: \n");
  printArray(res, max_indx); // Ex. 5
  fp = fopen("sorted.txt", "w");

  for (size_t i = 0; i < max_indx; i++){
    fprintf(fp, "%zu %zu\n", i, res[i]);
  }
  fclose(fp);

  system("gnuplot -e \"set terminal png; set title 'PC Laborator 4: Algoritmi sortare'; set output 'sorted.png'; set grid; plot 'sorted.txt' with lines title 'Sortat', 'unsorted.txt' with lines title 'Nesortat' \"");
  free(res); // Ex. 6

  // printf("(Last_row, last_col): (%zu, %zu)\n", last_row, last_col); // FIXME: Displays (Last_row, last_col): (18446744073709551615, 18446744073709551615)

  // TODO: Figure out whether to linearize the matrix (treat all the rows of a matrix as one long array) or to sort each individual array within the matrix. This is ambiguous, so I will propose the latter.

  // TODO: Ex. 3




  // printf("Nesortat:\n");
  // printMatrix(res, rows, cols);

  // for (size_t i = 0; i < rows; i++){ // Ex. 4
  //   XSortArray(res[i], cols, choice);
  // }

  // printf("Sortat: \n");
  // printMatrix(res, rows, cols); // Ex. 5
  // free(res); // Ex. 6
  /* END Matrix support area */
}
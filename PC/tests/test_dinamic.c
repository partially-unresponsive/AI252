#include <stdlib.h>
#include <stdio.h>

int** alocmat(int nl, int nc){ // nl = number lines, nc = number columns
  /* Dynamically allocates a matrix of nl x nc size, but does not give any of its elements values */
  int i;
  int** a = (int **) malloc(nl * sizeof(int*));
  if (a == NULL) return a; // Checks the matrix is allocated
  for (i = 0; i < nl; i++){
    if (a[i] == NULL) return NULL; // Checks the array is allocated
  }
  return a;
}

void printmat(int** a, int nl, int nc){
  /* Prints out a matrix of nl x nc size */
  int i, j;
  for (i = 0; i < nl; i++){
    for (j = 0; j < nc; j++){
      printf("%d\t", a[i][j]);
      printf("\n");
    }
  }
  return;
}

void cifre(int n, int* c){
  int k;
  for (k = 4; k >= 0; k--){
    c[k] = n % 10;
    n = n / 10;
  }
}

/* Algoritmi de sortare */

void sortareSelectie(int* v, int n){
  int i, j, min, aux;
  for (i = 0; i < n - 1; i++){
    min = i;
    for (j = i + 1; j < n; j++){
      if (v[j] < v[min]){
        min = j;
      }
    }
    if (min != i){
      aux = v[i];
      v[i] = v[min];
      v[min] = aux;
    }
  }
}


void sortareInsertie(int* v, int n){
  int i, j, aux;
  for (i = 1; i < n; i++){
    j = i;
    while (j > 0 && v[j-1] > v[j]){
      aux = v[j];
      v[j] = v[j-1];
      v[j-1] = aux;
      j--;
    }
  }
}


void bubbleSort(int* v, int n){
  // TODO: Figure out how this works
  int ok = 1;
  int j = 0;
  int aux;
  while (ok){
    ok = 0;
    j++;
    for (int i = 0; i < n - j; i++){
      if (v[i] > v[i + 1]){
        aux = v[i];
        v[i] = v[i+1];
        v[i+1] = aux;
        ok = 1;
      }
    }
  }
}


void shellSort(int* v, int n){
  // FIXME: This does not work.
  int i, j, h, x;
  h = 1;
  while (h < n){
    h = h*3 + 1;
  }
  while(h >= 1){
    h = h / 3;
    for (i = h; i < n; i++){
      x = v[i];
      j = i;
      while (v[j-h] > x){
        v[j] = v[j-h];
        j = j - h;
        if (j < h){
          break;
        }
        v[j] = x;
      }
    }
  }
}


void quickSort(int* v, int st, int dr){
  // TODO: Write a better implementation of this
  int i = st, j = dr;
  int aux;
  int pivot = v[(st + dr)/2];
  while (i <= j){
    while(v[i] < pivot) {i++;}
    while(v[j] > pivot) {j--;}
    if (i <= j){
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      i++;
      j--;
    } 
  }
  if (st < j) { quickSort(v, st, j); }
  if (i < dr) { quickSort(v, i, dr);}
}

void resetArray(int* v){
  int dummy[10] = {3, -4, 8, -12, 503, -32, 44, 12, 950, 420};
  for (int i = 0; i < 10; i++){
    v[i] = dummy[i];
  }
}

void printArray(int* v){
  for (int i = 0; i < 10; i++){
    printf("myarr[%d] = %d\n", i, v[i]);
  }
  printf("\n");
}

int main(){
  // int* myarr = (int *) malloc(5 * sizeof(int));
  // int n = 57304;
  // cifre(n, myarr);
  // for (int i = 0; i < 5; i++){
  //   printf("a[%d] = %d\n", i, myarr[i]);
  // }
  // free(myarr);
  // myarr = NULL;

  /* TESTING: Algoritmi de sortare */
  int n = 10;
  // int dummy[10] = {3, -4, 8, -12, 503, -32, 44, 12, 950, 420};
  int* myarr = (int *) malloc(n * sizeof(int));
  resetArray(myarr); // Sets the initial dummy values to myarr

  sortareSelectie(myarr, n);
  printf("====\nPrelucrat (SelectionSort):\n");
  printArray(myarr);

  resetArray(myarr);
  sortareInsertie(myarr, 10);
  printf("====\nPrelucrat (InsertionSort):\n");
  printArray(myarr);

  resetArray(myarr);
  bubbleSort(myarr, 10);
  printf("====\nPrelucrat (BubbleSort):\n");
  printArray(myarr);

  resetArray(myarr);
  shellSort(myarr, 10);
  printf("====\nFIXME: Prelucrat (ShellSort):\n");
  printArray(myarr);

  // TODO: Use <time.h> module (or timeit) or similar to test the execution speed of 1000 sorting operations of each sorting algorithm (linear, selection, insertion, quick, merge)
}
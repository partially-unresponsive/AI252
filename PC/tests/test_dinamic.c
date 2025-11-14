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
  // TODO: Figure out how this works
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
  // TODO: Implement QuickSort
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
  int* myarr = (int *) malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    myarr[i] = i * i * 2 - 3*i - 14 - (i * i * i);
  }

  for (int i = 0; i < n; i++) {
    printf("myarr[%d] = %d\n", i, myarr[i]);
  }

  sortareSelectie(myarr, n);

  printf("====\nPrelucrat (SelectionSort):\n");
  for (int i = 0; i < n; i++) {
    printf("myarr[%d] = %d\n", i, myarr[i]);
  }



}
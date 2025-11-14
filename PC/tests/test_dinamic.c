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

int main(){
  int* myarr = (int *) malloc(5 * sizeof(int));
  int n = 57304;
  cifre(n, myarr);
  for (int i = 0; i < 5; i++){
    printf("a[%d] = %d\n", i, myarr[i]);
  }
  free(myarr);
  myarr = NULL;

}
// LABORATOR 3. Sarcina 15 -> Uniformizarea tabloului

/*

n = 3, m = 3; // Exemplu
MAT[n][m] =        { {4, 6, 8}, \
                     {1, 3, 5}, \
                     {3, 5, 7}  };

PROCESSED[n][m] =  { {(6+1)/2, (4+3+8)/3, (6+5)/2},\
                     {(4+3+3)/3, (6+5+5+1)/4, (8+3+7)/3}\
                     {(1+5)/2, (3+3+7)/3, (5+5)/2} }

*/

// Have a flag MAT_INCLUDE_SELF that toggles between: False: PROCESSED[0][0] = (6+1)/2 and True: PROCESSED[0][0]=(4+6+1)/3

#include <stdio.h>
#include <stdbool.h>

#define MAT_INCLUDE_SELF 1

int main(){
    // STEP 1. Input
    int n, m;
    printf("Dimensiunile matricei (n, m): ");
    scanf("%d %d", &n, &m);

    double mat[n][m];
    double tmp;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            printf("Mat[%d][%d] = ", i, j);
            scanf("%lf", &tmp);
            mat[i][j] = tmp;
        }
    }

    // STEP 2. Processing
    double processed[n][m]; // The processed matrix; here all the results will be saved to
    double tmpsum = 0;
    double media;
    unsigned int num_neighbors;
    bool neighbors[4] = {0, 0, 0, 0};
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            // Find all its neighbors possible: (0) mat[i-1][j] + (1) mat[i][j-1] + (2) mat[i][j+1] + (3) mat[i+1][j] != 0 && i+-1, j+-1 in DVA
            tmpsum = 0;
            num_neighbors = 0;
            neighbors[0] = (i - 1) >= 0;
            neighbors[1] = (j - 1) >= 0;
            neighbors[2] = (j + 1) < m;
            neighbors[3] = (i + 1) < n; 
            for (int k = 0; k < 4; ++k){
                if (neighbors[k]){ // Checks if the neighbor exists, values explained in comment above
                    switch (k) {
                        case 0:
                            tmpsum += mat[i-1][j];
                            break;
                        case 1:
                            tmpsum += mat[i][j-1];
                            break;
                        case 2:
                            tmpsum += mat[i][j+1];
                            break;
                        case 3:
                            tmpsum += mat[i+1][j];
                            break;
                    }
                    num_neighbors++;
                }
            }

            if (MAT_INCLUDE_SELF){
                tmpsum += mat[i][j];
                num_neighbors++;
            }

            media = tmpsum / num_neighbors;
            processed[i][j] = media; // Assigning the uniformized value
        }
    }

    // STEP 3. Displaying the values
    printf("========================\n");
    printf("Matrixa originara: \n");
    for (int i = 0; i < n; ++i){
        printf("[");
        for (int j = 0; j < m; ++j){
            printf(" %8.3lf,", mat[i][j]);
        }
        printf("]\n");
    }

    printf("\nMatrixa uniformizata (FLAG = %d): \n", MAT_INCLUDE_SELF);
        for (int i = 0; i < n; ++i){
        printf("[");
        for (int j = 0; j < m; ++j){
            printf(" %8.3lf,", processed[i][j]);
        }
        printf("]\n");
    }

}
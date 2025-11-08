#include <stdio.h>
#include <float.h>

int main(void){
    // Varianta 5. max(arr), index(max(arr)), count(max(array))
    unsigned int N;
    printf("N = ");
    scanf("%d", &N);
    double myarr[N];
    double tmp;
    for (int i = 0; i < N; ++i){
        printf("N[%d] = ", i);
        scanf("%lf", &tmp);
        myarr[i] = tmp;
    }
    double maxim = -DBL_MAX; // Lowest possible double value
    for (size_t i = 0; i < N; ++i){ // Gets max(myarr)
        if (myarr[i] > maxim){
            maxim = myarr[i];
        }
    }

    int mindex[256] = {-1, -1};
    size_t n = 0;
    size_t maxcount = 0;
    for (size_t i = 0; i < N; ++i){ // Gets the indexes of the maximal element, and counts them
        if (myarr[i] == maxim){
                mindex[n] = i;
                maxcount++;
                n++;
        }
    }

    printf("==================\n");
    if(mindex[1] == -1){
        printf("Elementul maxim: %.3lf este intalnit la pozitia %d.\n", maxim, mindex[0]);
    } else {
        printf("Elementul maxim: %.3lf este intalnit la pozitiile", maxim);
        for(size_t i = 0; i < maxcount - 1; ++i){
            printf(" %d,", mindex[i]);
        }
        printf(" %d.\n", mindex[maxcount - 1]);
    }
}
#include <stdio.h>
#include <float.h>

int main(void){
    // Varianta 4. min(arr), index(min(arr)), sum(neg)/N

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
    double minim = DBL_MAX; // Assume worst case scenario since the compiler throws a warning if I try initializing this to myarr[0]
    for (size_t i = 0; i < N; ++i){ // Gets min(myarr)
        if (myarr[i] < minim){
            minim = myarr[i];
        }
    };

    int mindex[2] = {-1, -1}; // -1 = Value not reached
    size_t n = 0;
    for (size_t i = 0; i < N; ++i){ // Gets the indexes of the minimal element
        if (myarr[i] == minim){
            switch(n){
                case 0:
                    mindex[0] = i;
                    mindex[1] = i; // In case there is only one minimal value in the array, we still want a value assigned
                    n++;
                    break;
                case 1:
                    mindex[1] = i; // No need to increment n here
                    break;
            }
        }
    }

    double negsum = 0;
    double negmedie = 0;
    size_t negcount = 0;
    for (size_t i = 0; i < N; ++i){
        if (myarr[i] < 0){
            negsum += myarr[i];
            negcount++;
        }
    }
    negmedie = (negsum)/(negcount);

    printf("==================\n");
    if(mindex[0] == mindex[1]){
        printf("Elementul minim: %.3lf este intalnit la pozitia %d.\n", minim, mindex[0]);
    } else {
        printf("Elementul minim: %.3lf este intalnit la pozitiile %d si %d.\n", minim, mindex[0], mindex[1]);
    }
    printf("Media valorilor negative este: %.3lf\n", negmedie);

}
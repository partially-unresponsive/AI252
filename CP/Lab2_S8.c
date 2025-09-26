#include <stdio.h>
#include <float.h>

int main(void){
    // Varianta 8. min(arr > 0), index(max(arr))[1], count(array < 0)
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
    int negcount = 0;
    int mindex = -1; // Assume it won't find any positive values
    for (size_t i = 0; i < N; ++i){ // Gets min(myarr) and index(min(arr))
        if ((myarr[i] < minim) && (myarr[i] >= 0)){ // NOTE: Considering "positive" as >=0
            minim = myarr[i];
            mindex = i;
        }
        if (myarr[i] < 0){
            negcount++;
        }
    }
    
    printf("==================\n");
    if (mindex == -1){
        printf("Nu au fost recordate numere pozitive.\n");
    } else {
        printf("Elementul minim pozitiv: %.3lf este intalnit la pozitia %d.\n", minim, mindex);
    }
    printf("Exista %d elemente negative in tablou.\n", negcount);
}
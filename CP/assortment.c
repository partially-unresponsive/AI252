#include <stdio.h>
// Algorithm taken from C01.pdf, pp 8
int digit_sum(long int n){
    int sum = 0;
    if (n <= 0) { return 0; }

    while (n > 9){
        sum += n % 10;
        n /= 10;
    }
    sum += n;

    return sum;
}

int main(){
    long int nums[] = {0, 1, 8, 10, 12, 24, 48, 195, 491, 10654352};
    for (int i = 0; i < sizeof(nums) / sizeof(long int); ++i){
        printf("Sum (%ld) = %d\n", nums[i], digit_sum(nums[i]));
    }

    // sscanf() and sprintf() example, C01.pdf pp 67
    char mystr[50] = "Andrei 24 Cluj-Napoca 9.5";
    char nume[30], oras[20];
    int varsta;
    float nota;
    sscanf(mystr, "%s %d %s %f", nume, &varsta, oras, &nota);
    char text[100];
    sprintf(text, "%s are %d ani, este din %s si a obtinut nota %.2f", nume, varsta, oras, nota);
    printf("%s\n", text);
}
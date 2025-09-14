/* 
Arithm. Operators: +, -, *, /, %, ++, --
Math functs: sqrt, log, pow, abs
Logic operators: <, >, <=, !=, ==, >=, &&, ||
Data types: char, double, float, int, long int, unsigned int, short
Printf scan codes
math.h
*/

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG_E 0 // 1 (True) let anything happen; 0 (False) production mode, disable risky behavior
#define MAGIC 120

const double MATH_PI = 3.14159265358979323846L; // constant double literal

int main(void){
    srand(time(NULL));
    printf("============================\n%20s\n", "# PROGRAM START");
    long double num1_, num2_;
    printf("Introduceti 2 numere: ");
    if(scanf("%Lf %Lf", &num1_, &num2_) == 2){ // %Lf -> long double (16-bit precision)
        printf("Introdus: %Lf, %Lf\n", num1_, num2_);
    } else {
        printf("[ERR]: Numar incorect de argumente.");
        return -1;
    }
    // Operatii aritmetice
    printf("============================\n%25s\n", "# Operatori aritmetici");
    printf("Suma:      %.5Lf\n", num1_+num2_);
    printf("Diferenta: %.5Lf\n", num1_-num2_);
    printf("Produsul:  %.5Lf\n", num1_*num2_);
    if (num2_ != 0 || DEBUG_E){
        printf("Catul:     %.5Lf\n", num1_/num2_);
    }
    printf("Radical:   %.5f\n", sqrt(num1_));
    printf("Puterea:   %.5f\n", pow(num1_, num2_)); // Downcasting from long double to double for pow(), values restricted to 1.7E+308 
    printf("Logaritmul natural: ln(%Lf) = %.8f\n", num1_, log(fabsl(num1_))); // fabsl(double) is the same as math.abs(int), but works for any data type
    printf("%Lf<<4 = %Ld\n", num1_, (long long)num1_<<4);

    // Operatori logici
    printf("============================\n%21s\n", "# Operatori logici");
    if (num1_ == num2_){
        printf("Numerele sunt egale.\n");
    } else if (num1_ < num2_){
        printf("Num2 este mai mare.\n");
    } else if (num1_ > num2_){
        printf("Num1 este mai mare.\n");
    }

    uint64_t randnum = rand();

    if ((randnum % 2) && ((long long)num1_) % 2){
        printf("Numarul generat %lu si %Ld sunt ambii impari.\n", randnum, (long long)num1_);
    } else if ((randnum % 2) == ((long long)num1_) % 2){
        printf("Numarul generat %lu si %Ld sunt ambii pari.\n", randnum, (long long)num1_);
    } else {
        printf("Numarul generat %lu si %Ld au semne diferite.\n", randnum, (long long)num1_);
    }

    // Operatii de bucla
    printf("============================\n%22s\n", "# Operatii de bucla");
    printf("Numele secret este ");
    short int myarr[5] = {195, 205, 196, 189, 206};
    for (int i = 0; i < sizeof(myarr)/sizeof(myarr[0]); ++i){ // equivalent to len(myarr)
        printf("%c", myarr[i] % MAGIC); // Rudimentary cryptography
    }
    printf("!\n");
}
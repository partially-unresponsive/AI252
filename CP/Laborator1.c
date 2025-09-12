/* 
Arithm. Operators: +, -, *, /, %, ++, --
Math functs: sqrt, log, pow, abs
Logic operators: <, >, <=, !=, ==, >=, &&, ||
Data types: char, double, float, int, long int, unsigned int, short
Printf scan codes
math.h
*/

#include <math.h>
#include <stdio.h>

#define DEBUG_E 0 // 1 (True) let anything happen; 0 (False) production mode, disable risky behavior

const double MATH_PI = 3.14159265358979323846L; // constant double literal

int main(void){
    long double num1_, num2_;
    printf("Introduceti 2 numere: ");
    if(scanf("%Lf %Lf", &num1_, &num2_) == 2){ // %Lf -> long double (16-bit precision)
        printf("Introdus: %Lf, %Lf\n", num1_, num2_);
    } else {
        printf("[ERR]: Numar incorect de argumente.");
        return -1;
    }
    // Operatii aritmetice
    printf("Suma: %Lf\n", num1_+num2_);
    printf("Diferenta: %Lf\n", num1_-num2_);
    printf("Produsul: %Lf\n", num1_*num2_);
    if (num2_ != 0 || DEBUG_E){
        printf("Catul: %Lf\n", num1_/num2_);
    }
    printf("Puterea: %f\n", pow(num1_, num2_)); // Downcasting from long double to double for pow(), values restricted to 1.7E+308 
    printf("Logaritmul natural: ln(%Lf) = %f\n", num1_, log(fabsl(num1_))); // fabsl(double) is the same as math.abs(int), but works for any data type




    // Operatii de bucla
    printf("Numele secret este ");
    short int myarr[5] = {195, 205, 196, 189, 206};
    for (int i = 0; i < sizeof(myarr)/sizeof(myarr[0]); ++i){ // equivalent to len(myarr)
        printf("%c", myarr[i] % 120); // Rudimentary cryptography
    }
    printf("!\n");

    // Functii matematice


}
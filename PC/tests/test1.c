#include <stdio.h>
#include <string.h>

int main() {
    char str1[101];  // 101 due to https://www.geeksforgeeks.org/c/gets-is-risky-to-use/
    printf("talk quietly...the children are sleeping: ");
    scanf("%[^A-Z]s", str1);  // Reads input until the first uppercase letter
    // Doesn't need to be &str because it's already a pointer
    int len = strlen(str1);
    str1[len - 1] = '\0'; // Removes trailing \n

    printf("You fucking woke up the children.\n");


    getchar();
    getchar(); // Run it twice, just in case.

    char str2[100];

    printf("Enter a string under a NDA: ");
    fgets(str2, sizeof(str2), stdin);
    printf("I entered (as you have forfeited your copyright over to *me*) (fgets): %s\n", str2);


    // IO Formatting example
    char str[] = "brickforbrick"; 
    printf("%20s\n", str);        // ->        brickforbrick
    printf("%-20s\n", str);       // -> brickforbrick       
    printf("%20.5s\n", str);      // ->                brick
    printf("%-20.5s\n", str);     // -> brick

    return 0;
}

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define DEBUG 1

uint64_t consonant_count(char* ss, size_t n){ // Ex. 1
    uint64_t res = 0;
    char tmp;
    for (size_t i = 0; i < n; i++){
        tmp = ss[i];
        switch (tmp) {
            case 'b':
            case 'c':
            case 'd':
            case 'f':
            case 'g':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                res++;
                break;
            default:
                break;
        }
    }
    return res;
}

struct StringMatrixContainer {
    size_t size;
    char** words;
};

struct StringMatrixContainer* split_str(char* ss, size_t n){

}

struct StringMatrixContainer* extract_words(char* ss, size_t n){
    // Takes a string like " This is truly a wonderful day!  " and performs a Python-like .split() operation, returns an array of words, thus a char**
    struct StringMatrixContainer res;
    char** words;
    size_t word_count = 0;
    char curr;
    char last = ss[0];
    for (size_t i = 1; i < n; i++){
        curr = ss[i];
        if (curr == ' ' && last != ' '){
            words++;
        }
        last = curr;
    }

}

uint64_t word_count(char* ss) { // Ex. 2
    uint64_t words_count = 0;
    char curr;
    char last = ss[0];
    for (size_t i = 1; i < strlen(ss); i++){
        curr = ss[i];
        if (isspace(curr) && !isspace(last)){
            words_count++;
        }
        last = curr;
    }
    return words_count;
}

char* reverse_str(const char* ss) { // Ex. 3
    size_t len = strlen(ss);
    char* res = (char *) malloc(len * sizeof(char));
    char tmp;
    for (size_t i = 0; i < len; i++){
        tmp = ss[len-i-1];
        res[i] = tmp;
    }
    return res;
}

void printStr(char* ss){
    // for (size_t i = 0; i < strlen(ss); i++){
    //     printf("%c", ss[i]);
    // }
    printf("%s\n", ss);
}

int main(){
    // TODO: Try to dynamically allocate the memory across the program.
    // size_t n = 62;
    // FIXME: I have become lost in the sauce
    char mystr[1000] = "     Meowwers! I am truly enjoying this wonderful experience!";
    printStr(mystr);

    char* rev = reverse_str(mystr);
    printStr(rev);

    uint64_t words = word_count(mystr);
    printf("Word count: %zu", words);

}
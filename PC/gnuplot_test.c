#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *fp;
    fp = fopen("data.txt", "w");

    for (int i = 0; i < 100; i++) {
        fprintf(fp, "%d %f\n", i, sin(i * 0.1));
    }
    
    fclose(fp);
    
    system("gnuplot -e \"set terminal png; set output 'plot.png'; plot 'data.txt' with lines\"");

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char **argv) {
    srand( time(NULL) );
    int n = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    for (int i = 0; i < n; ++i) {
        printf("%i ", rand() % (b - a + 1) + a);
    }
    printf("\n");
    return 0;
}

//letter transposition

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


void permutations(char *str, char *cp, int st, int end) {
    for (int i = st; i < (end-1); ++i) {
        for (int j = (i + 1); j < end; ++j) {
            char tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
            if (strcmp(str, cp) == 0) {
                printf("YES\n");
                exit(0);
            }
            permutations(str, cp, i+1, end);
            tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
        }
    }
}


int main(int argc, char **argv) {
    int n = strlen(argv[1]);
    int m = strlen(argv[2]);
    if (n != m) {
        printf("NO\n");
        exit(0);
    }
    permutations(argv[1], argv[2], 0, n);
    printf("NO\n");
    return 0;
}

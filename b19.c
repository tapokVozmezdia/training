#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    char line[1024];
    char *ptr;
    printf("Введите строку:\n");
    scanf("%s", &line);
    ptr = strtok(line,".");
    int t = 0;
    while (ptr != NULL) {
        t += 1;
        if ((atoi(ptr)>=0) && (atoi(ptr)<=255) && (ptr[0] != '0')) {
            ptr = strtok(NULL, ".");
        }
        else {
            printf("NO");
            break;
        }
    }
    if (t == 4) {
        printf("YES");
    }
    return 0;

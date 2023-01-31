#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *perest(int sdvig, int k, int *mass)
{
    if (sdvig == 0) {
        FILE* fp = fopen("out.txt", "a+");
        for (int i = 1; i < k - 1; ++i) {
            fprintf(fp, "%d ", mass[i]);
        }
        fclose(fp);
        exit(1);
    }
    else if (sdvig > 0) {
        sdvig = k - 2 - sdvig;
        while (sdvig > 0) {
            for (int i = 1; i < k - 2; ++i) {
                int tmp = mass[i + 1];
                mass[i + 1] = mass[i];
                mass[i] = tmp;
            }
            --sdvig;
        }
    }
    else {
        sdvig = k - 2 - sdvig;
        while (sdvig > 0) {
            for (int i = 1; i < k - 2; ++i) {
                int tmp = mass[i + 1];
                mass[i + 1] = mass[i];
                mass[i] = tmp;
            }
            --sdvig;
        }
    }
    FILE* fp = fopen("out.txt", "a+");
    for (int i = 1; i < k - 1; ++i) {
        fprintf(fp, "%d ", mass[i]);
    }
    fclose(fp);
}


void *read(FILE* file)
{
    int k = 0;
    int sym = 0;
    if (file == NULL) {
        printf("error\n");
        exit(1);
    }
    while (fscanf(file, "%d", &sym)) {
        k = k + 1;
    }
    fseek(file, 0, SEEK_SET);
    int mass[k - 2];
    for (int i = 0; i < k - 1; ++i) {
        fscanf(file, "%d", &mass[i]);
    }
    int sdvig = mass[0];
    perest(sdvig, k, mass);
}


int main()
{
    FILE* file = fopen("12.txt", "r");
    read(file);
    fclose(file);
    return 0;
}

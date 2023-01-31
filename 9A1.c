#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void delete (char* str) {
    int fl = 0;
    int first = 0;
    int n = strlen(str);
    int end = 0; //уже удалили последовательность
   
    for (int i = 0; i < n; i++) {
        if (end == 1) {
            break;
        }
        if (str[i] == '/' && str[i + 1] == '*' && end == 0) {
            fl = 1;
            first = 1;
        }
             
        if (str[i] == '*' && str[i + 1] == '/') {
            if (first == 1) {
                memmove(&str[i], &str[i + 2], n - 2);
                i -= 2;
                n -= 2;
                end = 1;
            }
            fl = 0;
        }
       
        if (fl == 1 && end == 0) {
            memmove(&str[i], &str[i + 1], n - 1);
            --i;
            --n;          
        }
    }
   
   str[strlen(str)] = '\0';
   printf ("%s", str);
   
}
       
int main() {
    FILE* fp = fopen("task10_1.txt", "a+");
   
    if (fp == NULL) {
        printf ("Ошибка открытия файла\n");
        return 0;
    }


    char* str = NULL;
    size_t len = 0;


    if (getline(&str, &len, fp) > 0) {
        delete(str);
    }
   
    free(str);
    fclose(fp);
    return 0;
}

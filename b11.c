#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main() {
    FILE *f = fopen("task11.txt", "r");
    size_t len;
    char *line = NULL;
    size_t len_;
    while ((len_ = (getline(&line, &len, f))) != -1) {
        printf("%s", line);
    }
    char* mas[len];
    size_t wcount = 0;
    size_t i = 0;
    size_t flag = 0;
    while (strlen(line)) {
        if (isalpha(line[i])) {
            i++;
            flag = 0;
        }else{
            if (flag) {
                line++;
                continue;
            }else{
                line[i] = '\0';
                wcount++;
                mas[wcount-1] = calloc((i+1), sizeof(char));
                strcpy(mas[wcount-1], line);
                line[i] = ' ';
                line += i;
                i = 0;
            }
            flag = 1;
        }
    }
    for (int i = 0; i < wcount; ++i) {
        for (int j = i + 1; j < wcount; ++j) {
            if (strcmp(mas[i], mas[j]) > 0) {
                char tmp[128];
                memset(tmp, 0, 128);
                strcpy(tmp, mas[i]);
                strcpy(mas[i], mas[j]);
                strcpy(mas[j], tmp);
            }
        }
    }
    for (int i = 0; i < wcount; ++i) {
        printf("%s\n", mas[i]);
    }
    return 0;
}

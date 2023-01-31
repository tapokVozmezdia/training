#define _GNU_SOURCE
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void strdelchar(char *str, char ch, int index){
    char *ptr = str;
    ptr += index;
    for(int i = index; i < strlen(str); i++){
        if(str[i] == ch){
            memmove(ptr, ptr + 1, strlen(str) - i);
        }
        ptr++;
    }
}


size_t strUnique(char *str){
    char *ptr = str;
    for(int i = 1; i < strlen(str); i++){
        if(strchr(ptr + i, str[i]) == NULL){
            //ptr++;
            continue;
        }
        else{
            char ch = str[i];
            for(int j = i + 1; j < strlen(str); j++){
                if(str[j] == ch){
                    strdelchar(ptr, ch, j);
                }
            }
        }
    }
    printf("%s\n", ptr);
    return sizeof(str);
}
int main(){
    printf("Введите название файла:\n");
    size_t len = 0;
    char *fileName = NULL;
    FILE *fd = NULL;
    if(getline(&fileName, &len, stdin) != -1){
        fileName[strlen(fileName) - 1] = '\0';
        fd = fopen(fileName, "r");
    }
    if(fd == NULL){
        return 0;
    }
    char *fstr = NULL;
    size_t len_fstr = 0;
    if(getline(&fstr, &len_fstr, fd) != -1){
        fstr[strlen(fstr) - 1] = '\0';
    }
    printf("Длина строки: %i\n", strUnique(fstr));
    printf(" \n");
    printf("%s\n", fstr);
    free(fileName);
    fclose(fd);
    return 0;
}

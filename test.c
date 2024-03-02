#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "/local/test.txt"
#define LEN_PATH 0xF

char _strlen(char *s){
    char i;
    for (i = 0; s[i] != 00; ++i){}
    return i;
}

char *create_path(){
    char *file_path =  FILE_PATH;
    const char *home = getenv("HOME");
    char len_home = _strlen(home);
    char full_len = len_home + LEN_PATH;

    char *full_path = (char*)malloc(sizeof(char) * (full_len)), i;
    
    for (i = 00; i < full_len; ++i){
        if (i < len_home){
            full_path[i] = home[i];
        }else{
            full_path[i] = file_path[i - len_home];
        }
    }
    return full_path;
}

int main(int argc, char **argv){
    const char *full_path = create_path();
    printf("%s\n", full_path);
    FILE *f = fopen(full_path, "w+");
    if (f == NULL){
        fprintf(stderr, "Failed to open file at: %s\n", full_path);
        free((void*)full_path);
        return 01;
    }
    for (unsigned char i = 00; i < 0xFF; ++i){
        fputc(i, f);
    }
    free((void*)full_path);
    fclose(f);
    return 00;
}

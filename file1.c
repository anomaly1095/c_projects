#include <stdio.h>
#include <stdlib.h>

                            //Algorythm to find if there is a suite of 4 similar characters

#define uint16 unsigned short
const uint16 _SIZE = 2980;

uint16 find(char* buffer);
int open_file(FILE* f, char *buffer);


uint16 main(){
    FILE* f;
    char* buffer = (char*)malloc(_SIZE);
    if (open_file(f, buffer) == 0){
        find(buffer);
        free(buffer);
        return 0;
    }else{
        return 1;
    }
    
}


// Find the 4 consecutive unique chars 
uint16 find(char *buffer){
    uint16 position;
    for (uint16 i = 0; i <= _SIZE - 4; i++){
        if (buffer[i] == buffer[i+1] || buffer[i] == buffer[i+2] || buffer[i] == buffer[i+3]){
            buffer++;
        }else if(buffer[i+1] == buffer[i+2] || buffer[i+1] == buffer[i+3]){
            buffer++;
        }else if(buffer[i+2] == buffer[i+3]){
            buffer++;
        }else{
            printf("%c %c %c %c\n", buffer[i], buffer[i+1], buffer[i+2], buffer[i+3]);
        }
    }
}

// Opening the file that contains the string
int open_file(FILE* f, char *buffer){
    char f_name[] = "/home/amnesia2/Documents/C_Files/file1.txt";
    f = fopen(f_name, "r");
    if(f == NULL){
        fprintf(stderr, "Error opening: %s", f_name);
        return 1;
    }
    fgets(buffer, _SIZE, f);
    fclose(f);
}

#include <stdio.h>



int _conv(char c, int coef){
    int i, j = 0;
    for (i = 0x30; i <= 0x39; i++, j++){
        if (c == i)
            return coef * j;
    }
}

int _strlen(char *s){
    int i;
    for (i = 0; *(s+i) != 0x0; i++){}
    return i;
}

int *_parse(char *s){
    const int MAX = 20;
    int arr[MAX], index_arr = MAX, coef = 1, i, j, size = _strlen(s);
    for (i = size; i >= 0; i--){
        for (j = i; *(s+j) != 0x0; j--){
            if (*(s+j) >= 0x30 && *(s+j) <= 0x39){
                arr[index_arr] += _conv(*(s+j), coef);
                coef *= 10;
                if (*(s+j+1) < 0x30 || *(s+j+1) > 0x39){
                    index_arr--;
                    break;
                }
            }else{
                break;
            }
        }
        i = j;
        coef = 1;
    }
}


int main(int argc, char const *argv[]){
    char *s = "hdbh6278261dkhbvccdhbv16726";
    _parse(s);

    printf("s: %s\n", s);
    return 0;
}

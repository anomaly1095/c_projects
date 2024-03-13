#include "_types_.h"
#include <openssl/sha.h>


void sha256_hash_string(const char *string, unsigned char outputBuffer[65]) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, string, strlen(string));
    SHA256_Final((unsigned char*)outputBuffer, &sha256);
    outputBuffer[64] = 0; // Null-terminate the hash string
}


_ui32 _str_len(char *arr){

}

_ui8 _str_comp(char *arr1, const char *str){

}

_ui8 _str_copy(char *arr1, const char *str){

}

_ui8 _str_cat(char *arr1, _ui32 size_arr1, const char *str){

}

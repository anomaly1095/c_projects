#include "../include/_types_.h"
#include <openssl/evp.h>





_ui32 _str_len(char *arr){
_ui32 i;
  for (i = 00; arr[i] != 00; ++i){}
  return i;
}

_ui8 _str_comp(char *arr1, const char *str){
_ui32 i;
  for (i = 00; i < _str_len(arr1) && i < _str_len(str); ++i){
    if (arr1[i] != str[i]) return _FAILURE;
  }
  return 0x0;
}

_ui8 _str_copy(char *arr, _ui32 size_arr, const char *str){
_ui32 i;
  for (i = 00; i < _str_len(str) && i < size_arr; ++i){
    arr[i] = str[i];
  }
  return _SUCCESS;
}

_ui8 _str_cat(char *arr, _ui32 size_arr, const char *str){
_ui32 i;
  for (i = 00; i < _str_len(arr) && i < size_arr; ++i){
    arr[i] = arr[i];
  }
  for (i = 00; i < _str_len(str) && i < size_arr; ++i){
    arr[i] = str[i];
  }
  return _SUCCESS;
}

void sha256_hash_string(const char *string, unsigned char outputBuffer[65]) {
  EVP_MD_CTX *mdctx;
  const EVP_MD *sha256 = EVP_sha256();

  // Allocate EVP_MD_CTX
  if (!(mdctx = EVP_MD_CTX_create())) {
    exit(HASH_FAIL);
  }
  // Initialize EVP_MD_CTX with SHA256
  if (EVP_DigestInit_ex(mdctx, sha256, NULL) != 1) {
    // Handle error
    EVP_MD_CTX_destroy(mdctx);
    exit(HASH_FAIL);
  }
  // Update the context with the data
  if (EVP_DigestUpdate(mdctx, string, _str_len((char *)string)) != 1) {
    // Handle error
    EVP_MD_CTX_destroy(mdctx);
    exit(HASH_FAIL);
  }
  // Finalize the hash computation
  if (EVP_DigestFinal_ex(mdctx, outputBuffer, NULL) != 1) {
    // Handle error
    EVP_MD_CTX_destroy(mdctx);
    exit(HASH_FAIL);
  }
  // Clean up
  EVP_MD_CTX_destroy(mdctx);
}

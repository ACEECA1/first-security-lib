#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math/matrix.h"
/*
    @param input The plaintext to be encrypted or the ciphertext to be decrypted.
    @param key The key used for encryption or decryption.
    @return A newly allocated string containing the encrypted or decrypted result. The caller is responsible for freeing this memory.
*/
char* encrypt_caesar(const char* input, const char* key) {
    size_t input_len = strlen(input);
    size_t key_len = strlen(key);
    char* encrypted = (char*)malloc(input_len + 1); 

    for (size_t i = 0; i < input_len; ++i) {
        int pos = input[i] - 'A';
        char enc_char = key[pos % key_len];
        encrypted[i] = enc_char;
    }
    encrypted[input_len] = '\0'; 
    return encrypted;
}

/*
    @param input The ciphertext to be decrypted.
    @param key The key used for decryption.
    @return A newly allocated string containing the decrypted result. The caller is responsible for freeing this memory.
*/
char* decrypt_caesar(const char* input, const char* key) {
    size_t input_len = strlen(input);
    size_t key_len = strlen(key);
    char* decrypted = (char*)malloc(input_len + 1); 

    for (size_t i = 0; i < input_len; ++i) {
        for(size_t j = 0; j < key_len; ++j) {
            if (input[i] == key[j]) {
                decrypted[i] = 'A' + j;
                break;
            }
        }
    }
    decrypted[input_len] = '\0'; 
    return decrypted;
}
/*
    @param input The plaintext to be encrypted or the ciphertext to be decrypted.
    @param key_matrix The key matrix used for encryption or decryption.
    @return A newly allocated string containing the encrypted or decrypted result. The caller is responsible for freeing this memory.
*/
char* encrypt_hill(const char* input, Matrix* key_matrix) {
    return NULL;
}
/*
    @param input The ciphertext to be decrypted.
    @param key_matrix The key matrix used for decryption.
    @return A newly allocated string containing the decrypted result. The caller is responsible for freeing this memory.
*/
char* decrypt_hill(const char* input, Matrix* key_matrix) {
    return NULL;
}

/*
    @param input The plaintext to be encrypted or the ciphertext to be decrypted.
    @param key The key used for encryption or decryption.
    @return A newly allocated string containing the encrypted or decrypted result. The caller is responsible for freeing this memory.
*/
char* encrypt_shift(const char* input , int key) {
    size_t input_len = strlen(input);
    char* encrypted = (char*)malloc(input_len + 1); 

    for (size_t i = 0; i < input_len; ++i) {
        char enc_char = ((input[i] - 'A' + key) % 26) + 'A';
        encrypted[i] = enc_char;
    }
    encrypted[input_len] = '\0'; 
    return encrypted;
}

/*
    @param input The ciphertext to be decrypted.
    @param key The key used for decryption.
    @return A newly allocated string containing the decrypted result. The caller is responsible for freeing this memory.
*/
char* decrypt_shift(const char* input , int key) {
    size_t input_len = strlen(input);
    char* decrypted = (char*)malloc(input_len + 1); 

    for (size_t i = 0; i < input_len; ++i) {
        char dec_char = ((input[i] - 'A' - key + 26) % 26) + 'A';
        decrypted[i] = dec_char;
    }
    decrypted[input_len] = '\0'; 
    return decrypted;
}
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
    @param num The integer for which to find the modular inverse.
    @param mod The modulus.
    @return The modular inverse of num modulo mod, or -1 if it does not exist.
*/
int inverse_mod(int num, int mod) {
    num = num % mod;
    for (int x = 1; x < mod; x++) {
        if ((num * x) % mod == 1) {
            return x;
        }
    }
    return -1; 
}

/*
    @param input The plaintext to be encrypted or the ciphertext to be decrypted.
    @param key_matrix The key matrix used for encryption or decryption.
    @return A newly allocated string containing the encrypted or decrypted result. The caller is responsible for freeing this memory.
*/
char* encrypt_hill(const char* input, Matrix* key_matrix) {
    char* encrypted = (char*)malloc(strlen(input) + 1);
    for(int i = 0 ; i < strlen(input); i+=2) {
        char c1 = input[i];
        char c2 = (i + 1 < strlen(input)) ? input[i + 1] : 'Z';
        int p1 = c1 - 'A';
        int p2 = c2 - 'A';
        int e1 = (key_matrix->data[0] * p1 + key_matrix->data[1] * p2) % 26;
        int e2 = (key_matrix->data[2] * p1 + key_matrix->data[3] * p2) % 26;
        encrypted[i] = e1 + 'A';
        if (i + 1 < strlen(input)) {
            encrypted[i + 1] = e2 + 'A';
        }
    }
    encrypted[strlen(input)] = '\0';
    return encrypted;
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
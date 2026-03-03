#include <stdio.h>
#include "encryption.h"
#include "math/matrix.h"


int main() {
    // Test Caesar cipher
    const char* plaintext = "HELLO";
    const char* caesar_key = "QWERTYUIOPASDFGHJKLZXCVBNM";
    char* encrypted_caesar = encrypt_caesar(plaintext, caesar_key);
    printf("Caesar Encrypted: %s\n", encrypted_caesar);
    char* decrypted_caesar = decrypt_caesar(encrypted_caesar, caesar_key);
    printf("Caesar Decrypted: %s\n", decrypted_caesar);
    free(encrypted_caesar);
    free(decrypted_caesar);
    // Test Shift cipher
    int shift = 3;
    char* encrypted_shift = encrypt_shift(plaintext, shift);
    printf("Shift Encrypted: %s\n", encrypted_shift);
    char* decrypted_shift = decrypt_shift(encrypted_shift, shift);
    printf("Shift Decrypted: %s\n", decrypted_shift);
    free(encrypted_shift);
    free(decrypted_shift);
    
    return 0;
}

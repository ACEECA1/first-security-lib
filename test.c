#include <stdio.h>
#include "encryption.h"
#include "math/matrix.h"


int main() {
    const char* plaintext = "JE VOUSAIME";
    Matrix* key_matrix = mat_create(2, 2);
    key_matrix->data[0] = 3; key_matrix->data[1] = 2;
    key_matrix->data[2] = 5; key_matrix->data[3] = 7;
    char* encrypted = encrypt_hill(plaintext, key_matrix);
    printf("Encrypted: %s\n", encrypted);
    free(encrypted);
    mat_free(key_matrix);
    return 0;
}

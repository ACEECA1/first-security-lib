#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef struct {
    size_t rows;
    size_t cols;
    int* data;
} Matrix;

/*
    @param rows Number of rows in the matrix.
    @param cols Number of columns in the matrix.
    @return A pointer to a newly allocated Matrix structure. The caller is responsible for freeing this memory using mat_free().
*/
Matrix* mat_create(size_t rows, size_t cols) {
    Matrix* mat = (Matrix*)malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = (int*)malloc(rows * cols * sizeof(int));
    return mat;
}
/*
    @param mat A pointer to the Matrix structure to be freed.
*/
void mat_free(Matrix* mat) {
    if (mat) {
        free(mat->data);
        free(mat);
    }
}
/*
    @param mat A pointer to the Matrix structure.
    @param row The row index (0-based) of the element to set.
    @param col The column index (0-based) of the element to set.
    @param value The integer value to set at the specified position.
*/
void mat_set(Matrix* mat, size_t row, size_t col, int value) {
    if (row < mat->rows && col < mat->cols) {
        mat->data[row * mat->cols + col] = value;
    }
}

/*
    @param mat A pointer to the Matrix structure.
    @param row The row index (0-based) of the element to retrieve.
    @param col The column index (0-based) of the element to retrieve.
    @return The integer value at the specified position, or 0 if the indices are out of bounds.
*/
int mat_get(Matrix* mat, size_t row, size_t col) {
    if (row < mat->rows && col < mat->cols) {
        return mat->data[row * mat->cols + col];
    }
    return 0;
}

/*
    @param mat A pointer to the Matrix structure to be printed.
*/
void mat_print(Matrix* mat) {
    for (size_t i = 0; i < mat->rows; ++i) {
        for (size_t j = 0; j < mat->cols; ++j) {
            printf("%d ", mat_get(mat, i, j));
        }
        printf("\n");
    }
}

/*
    @param a A pointer to the first Matrix structure.
    @param b A pointer to the second Matrix structure.
    @return A pointer to a newly allocated Matrix structure containing the sum of the input matrices, or NULL if the matrices have incompatible dimensions.
*/
Matrix* mat_sum(Matrix* a, Matrix* b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        return NULL; 
    }
    Matrix* result = mat_create(a->rows, a->cols);
    for (size_t i = 0; i < a->rows; ++i) {
        for (size_t j = 0; j < a->cols; ++j) {
            int sum = mat_get(a, i, j) + mat_get(b, i, j);
            mat_set(result, i, j, sum);
        }
    }
    return result;
}

/*
    @param a A pointer to the first Matrix structure.
    @param b A pointer to the second Matrix structure.
    @return A pointer to a newly allocated Matrix structure containing the product of the input matrices, or NULL if the matrices have incompatible dimensions.
*/
Matrix* mat_prod(Matrix* a, Matrix* b) {
    if (a->cols != b->rows) {
        return NULL; 
    }
    Matrix* result = mat_create(a->rows, b->cols);
    for (size_t i = 0; i < a->rows; ++i) {
        for (size_t j = 0; j < b->cols; ++j) {
            int sum = 0;
            for (size_t k = 0; k < a->cols; ++k) {
                sum += mat_get(a, i, k) * mat_get(b, k, j);
            }
            mat_set(result, i, j, sum);
        }
    }
    return result;
}



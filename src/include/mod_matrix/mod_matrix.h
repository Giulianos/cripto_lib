#ifndef MOD_MATRIX_H_08b80052e752c78bea7877589436359b
#define MOD_MATRIX_H_08b80052e752c78bea7877589436359b

#include <mod/mod.h>
#include <stdint.h>

typedef struct
{
  uint32_t rows;
  uint32_t cols;
  uint32_t values[];
} matrix_t;

/**
 * @brief Perform m1+m2
 *
 * @param m1
 * @param m2
 * @return matrix_t* a new matrix with the result of the operation
 */
matrix_t*
mod_matrix_sum(matrix_t* m1, matrix_t* m2);

/**
 * @brief Perform m1-m2
 *
 * @param m1
 * @param m2
 * @return matrix_t* a new matrix with the result of the operation
 */
matrix_t*
mod_matrix_sub(matrix_t* m1, matrix_t* m2);

/**
 * @brief Perform m1*m2
 *
 * @param m1
 * @param m2
 * @return matrix_t* a new matrix with the result of the operation
 */
matrix_t*
mod_matrix_mul(matrix_t* m1, matrix_t* m2);

/**
 * @brief Perform e*m
 *
 * @param e
 * @param m
 * @return matrix_t* a new matrix with the result of the operation
 */
matrix_t*
mod_matrix_mul_esc(uint32_t e, matrix_t* m);

/**
 * @brief Transpose m
 *
 * @param m
 * @return matrix_t* a new matrix with m transposed
 */
matrix_t*
mod_matrix_transpose(matrix_t* m);

#endif // MOD_MATRIX_H_08b80052e752c78bea7877589436359b

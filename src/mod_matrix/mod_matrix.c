#include <mod_matrix/mod_matrix.h>
#include <mod_matrix/mod_matrix_macros.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Applies op between elements of the
 * matrices: m1[i,j] op m2[i,j] ; 0<i<rows, 0<j<cols.
 * Matrices sizes must match!
 *
 * @param m1 Matrix 1
 * @param m2 Matrix 2
 * @param op Operator
 * @return matrix_t*
 */
static inline matrix_t*
mod_matrix_binary_elem_op_applier(matrix_t* m1,
                                  matrix_t* m2,
                                  uint32_t (*op)(uint32_t, uint32_t))
{
  if (m1->cols != m2->cols || m1->rows != m2->rows) {
    fprintf(stderr, "Matrix sizes must match!");
    exit(EXIT_FAILURE);
  }

  matrix_t* ans = NEW_MATRIX(m1->cols, m1->rows);
  ans->rows     = m1->rows;
  ans->cols     = m1->cols;

  uint32_t* ans_p = ans->values;
  uint32_t* m1_p  = m1->values;
  uint32_t* m2_p  = m2->values;
  uint32_t i      = ans->cols * ans->rows;

  while (i--) {
    *(ans_p++) = op(*(m1_p++), *(m2_p++));
  }

  return ans;
}

matrix_t*
mod_matrix_sum(matrix_t* m1, matrix_t* m2)
{
  return mod_matrix_binary_elem_op_applier(m1, m2, mod_sum);
}

matrix_t*
mod_matrix_sub(matrix_t* m1, matrix_t* m2)
{
  return mod_matrix_binary_elem_op_applier(m1, m2, mod_sub);
}

matrix_t*
mod_matrix_transpose(matrix_t* m)
{
  matrix_t* ans = NEW_MATRIX(m->cols, m->rows);
  ans->rows     = m->cols;
  ans->cols     = m->rows;

  for (uint32_t row = 0; row < m->rows; row++) {
    for (uint32_t col = 0; col < m->cols; col++) {
      ans->values[col * ans->cols + row] = m->values[row * m->cols + col];
    }
  }

  return ans;
}

matrix_t*
mod_matrix_mul(matrix_t* m1, matrix_t* m2)
{
  if (m1->cols != m2->rows) {
    fprintf(stderr, "Inner matrix dimensions must match!");
    exit(EXIT_FAILURE);
  }

  matrix_t* ans = NEW_MATRIX(m1->rows, m2->cols);
  ans->rows     = m1->rows;
  ans->cols     = m2->cols;

  uint32_t inner_dim = m1->cols;
  uint32_t sum;

  for (uint32_t row = 0; row < ans->rows; row++) {
    for (uint32_t col = 0; col < ans->cols; col++) {
      sum = 0;
      for (uint32_t k = 0; k < inner_dim; k++) {
        sum = mod_sum(sum,
                      mod_mul(m1->values[row * m1->cols + k],
                              m2->values[k * m2->cols + col]));
      }
      ans->values[row * ans->cols + col] = sum;
    }
  }

  return ans;
}

matrix_t*
mod_matrix_mul_esc(uint32_t e, matrix_t* m)
{
  return NULL;
}
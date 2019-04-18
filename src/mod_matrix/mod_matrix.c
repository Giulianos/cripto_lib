#include <mod_matrix/mod_matrix.h>
#include <mod_matrix/mod_matrix_macros.h>
#include <stdio.h>
#include <stdlib.h>

matrix_t*
mod_matrix_sum(matrix_t* m1, matrix_t* m2)
{
  if (m1->cols != m2->cols || m1->rows != m2->rows) {
    fprintf(stderr, "Matrix sizes must match!");
    exit(EXIT_FAILURE);
  }

  matrix_t* sum = NEW_MATRIX(m1->cols, m1->rows);
  sum->rows     = m1->rows;
  sum->cols     = m1->cols;

  uint32_t* sum_p = sum->values;
  uint32_t* m1_p  = m1->values;
  uint32_t* m2_p  = m2->values;
  uint32_t i      = sum->cols * sum->rows;

  while (i--) {
    *(sum_p++) = mod_sum(*(m1_p++), *(m2_p++));
  }

  return sum;
}

matrix_t*
mod_matrix_sub(matrix_t* m1, matrix_t* m2)
{
  if (m1->cols != m2->cols || m1->rows != m2->rows) {
    fprintf(stderr, "Matrix sizes must match!");
    exit(EXIT_FAILURE);
  }

  matrix_t* sub = NEW_MATRIX(m1->cols, m1->rows);
  sub->rows     = m1->rows;
  sub->cols     = m1->cols;

  uint32_t* sub_p = sub->values;
  uint32_t* m1_p  = m1->values;
  uint32_t* m2_p  = m2->values;
  uint32_t i      = sub->cols * sub->rows;

  while (i--) {
    *(sub_p++) = mod_sub(*(m1_p++), *(m2_p++));
  }

  return sub;
}

matrix_t*
mod_matrix_mul(matrix_t* m1, matrix_t* m2)
{
  return NULL;
}

matrix_t*
mod_matrix_mul_esc(uint32_t e, matrix_t* m)
{
  return NULL;
}
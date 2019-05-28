#ifndef MOD_MATRIX_MACROS_H_
#define MOD_MATRIX_MACROS_H_

#include <mod_matrix/mod_matrix.h>
#include <stdlib.h>

#define NEW_MATRIX(rows, cols)                                                 \
  (malloc(sizeof(matrix_t) + (rows) * (cols) * sizeof(uint32_t)))

#define ELEM(matrix_ptr, row, col)                                             \
  ((matrix_ptr)->values[(row) * (matrix_ptr)->cols + (col)])

#endif

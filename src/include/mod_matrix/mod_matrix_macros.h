#ifndef MOD_MATRIX_MACROS_H_
#define MOD_MATRIX_MACROS_H_

#include <mod_matrix/mod_matrix.h>
#include <stdlib.h>

#define NEW_MATRIX(rows, cols)                                                 \
  (malloc(sizeof(matrix_t) + (rows) * (cols) * sizeof(uint32_t)))

#endif

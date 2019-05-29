#ifndef MOD_MATRIX_MACROS_H_23d9ea1f6208868426a402e806ced9f3
#define MOD_MATRIX_MACROS_H_23d9ea1f6208868426a402e806ced9f3

#include <mod_matrix/mod_matrix.h>
#include <stdlib.h>

#define NEW_MATRIX(rows, cols)                                                 \
  (malloc(sizeof(matrix_t) + (rows) * (cols) * sizeof(uint32_t)))

#endif // MOD_MATRIX_MACROS_H_23d9ea1f6208868426a402e806ced9f3

#include <algorithms/algorithms.h>
#include <mod/mod.h>
#include <mod_matrix/mod_matrix.h>
#include <mod_matrix/mod_matrix_macros.h>
#include <stdio.h>
#include <string.h>

/**
 * Find the first non-zero element row
 * in a matrix column
 *
 * @param matrix
 * @param starting_row search will start from this row
 * @param column
 * @param ans here will be setted the result if there is one
 * @return different than 0 if found elem, 0 otherwise
 */
static uint8_t
algorithms_find_non_zero_in_column(const matrix_t* matrix,
                                   uint32_t starting_row,
                                   uint32_t column,
                                   uint32_t* ans)
{
  for (uint32_t row = starting_row; row < matrix->rows; row++) {
    if (ELEM(matrix, row, column) != 0) {
      *ans = row;
      return 1;
    }
  }

  return 0;
}

static void
algorithms_swap_rows(matrix_t* matrix, uint32_t row1, uint32_t row2)
{
  uint32_t temp;

  if (row1 == row2) {
    return;
  }

  /** TODO: test performance against swaping entire rows at once using memcpy */

  for (uint32_t col = 0; col < matrix->cols; col++) {
    temp                    = ELEM(matrix, row1, col);
    ELEM(matrix, row1, col) = ELEM(matrix, row2, col);
    ELEM(matrix, row2, col) = temp;
  }
}

matrix_t*
algorithms_gauss_row_reduction(const matrix_t* matrix)
{
  /** @link
   * https://www.mathworks.com/matlabcentral/answers/441021-row-reduction-using-modular-arithmetic#answer_357676
   */

  matrix_t* m = NEW_MATRIX(matrix->rows, matrix->cols);
  m->rows     = matrix->rows;
  m->cols     = matrix->cols;
  memcpy(m->values, matrix->values, m->rows * m->cols * sizeof(*m->values));

  uint32_t pivot_row   = 0;
  uint32_t pivot_col   = 0;
  uint32_t pivot_value = 0;

  while (pivot_row < m->rows && pivot_col < m->cols) {

    uint32_t temp_idx    = 0;

    /** find the first non-zero remaining in column j */
    if (algorithms_find_non_zero_in_column(
          m, pivot_row, pivot_col, &temp_idx)) {
      /** an element was found */
      pivot_value = ELEM(m, temp_idx, pivot_col);
    } else {
      pivot_value = 0;
    }

    if (pivot_value == 0) {

      /** The column is negligible, zero it out. */
      for (uint32_t row = pivot_row; row < m->rows; row++) {
        ELEM(m, row, pivot_col) = 0;
      }
      pivot_col++;

    } else {

      /** Swap i-th and k-th rows. */
      algorithms_swap_rows(m, pivot_row, temp_idx);

      /** Divide the pivot row by the pivot element. */
      for (uint32_t col = pivot_col; col < m->cols; col++) {
        ELEM(m, pivot_row, col) = mod_div(ELEM(m, pivot_row, col), pivot_value);
      }

      /** Subtract multiples of the pivot row from all the other rows. */
      for (uint32_t row = (pivot_row == 0 ? 1 : 0); row < m->rows;
           row += (row == pivot_row - 1 ? 2 : 1)) {
        uint32_t pivot_temp = ELEM(m, row, pivot_col);
        for (uint32_t col = pivot_col; col < m->cols; col++) {
          ELEM(m, row, col) = mod_sub(
            ELEM(m, row, col), mod_mul(pivot_temp, ELEM(m, pivot_row, col)));
        }
      }

      pivot_row++;
      pivot_col++;
    }
  }

  return m;
}

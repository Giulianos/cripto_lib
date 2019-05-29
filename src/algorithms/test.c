#include <algorithms/algorithms.h>
#include <assert.h>
#include <mod/mod.h>
#include <mod_matrix/mod_matrix_macros.h>
#include <stdio.h>
#include <string.h>

void
cleanup()
{
  mod_terminate();
}

void
setup()
{
  mod_set(251);
}

void
test_gauss_row_reduction()
{
  matrix_t* m1 = NEW_MATRIX(4, 8);

  m1->rows = 4;
  m1->cols = 8;

  uint32_t m1_values[] = {
    77,  130, 213, 186, 1, 0, 0, 0, //
    68,  1,   87,  40,  0, 1, 0, 0, //
    239, 167, 230, 36,  0, 0, 1, 0, //
    14,  154, 146, 180, 0, 0, 0, 1, //
  };

  uint32_t expected_values[] = {
    1, 0, 0, 0, 173, 247, 64,  91,  //
    0, 1, 0, 0, 122, 32,  98,  154, //
    0, 0, 1, 0, 164, 172, 232, 75,  //
    0, 0, 0, 1, 187, 90,  225, 36,  //
  };

  memcpy(m1->values, m1_values, sizeof(m1_values));

  matrix_t* ans = algorithms_gauss_row_reduction(m1);

  assert(memcmp(ans->values, expected_values, sizeof(expected_values)) == 0);

  printf("[test_gauss_row_reduction] passed tests\n");
}

int
main(int argc, char* argv[])
{
  setup();

  test_gauss_row_reduction();

  cleanup();
  return 0;
}

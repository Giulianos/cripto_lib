#include <assert.h>
#include <math.h>
#include <mod_matrix/mod_matrix.h>
#include <mod_matrix/mod_matrix_macros.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

void
print_matrix(matrix_t* m)
{
  for (uint32_t row = 0; row < m->rows; row++) {
    for (uint32_t col = 0; col < m->cols; col++) {
      printf("%d ", m->values[row * m->cols + col]);
    }
    putchar('\n');
  }
}

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
test_sum()
{
  matrix_t* m1 = NEW_MATRIX(4, 4);
  matrix_t* m2 = NEW_MATRIX(4, 4);

  m1->cols = m1->rows = 4;
  m2->cols = m2->rows = 4;

  uint32_t m1_values[] = {
    112, 233, 34,  43,  //
    16,  2,   66,  4,   //
    187, 27,  234, 84,  //
    1,   42,  33,  124, //
  };

  uint32_t m2_values[] = {
    4,   55,  134, 123, //
    126, 32,  66,  24,  //
    198, 217, 64,  45,  //
    89,  32,  33,  13,  //
  };

  uint32_t expected_values[] = {
    116, 37,  168, 166, //
    142, 34,  132, 28,  //
    134, 244, 47,  129, //
    90,  74,  66,  137, //
  };

  memcpy(m1->values, m1_values, sizeof(m1_values));
  memcpy(m2->values, m2_values, sizeof(m2_values));

  matrix_t* ans = mod_matrix_sum(m1, m2);

  assert(memcmp(ans->values, expected_values, sizeof(expected_values)) == 0);

  printf("[test_sum] passed tests\n");
}

void
test_sub()
{
  matrix_t* m1 = NEW_MATRIX(4, 4);
  matrix_t* m2 = NEW_MATRIX(4, 4);

  m1->cols = m1->rows = 4;
  m2->cols = m2->rows = 4;

  uint32_t m1_values[] = {
    112, 233, 34,  43,  //
    16,  2,   66,  4,   //
    187, 27,  234, 84,  //
    1,   42,  33,  124, //
  };

  uint32_t m2_values[] = {
    4,   55,  134, 123, //
    126, 32,  66,  24,  //
    198, 217, 64,  45,  //
    89,  32,  33,  13,  //
  };

  uint32_t expected_values[] = {
    108, 178, 151, 171, //
    141, 221, 0,   231, //
    240, 61,  170, 39,  //
    163, 10,  0,   111, //
  };

  memcpy(m1->values, m1_values, sizeof(m1_values));
  memcpy(m2->values, m2_values, sizeof(m2_values));

  matrix_t* ans = mod_matrix_sub(m1, m2);

  assert(memcmp(ans->values, expected_values, sizeof(expected_values)) == 0);

  printf("[test_sub] passed tests\n");
}

void
test_mul()
{
  matrix_t* m1 = NEW_MATRIX(2, 3);
  matrix_t* m2 = NEW_MATRIX(3, 1);

  m1->rows = 2;
  m1->cols = 3;

  m2->rows = 3;
  m2->cols = 1;

  uint32_t m1_values[] = {
    125, 3,   8,  //
    7,   250, 67, //
  };

  uint32_t m2_values[] = {
    137, //
    8,   //
    13,  //
  };

  uint32_t expected_values[] = {
    185, //
    65,  //
  };

  memcpy(m1->values, m1_values, sizeof(m1_values));
  memcpy(m2->values, m2_values, sizeof(m2_values));

  matrix_t* ans = mod_matrix_mul(m1, m2);

  assert(memcmp(ans->values, expected_values, sizeof(expected_values)) == 0);

  printf("[test_mul] passed tests\n");
}

void
test_mul_esc()
{

  printf("[test_mul_esc] passed tests\n");
}

void
test_transpose()
{
  matrix_t* m = NEW_MATRIX(4, 4);

  m->cols = 3;
  m->rows = 4;

  uint32_t m_values[] = {
    112, 233, 34,  //
    16,  2,   66,  //
    187, 27,  234, //
    1,   42,  33,  //
  };

  memcpy(m->values, m_values, sizeof(m_values));

  uint32_t expected_values[] = {
    112, 16, 187, 1,  //
    233, 2,  27,  42, //
    34,  66, 234, 33, //
  };

  matrix_t* ans = mod_matrix_transpose(m);

  assert(memcmp(ans->values, expected_values, sizeof(expected_values)) == 0);

  printf("[test_transpose] passed tests\n");
}

int
main(int argc, char* argv[])
{
  setup();
  test_sum();
  test_sub();
  test_mul();
  test_mul_esc();
  test_transpose();
  cleanup();
  return 0;
}

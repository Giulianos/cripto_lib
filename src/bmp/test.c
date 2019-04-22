#include <assert.h>
#include <bmp/bmp.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

bmp_t test_bmp;
int   bmp_fd;

void
setup()
{
  char* filename = "MARBLES.bmp";

  bmp_fd   = open(filename, O_RDONLY);
  test_bmp = bmp_load(bmp_fd);
}

void
cleanup()
{
  bmp_free(test_bmp);
  test_bmp = NULL;
  close(bmp_fd);
}

void
test_get_width()
{
  assert(bmp_get_width(test_bmp) == 1419);

  printf("[get_width] passed tests\n");
}

void
test_get_height()
{
  assert(bmp_get_height(test_bmp) == 1001);

  printf("[get_height] passed tests\n");
}

int
main(int argc, char* argv[])
{
  setup();

  test_get_width();
  test_get_height();

  cleanup();

  return 0;
}

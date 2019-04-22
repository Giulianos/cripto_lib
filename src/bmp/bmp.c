#include <bmp/bmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BMP_FILE_IDENTIFIER 0x4D42

struct bmp
{
  uint32_t file_size;
  uint32_t start_offset;
  uint32_t header_size;
  uint32_t width;
  uint32_t height;
  uint16_t bit_planes;
  uint16_t bits_per_pixel;
  uint32_t compression_type;
  uint32_t compressed_size;
  uint32_t horizontal_res;
  uint32_t vertical_res;
  int      fd;
};

static ssize_t
read_uint32(int fd, uint32_t* dest)
{
  uint32_t temp32;
  ssize_t  read_bytes = read(fd, &temp32, sizeof(temp32));
  if (read_bytes == 4) {
    *dest = temp32;
  }
  return read_bytes;
}

static ssize_t
read_uint16(int fd, uint16_t* dest)
{
  uint16_t temp16;
  ssize_t  read_bytes = read(fd, &temp16, sizeof(temp16));
  if (read_bytes == 2) {
    *dest = temp16;
  }
  return read_bytes;
}

bmp_t
bmp_load(int fd)
{
  uint16_t temp = 0;
  char*    error_desc;
  bmp_t    bmp = malloc(sizeof(struct bmp));

  /** Read identifier */
  if (read_uint16(fd, &temp) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  } else if (temp != BMP_FILE_IDENTIFIER) {
    error_desc = "Provided file is not a BMP";
    goto bmp_load_failure_exit;
  }

  /** Read file size */
  if (read_uint32(fd, &bmp->file_size) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  }

  /** Read reserved bytes */
  if (read_uint16(fd, &temp) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  }
  if (read_uint16(fd, &temp) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  }

  /** Read start offset */
  if (read_uint32(fd, &bmp->start_offset) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  }

  /** Read header size */
  if (read_uint32(fd, &bmp->header_size) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  }

  /** Read width */
  if (read_uint32(fd, &(bmp->width)) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  }

  /** Read height */
  if (read_uint32(fd, &(bmp->height)) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  }

  /** Read bit planes */
  if (read_uint16(fd, &bmp->bit_planes) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  }

  /** Read bits per pixel */
  if (read_uint16(fd, &bmp->bits_per_pixel) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  }

  /** Read compression type */
  if (read_uint32(fd, &bmp->compression_type) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  }

  /** Read compressed size */
  if (read_uint32(fd, &bmp->compressed_size) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  }

  /** Read horizontal resolution */
  if (read_uint32(fd, &bmp->horizontal_res) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  }

  /** Read vertical resolution */
  if (read_uint32(fd, &bmp->vertical_res) < 0) {
    error_desc = "Error reading BMP header";
    goto bmp_load_failure_exit;
  }

  /** Store fd for subsequent image read */
  bmp->fd = fd;

  /** Everything ok!*/
  return bmp;

bmp_load_failure_exit:
  fprintf(stderr, "%s", error_desc);
  free(bmp);
  close(fd);
  exit(EXIT_FAILURE);
}

uint32_t
bmp_get_width(const bmp_t bmp)
{
  return bmp->width;
}

uint32_t
bmp_get_height(const bmp_t bmp)
{
  return bmp->height;
}

void
bmp_free(bmp_t bmp)
{
  if (bmp != NULL) {
    free(bmp);
  }
}

#ifndef BMP_H_
#define BMP_H_

#include <stdint.h>

typedef struct bmp* bmp_t;

/**
 * @brief Loads a bitmap from a file
 *
 * @param fd an open file descriptor to read the bmp from
 * @return bmp_t*
 */
bmp_t
bmp_load(int fd);

/**
 * @brief Returns the width of the bitmap in pixels
 *
 * @param bmp
 * @return uint32_t
 */
uint32_t
bmp_get_width(const bmp_t bmp);

/**
 * @brief Returns the height of the bitmap in pixels
 *
 * @param bmp
 * @return uint32_t
 */
uint32_t
bmp_get_height(const bmp_t bmp);

/**
 * @brief Releases allocated resources for passed bmp
 * NOTE: file operations are not handled by the library,
 * this means, the file descriptor won't be closed.
 *
 * @param bmp
 */
void
bmp_free(bmp_t bmp);

#endif // BMP_H_

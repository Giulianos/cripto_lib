#ifndef MOD_H_566715414026afead1d5fa7a531c7970
#define MOD_H_566715414026afead1d5fa7a531c7970

#include <stdint.h>

/**
 * @brief Sets the modulus for all subsequent
 * operations.
 *
 * @param modulus
 * @return uint32_t previous modulus
 */
uint32_t
mod_set(uint32_t modulus);

/**
 * @brief Performs a+b (mod)
 *
 * @param a
 * @param b
 * @return uint32_t operation result
 */
uint32_t
mod_sum(uint32_t a, uint32_t b);

/**
 * @brief Performs a-b (mod)
 *
 * @param a
 * @param b
 * @return uint32_t operation result
 */
uint32_t
mod_sub(uint32_t a, uint32_t b);

/**
 * @brief Performs a*b (mod)
 *
 * @param a
 * @param b
 * @return uint32_t operation result
 */
uint32_t
mod_mul(uint32_t a, uint32_t b);

/**
 * @brief Performs a/b (mod)
 *
 * @param a
 * @param b
 * @return uint32_t operation result
 */
uint32_t
mod_div(uint32_t a, uint32_t b);

/**
 * @brief Release lookup table memory
 *
 */
void
mod_terminate();

#endif // MOD_H_566715414026afead1d5fa7a531c7970

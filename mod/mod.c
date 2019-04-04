#include "mod.h"
#include <stdio.h>
#include <stdlib.h>

static uint32_t mod                 = 251;
static uint32_t* mul_inverse_lookup = NULL;

static inline uint32_t
mod_reduce(uint32_t a)
{
  return a > mod ? a % mod : a;
}

static void
mod_compute_mul_inverse_lookup(uint32_t prev_modulus)
{
  if (!mul_inverse_lookup || mod > prev_modulus) {
    mul_inverse_lookup = realloc(mul_inverse_lookup, mod * sizeof(uint32_t));
  }

  uint32_t* p;
  uint32_t a;
  for (p = mul_inverse_lookup, a = 0; a < mod; a++, p++) {
    /** TODO: change naïve implementation */
    for (uint32_t b = 0; b < mod; b++) {
      if (mod_mul(a, b) == 1) {
        *p = b;
        break;
      }
    }
  }
}

uint32_t
mod_set(uint32_t modulus)
{
  uint32_t prev_modulus = mod;
  mod                   = modulus;

  mod_compute_mul_inverse_lookup(prev_modulus);
  return prev_modulus;
}

uint32_t
mod_sum(uint32_t a, uint32_t b)
{
  return mod_reduce(a + b);
}

uint32_t
mod_sub(uint32_t a, uint32_t b)
{
  return (mod_reduce(a) + (a < b ? mod : 0)) - mod_reduce(b);
}

static inline uint32_t
mod_fast_mul(uint32_t a, uint32_t b)
{
  /** https://en.wikipedia.org/wiki/Modular_arithmetic */
  long double x;
  uint32_t c;
  int32_t r;
  if (a >= mod)
    a %= mod;
  if (b >= mod)
    b %= mod;
  x = a;
  c = x * b / mod;
  r = (int32_t)(a * b - c * mod) % (int32_t)mod;
  return r < 0 ? r + mod : r;
}

uint32_t
mod_mul(uint32_t a, uint32_t b)
{
  return mod_fast_mul(a, b);
}

uint32_t
mod_div(uint32_t a, uint32_t b)
{
  return mod_fast_mul(a, mul_inverse_lookup[mod_reduce(b)]);
}

void
mod_terminate()
{
  if (mul_inverse_lookup) {
    free(mul_inverse_lookup);
    mul_inverse_lookup = NULL;
  }
}
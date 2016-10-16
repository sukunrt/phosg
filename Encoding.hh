#pragma once

#include <stdint.h>


static inline uint64_t bswap16(uint16_t a) {
  return ((a >> 8) & 0x00FF) |
         ((a << 8) & 0xFF00);
}

static inline uint32_t bswap32(uint32_t a) {
  return ((a >> 24) & 0x000000FF) |
         ((a >> 8)  & 0x0000FF00) |
         ((a << 8)  & 0x00FF0000) |
         ((a << 24) & 0xFF000000);
}

static inline uint64_t bswap64(uint64_t a) {
  return ((a >> 56) & 0x00000000000000FF) |
         ((a >> 40) & 0x000000000000FF00) |
         ((a >> 24) & 0x0000000000FF0000) |
         ((a >> 8)  & 0x00000000FF000000) |
         ((a << 8)  & 0x000000FF00000000) |
         ((a << 24) & 0x0000FF0000000000) |
         ((a << 40) & 0x00FF000000000000) |
         ((a << 56) & 0xFF00000000000000);
}
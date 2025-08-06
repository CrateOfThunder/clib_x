/* ---------------------------------------------------------------- */
/* Bidirectional Bit Shifting Extension for Supporting Strings      */
/*          strrox.h -- string bit rotation implementation          */
/* Ver. 1.00                  02AUG2024              CrateOfThunder */
/* ---------------------------------------------------------------- */
#include <stddef.h>

static unsigned char _ror11(unsigned char a, unsigned char b)
{ return ((a << 7) | (b >> 1)); }

static unsigned char _rol11(unsigned char a, unsigned char b)
{ return ((a << 1) | (b >> 7)); }

static unsigned char _ror(unsigned char b)
{ return (b << 7); }

static unsigned char _rol(unsigned char b)
{ return (b >> 7); }

static void _srl(unsigned char *b)
{ *b >>= 1;  return; }

static void _sll(unsigned char *b)
{ *b <<= 1;  return; }

void strrox(void *v, size_t size, size_t nbits, int shift);

/* ---------------------------------------------------------------- */
/* Bidirectional Bit Shifting Extension for Supporting Strings      */
/*          strrox.c -- string bit rotation implementation          */
/* Ver. 1.00                  02AUG2024              CrateOfThunder */
/* ---------------------------------------------------------------- */
#include "strrox.h"

void strrox(void *v, size_t size, size_t nbits, int shift)
{
  unsigned char (*_rox11[2])(unsigned char, unsigned char) =
    { _rol11, _ror11 },
    (*_carry[2])(unsigned char) = { _rol, _ror },
    (*carry)(unsigned char),
    *p1, *p2, *pp[2], *ptr, carry_bit;
  void (*_srx[2])(unsigned char *) = { _sll, _srl };
  int xcrement;

  if ((size == 0) || (nbits == 0) || ((shift != 1) && (shift != 0)))
    return;

  xcrement = ~shift + (!shift + 1);
  carry = _carry[shift];
  p1 = (unsigned char *)v;
  p2 = &p1[size - 1];

  do {
    pp[0] = p1;
    pp[1] = p2;
    ptr = pp[shift];
    carry_bit = carry(*ptr);

    while (ptr != pp[!shift]) {
      *ptr = _rox11[shift](ptr[-shift], ptr[!shift]);
      ptr = ptr + xcrement;
    }

    _srx[shift](ptr);
    *ptr |= carry_bit;
  } while (--nbits);

  return;
}

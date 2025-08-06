/* ---------------------------------------------------------------- */
/* C Library Extension for String Reversal                          */
/*        xstrrev.c -- agnostic data inversion implementation       */
/* Ver. 1.00                  08AUG2024              CrateOfThunder */
/* ---------------------------------------------------------------- */
#include "xstrrev.h"

void xstrrev(void *v, size_t n)
{
  if ((v != NULL) && (n > 1)) {
    unsigned char *beg = (unsigned char *)v, *end = &beg[n - 1], tmp;

    n >>= 1; /* halve the volume */

    do {
      tmp = *beg;
      *beg++ = *end;
      *end-- = tmp;
    } while (--n);
  }

  return;
}

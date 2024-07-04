/* string vector for dynamic allocation */

#include <stdio.h>
#include "str_vec.h"

int main(void)
{
  int i = 0;
  str_vec v;
  vector_init(&v);

  vector_add(&v, "KOLOR ACRILICO STANDARD SEMIBRILHO ANTIG0");
  vector_add(&v, "0");
  vector_add(&v, "1.0000 1.0000");
  vector_add(&v, "BL-113");
  vector_add(&v, "BASE B");
  vector_add(&v, "\"\"200");
  vector_add(&v, "10,0.236296311,12,2.55827165,3,0.7520988,9,0.403950632\" 200");
  vector_add(&v, "200");

  for (i = 0; i < vector_total(&v); i++)
	printf("%s ", (char *) vector_get(&v, i));
  printf("\n");

  vector_free(&v);
  
  return 0;
}

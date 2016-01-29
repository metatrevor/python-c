#include "factorial.h"

int get_factorial(int x)
{
  int c;
  int result = 1;

  for (c = 1; c <= x; c++)
    result = result * c;

    return result;
}

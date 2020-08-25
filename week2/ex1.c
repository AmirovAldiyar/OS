#include <limits.h>
#include <float.h>
#include <stdio.h>

int main(){
  int maxInt = INT_MAX;
  float maxFloat = FLT_MAX;
  double maxDouble = DBL_MAX;
  printf("max integer: %d\nsize of integer: %lu\n", maxInt, sizeof(maxInt));
  printf("max float: %f\nsize of float: %lu\n", maxFloat, sizeof(maxFloat));
  printf("max double: %f\nsize of double: %lu\n", maxDouble, sizeof(maxDouble));
}

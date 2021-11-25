#include <stddef.h>
#include <stdio.h>

char *odd_or_even(int *v, int sz){
    int i = 0;
    int sum = 0;
    while(i<s){
        sum += v[i]
        i++;
    }
    return (sum%2 == 0) ? "even" : "odd";
}

/*
BEST CLEVER SOLUTION

#include <stddef.h>

const char *odd_or_even(const int *v, size_t sz) {
  long sum = 0;
  while (sz--) sum += *v++;
  return sum & 1 ? "odd" : "even";
}

*/
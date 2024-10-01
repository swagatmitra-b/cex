#include <stdio.h>
#include <stdlib.h>

struct Array {
  size_t size;
  int *vals;
} typedef Array;

void print(Array arr);
Array *createDynArr(size_t size);
void push(Array *a, int val);
void pop(Array *a);
void pull(Array *a, int val);

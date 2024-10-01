#include <stdio.h>
#include <stdlib.h>
#include "dynarr.h"

void print(Array arr) {
  for(size_t i = 0; i < arr.size; i++) {
     printf("%d ", arr.vals[i]); 
  }
  printf("\n");
}

Array *createDynArr(size_t size) {
  Array *newArr = malloc(sizeof(Array));
  newArr->size = size;
  newArr->vals = malloc(size * sizeof(int));

  return newArr;
}

void push(Array *a, int val) {
  size_t newLength = a->size + 1;
  int *newArr = realloc(a->vals, newLength * sizeof(int));
  if (newArr != NULL) {
    a->size = newLength;
    a->vals = newArr;
    a->vals[a->size - 1] = val;
  }
}

void pop(Array *a) {
  size_t newLength = a->size - 1;
  int *newArr = realloc(a->vals, newLength * sizeof(int));
  if (newArr != NULL) {
    a->size = newLength;
    a->vals = newArr;
  }
}

void pull(Array *a, int val) {
  size_t newLength = a->size + 1;
  int *newArr = realloc(a->vals, newLength * sizeof(int));
  if (newArr != NULL) {
    for (size_t i = newLength - 1; i >= 1; i--) {
        newArr[i] = newArr[i-1];
    }
    newArr[0] = val;
    a->size = newLength;
    a->vals = newArr;
  }
}

int main() {
  Array *a = createDynArr(3);
  a->vals[0] = 1;  
  print(*a);  
  push(a, 4);
  print(*a);  
  push(a, 5);
  print(*a);  
  pop(a);
  print(*a);  
  pop(a);
  print(*a);  
  pull(a, 6);
  print(*a); 
  pull(a, 7);
  push(a, 8);
  print(*a); 
}


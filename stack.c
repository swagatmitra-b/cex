#include <stdio.h>
#include <stdlib.h>
#include "dbl.h"

struct Stack {
  Dbl *stack;
  int top;
} typedef Stack;

Stack *createStack(int val) {
  Dbl *list = createList(val);
  Stack *st = malloc(sizeof(Stack));
  st->stack = list;
  st->top = val;

  return st;
}

void push(Stack *st, int val) {
  Dbl *stackList = st->stack;
  Node *newNode = malloc(sizeof(Node));
  
  newNode->value = val;
  newNode->next = stackList->head;
  newNode->prev = NULL;

  stackList->head = newNode;
  st->top = st->stack->head->value;
}

int pop(Stack *st) {
  Dbl *list = st->stack;
  
  Node *target = list->head;
  int popVal = target->value;
  
  list->head = target->next;
  list->head->prev = NULL;
  
  st->top = st->stack->head->value;
  

  free(target);
  
  return popVal;
}

void printStack(Stack st) {
  Node *original= st.stack->head;
  while(st.stack->head != NULL) {
    printf("%d -> ", st.stack->head->value);
    st.stack->head = st.stack->head->next;
  }
  st.stack->head = original;
  printf("\n");
}

int main() {
  Stack *st = createStack(1); 
  push(st, 2);
  printStack(*st);
  push(st, 3);
  printStack(*st);
  push(st, 4);
  printStack(*st);
  push(st, 5);
  printStack(*st);
  push(st, 6);
  printStack(*st);
  push(st, 7);
  printStack(*st);
  pop(st);
  pop(st);
  printStack(*st);
}

#include <stdio.h>
#include <stdlib.h>
#include "dbl.h"

Dbl *createList(int val) {
  Node *firstNode = malloc(sizeof(Node));
  Dbl *list = malloc(sizeof(Dbl)); 
  
  firstNode->value = val;
  firstNode->prev = NULL;
  firstNode->next = NULL;

  list->head = firstNode;
  list->tail = firstNode;
  
  return list;
}

void insertNode(Dbl *list, int val) {
  Node *newNode = malloc(sizeof(Node));

  newNode->value = val;
  newNode->prev = list->tail;
  newNode->next = NULL;
  
  list->tail->next = newNode;
  list->tail = newNode;
}

void deleteNode(Dbl *list, int val) {
  Node *original = list->head;
  while(list->head->value != val) {
    list->head = list->head->next;
  };
  
  if(list->head->prev != NULL)
    list->head->prev->next = list->head->next;
  else {
    original = list->head->next;
  }
  if(list->head->next != NULL)
    list->head->next->prev = list->head->prev;
  else {
    list->tail = list->tail->prev;
  }
  
  Node *target = list->head;
  target->prev = NULL;
  target->next = NULL;

  list->head = original;
  free(target);
}

void printList(Dbl list) {
  while(list.head != NULL) {
    printf("%d -> ", list.head->value);
    list.head = list.head->next;
  }
  printf("\n");
}

// int main() {
//   Dbl *list = createList(4);
//   insertNode(list, 5);
//   insertNode(list, 6);
//   insertNode(list, 7);
//   insertNode(list, 8);
//   insertNode(list, 9);
//   printf("%d\n", list->head->value);
//   printf("%d\n", list->tail->value);
//   printList(*list);
//   deleteNode(list, 7);
//   printList(*list);
//   printf("%d\n", list->head->value);
//   printf("%d\n", list->tail->value);
// }


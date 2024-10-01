#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node *prev;
  struct Node *next;
} typedef Node;

struct Dblinked {
  struct Node *head;
  struct Node *tail;
} typedef Dbl;

Dbl *createList(int val);
void insertNode(Dbl *list, int val);
void deleteNode(Dbl *list, int val);
void printList(Dbl list);

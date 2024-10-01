#include <stdio.h>
#include <stdlib.h>
#include "dbl.h"

struct Queue {
  Dbl *queue;
  int first;
  int last;
} typedef Queue;

Queue *createQueue(int val) {
  Dbl *list = createList(val);
  
  Queue *newQueue = malloc(sizeof(Queue));
  
  newQueue->queue = list;
  newQueue->first = list->head->value;
  newQueue->last = list->tail->value;
  
  return newQueue;
}

void enqueue(Queue *q, int val) {
  insertNode(q->queue, val);
  q->last = q->queue->tail->value;
}

int dequeue(Queue *q) {
  Dbl *list = q->queue;
  
  Node *target = list->head;
  int popVal = target->value;
  
  list->head = target->next;
  list->head->prev = NULL;
  
  q->first = q->queue->head->value;
  
  free(target);

  return popVal;
}

void printQueue(Queue q) {
  Node *original= q.queue->head;
  while(q.queue->head != NULL) {
    printf("%d -> ", q.queue->head->value);
    q.queue->head = q.queue->head->next;
  }
  q.queue->head = original;
  printf("\n");
}

int main() {
  Queue *q = createQueue(5);
  enqueue(q, 6);
  printQueue(*q);
  enqueue(q, 7);
  printQueue(*q);
  enqueue(q, 8);
  printQueue(*q);
  enqueue(q, 9);
  printQueue(*q);
  enqueue(q, 10);
  printQueue(*q);
  dequeue(q);
  printQueue(*q);
  dequeue(q);
  printQueue(*q);
}

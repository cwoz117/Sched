/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                        processQueue.h                             *
 *                                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <pthread.h>
#include <stdlib.h>

struct process {
  pthread_mutex_t state;
  int waitTime;
  int burstTime;
  int quantum;
  char name[3];
  pthread_t proc;
};

struct node {
  struct process *data;
  struct node *next;
};

extern struct node *head;
extern struct node *tail;

void addProcess(struct process *p){
  printf("inside addProcess\n");
  if (head == NULL){
    printf("head was empty\n");
    head = malloc(sizeof(struct node*));
    head->data = p;
    tail = head;
    printf("added to head\n");
  } else {
    printf("head isnt empty, adding to tail\n");
    struct node tmp;
    tmp.data = (struct process*)p;
    tmp.next = NULL;
    tail->next = (struct node*)&tmp;
    tail = (struct node*)&tmp;
  }
}

struct process *nextProcess(){
  struct node *n;
  struct process *tmp;
  n = (struct node*)head;
  tmp = (struct process*)head->data;
  head = (struct node*)head->next;
  free(n);
  return (struct process*)tmp;
}

int isFull(){
  if (head == NULL){
    return 1;
  } else {
    return 0;
  }
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END O *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */






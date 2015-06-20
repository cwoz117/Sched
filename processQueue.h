/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                        processQueue.h                             *
 *                                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <pthread.h>
#include <stdlib.h>

struct processNode {
  int waitTime;
  char name[2];
  int burstTime;
  pthread_t proc;
  struct processNode *next;
};

extern struct processNode *head;
extern struct processNode *tail;


void addProcess (pthread_t p){
  struct processNode *tmp;
  if (head == NULL){
    tmp = malloc(sizeof(struct processNode));
    tmp->proc = p;
    head = tmp;
    head->next = NULL;
    tail = head;
  } else {
    tmp = malloc(sizeof(struct processNode));
    tmp->proc = p;
    tail->next = tmp;
    tail = tail->next;
  }
}

struct processNode *nextProcess(){
  struct processNode *tmp;
  tmp = head;
  head = head->next;
  return tmp;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END OF *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */







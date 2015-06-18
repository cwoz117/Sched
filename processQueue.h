/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                        processQueue.h                             *
 *                                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <pthread.h>


struct processNode {
  p_thread proc;
  struct processNode *next;
};

extern processNode *head;
extern processNode *tail;


void addProcess (p_thread p){
  if (head == NULL){
    struct processNode tmp;
    tmp =(struct processNode *)malloc(sizeof(struct processNode));
    tmp.proc = p
    head = &tmp;
    head->next = NULL;
    tail = head;
  } else {
    struct processNode tmp;
    tmp = (struct processNode *)malloc(sizeof(struct processNode));
    tmp.proc = p;
    tail.next = tmp;
    tail = tail.next;
  }
}

processNode nextProcess(){
  processNode tmp = head;
  head = head.next;
 
  if (tmp == NULL){
    return NULL;
  }else {
    return tmp;
  }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END OF *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */







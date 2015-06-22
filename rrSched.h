/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                           rrSched.h                               *
 *                                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "processQueue.h"
#include <stdio.h>
#include <string.h>

struct schedule {
  int size;
  struct process *mem;
};

void *runningProcess(void *v){
  struct process *p = (struct process*)v;
  pthread_mutex_lock(&p->state);
  printf("I'm from a simulated process\n");
  sleep(p->quantum*1000);
  p->burstTime -= p->quantum;
  pthread_mutex_unlock(&p->state);
  pthread_yield();
}

void setupQueue(struct process *p, int s){
  int i;
  printf("Starting to setup a queue\n");
  for (i = 0; i < s; i++){
    printf("locking state\n");
    pthread_mutex_lock(&p[i].state);
    if (p[i].waitTime <= 1){
      printf("adding a process to the queue\n");
      addProcess(&p[i]);
    } else {
      printf("subtracting from the wait time\n");
      p[i].waitTime -= 1;
    }
  }
}

void startProcess(){
  struct process *p;
  p = nextProcess();
  printf("unlock state\n");
  pthread_mutex_unlock(&p->state);
  printf("running simulated process\n");
  int i = pthread_create(&p->proc, NULL, runningProcess, (void *)&p);
  printf("yield control to the scheduler\n");
  pthread_yield();
  pthread_mutex_lock(&p->state);
}

void* roundRobinStart(void *arg){
  struct schedule *sd =(struct schedule *)arg;
  printf("Round Robin Scheduler started\n");
  while (isFull() == 1){
    printf("Setting up the queue\n");
    setupQueue(sd->mem, sd->size);
    printf("start the process thread\n");
    startProcess();
  }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END O *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

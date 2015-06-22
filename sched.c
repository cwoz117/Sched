/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                             sched.c                               *
 *                                                                   *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "rrSched.h"

struct node *head;
struct node *tail;

int main(int argc, char *argv[]){
  FILE *fd;
  char buffer[32];
  char *tok;

  // Open file and confirm.
  fd = fopen(argv[1], "r");
  if (fd == NULL){
    printf("Unable to open file %s\n", argv[1]);
    exit(0);
  }
 
  // strip top file from config.
  if (fgets(buffer, 32, fd) == NULL){
    printf("Config file does not have the correct format\n");
    exit(0);
  }
  tok = strtok(buffer, " ");
  tok = strtok(NULL, " ");
  tok = strtok(NULL, " ");
  int val = atoi(tok);
  struct process *mem = malloc(val*sizeof(struct process));

  // Parse the config file, store into memory.
  int i = 0;
  while (fgets(buffer, 32, fd) != NULL){
    tok = strtok(buffer, " ");
    mem[i].waitTime = atoi(tok);
    
    tok = strtok(NULL, " ");
    strcpy(mem[i].name, tok);
    
    tok = strtok(NULL, " ");
    mem[i].burstTime = atoi(tok);

    mem[i].quantum = atoi(argv[5]);

    pthread_mutex_init(&mem[i].state, NULL);
    i++;
  }
  printf("Before the scheduler\n");
  // Confirm which scheduler to run
  pthread_t scheduler;  
  struct schedule s;
  s.size = val;
  s.mem = mem;
  i = pthread_create(&scheduler, NULL, &roundRobinStart, (void *)&s);
  if (i != 0){
    printf("Scheduler could not start.\n");
  }
  printf("After the scheduler starts\n");
  // Start the Output.


  // Wait for the threads to join

  i = pthread_join(scheduler, NULL);
  printf("The scheduler joined\n");
  //pthread_join(reporting);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE END O *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

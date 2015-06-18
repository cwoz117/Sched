/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                    processQueue.h                       *
 *                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <pthread.h>


struct processNode {
  p_thread proc;
  struct processNode next;
};

processNode head;
processNode tail;


void addProcess (p_thread &p){


}

processNode nextProcess(){
  processNode tmp = head;


}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 END OF FILE END OF FILE END OF FILE END OF FILE END OF FILE
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */







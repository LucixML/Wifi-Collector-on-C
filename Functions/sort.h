/**Function********************************************************************

  Synopsis           This function implements the action of collecting the data
                      of a cell asked by the user

  SideEffects        It stors the data from the asked cell in the struct array
                    "mydat"  as many times as the user wants and also prints
                     the data it's storing

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Functions/showdataonenetwork.h"

/****First we check if we have already collected any data, if not we print so
    *then, we compare the quality info with each others and order the array in descending order
    *finally, we print the array with the quality value that corresponds to it
****/
extern Node *head;
int sort(void){
  Node *tosort;

  tosort = head;

  if (numwifis == 0){
    printf("\nNothing has been stored yet");
      return 0;
  }

    Node tmp;

    while(tosort!=NULL) {
      Node *aux = tosort->next;
      while(aux!=NULL) {
        if (atoi(tosort->mydata.quality) < atoi(aux->mydata.quality)) {
          tmp.mydata = tosort->mydata;
          tosort->mydata = aux->mydata;
          aux->mydata = tmp.mydata;
        }
        aux = aux->next;
      }
      tosort = tosort->next;
    }

    while (head != NULL) {
      float qvalue;
      int num;
      char strnum[2];
      strncpy(strnum,head->mydata.quality,2);
      num = atoi(strnum);
      qvalue=(num+0.00)/70.0;
      printf( "\nData read from the linked list: %d %s %s %s %d %s %s %s %s (calculated signal quality %f)", head->mydata.cell,head->mydata.address, head->mydata.essid, head->mydata.mode, head->mydata.channel, head->mydata.ek, head->mydata.quality, head->mydata.frequency, head->mydata.signal_level, qvalue);
      head = head->next;
    }


    return 0;
}

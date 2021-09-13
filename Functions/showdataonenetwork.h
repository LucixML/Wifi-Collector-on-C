/**Function********************************************************************

  Synopsis           This function implements the action of searching for an
                     ESSID the user wants

  SideEffects        It prints the first found wifi with the wanted ESSID and
                    if none is found prints that there is no wifi with that
                    ESSID

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../Functions/collect.h"
#include "../Variables/essidsearch.h"
#include "../Variables/notfound.h"

/****First we check if we have already collected any data, if not we print so
    *then, we ask the user the ESSID they want to search for
    *If we enter ctrl-d we go back to the main menu
    *We compare each essid that has been stored with the one we are searching for
    *If we find a match we print the wifi that and stop searching
    *If we don't find a match we print that there is no ESSID with what the user search for
****/
extern Node *head;
int showdataonenetwork(void){
    unsigned notfound = -1;

    Node *showdata;
    showdata = clone_list(head);

    if (numwifis == 0){
      printf("\nNothing has been stored yet");
        return 0;
    }

    printf("\nIndicate the ESSID (use \"\")");
    res = scanf("%s", essidsearch);
    if(res==EOF){
      printf("\n");
      return 0;
    }

    while (showdata != NULL){
      if(!strcmp(showdata->mydata.essid,essidsearch)){
        printf( "\nData read from the linked list: %d %s %s %s %d %s %s %s %s", showdata->mydata.cell,showdata->mydata.address, showdata->mydata.essid, showdata->mydata.mode, showdata->mydata.channel, showdata->mydata.ek, showdata->mydata.quality, showdata->mydata.frequency, showdata->mydata.signal_level);
        notfound = 10;
        break;
      }
    showdata = showdata->next;
    }

    if(notfound == -1){
      printf("\nCell with ESSID %s not found in the dynamic array", essidsearch);
    }

    return 0;
}

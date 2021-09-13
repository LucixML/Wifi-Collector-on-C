/**Function********************************************************************

  Synopsis      Funtion to print the list in collect as we go adding positions

  SideEffects   The list is printed

******************************************************************************/
#include "../Functions/append.h"

void print_list(Node *head, int cellv) {
    while (head != NULL) {
      if(head->mydata.cell==cellv){
        printf( "\nData read from info_cell_%d.txt: %d %s %s %s %d %s %s %s %s (inserted at the end of the linked list)",head->mydata.cell, head->mydata.cell,head->mydata.address, head->mydata.essid, head->mydata.mode, head->mydata.channel, head->mydata.ek, head->mydata.quality, head->mydata.frequency, head->mydata.signal_level);
      }
      head = head->next;
    }
    printf("\n");
}

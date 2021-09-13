/**Function********************************************************************

  Synopsis

  SideEffects

******************************************************************************/
#include "../Functions/print_list.h"

void swap(Node *a, Node *b) {
    Node tmp;
    tmp.mydata = a->mydata;
    a->mydata = b->mydata;
    b->mydata = tmp.mydata;
}

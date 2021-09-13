/**Function********************************************************************

  Synopsis        This is a function to add a node to the end of the list

  SideEffects     Adds a given node in the end of the list

******************************************************************************/
#include "../Functions/create_node.h"

void append(Node **head_ref, Node *new_node) {
    Node *last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}

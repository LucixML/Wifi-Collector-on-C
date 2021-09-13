/**Function********************************************************************

  Synopsis        Function to duplicate a list

  SideEffects     A clone list of a given one is created

******************************************************************************/
#include "../Functions/print_list.h"
void push(Node **head_ref, Node *new_node) {
    new_node->next = *head_ref;
    *head_ref = new_node;
}
Node* clone_list(Node *head) {
    Node *current = head;
    Node *new_list = NULL;
    Node *tail = NULL;

    while (current != NULL) {
        Node *new_node = (Node*) malloc(sizeof(Node));
        memcpy(new_node, current, sizeof(Node));

        if (new_list == NULL) {
            push(&new_list, new_node);
            tail = new_list;
        } else {
            push(&(tail->next), new_node);
            tail = tail->next;
        }
        current = current->next;
    }

    return new_list;
}

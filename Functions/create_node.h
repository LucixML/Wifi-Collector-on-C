/**Function********************************************************************

  Synopsis      Function to create a new node with the given info from the txt

  SideEffects   A new node is created

******************************************************************************/
#include "../Structures/Node.h"

Node* create_node(int cell, char *address, char *essid, char *mode, int channel, char *ek, char *quality, char *frequency, char *signal_level) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->mydata.cell = cell;
    strncpy(node->mydata.address, address, strlen(address));
    strncpy(node->mydata.essid, essid, strlen(essid));
    strncpy(node->mydata.mode, mode, strlen(mode));
    node->mydata.channel = channel;
    strncpy(node->mydata.ek, ek, strlen(ek));
    strncpy(node->mydata.quality, quality, strlen(quality));
    strncpy(node->mydata.frequency, frequency, strlen(frequency));
    strncpy(node->mydata.signal_level, signal_level, strlen(signal_level));
    node->next = NULL;

    return node;
}

void initializehead(Node *head){
  head = NULL;
}

/**Variable********************************************************************

  Synopsis    Creation of pointer "mydata" of type data, that is used to store the collected data

******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_SIZE 80

typedef struct data {
  int cell;
  char address[CHAR_SIZE];
  char essid[CHAR_SIZE];
  char mode[CHAR_SIZE];
  int channel;
  char ek[CHAR_SIZE];
  char quality[CHAR_SIZE];
  char frequency[CHAR_SIZE];
  char signal_level[CHAR_SIZE];
}data;

typedef struct Node {
    data mydata;
    struct Node *next;
} Node;

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

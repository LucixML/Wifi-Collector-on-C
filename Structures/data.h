/**Struct**********************************************************************

  Synopsis    Creation of struct that contains the data we have to collect for each cell

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

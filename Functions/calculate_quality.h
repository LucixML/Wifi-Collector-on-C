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

float calculate_quality(char *str){
 char *strnum;
  int num;
  float qvalue;
  strncpy(strnum,str,2);
  num = atoi(strnum);
  qvalue=(num+0.00)/70.0;
  return qvalue;
}

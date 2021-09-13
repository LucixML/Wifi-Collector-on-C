/**Struct**********************************************************************

  Synopsis    Creation of struct that contains the date and the position of the ode. then we crate the list

******************************************************************************/
#include "../Structures/data.h"

typedef struct Node {
    data mydata;
    struct Node *next;
} Node;

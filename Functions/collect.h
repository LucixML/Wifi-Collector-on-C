/**Function********************************************************************

  Synopsis           This function implements the action of collecting the data
                      of a cell asked by the user

  SideEffects        It stors the data from the asked cell in linked list head
                      as many times as the user wants and also prints
                     the data it's storing

******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Variables/cell.h"
#include "../Variables/exit_2.h"
#include "../Variables/file.h"
#include "../Variables/n.h"
#include "../Variables/i.h"
#include "../Variables/numwifis.h"
#include "../Variables/res.h"

#include "../Functions/clone_list.h"
extern Node *head;
int collect(void){

  do{

    /****First we ask the user what cell do they want to collect and stor it in a char*
        *If we enter ctrl-d we go back to the main menu
        *Then we convert the char* to a number and check that its one of the possible cells
        *if it is not ask again until it is
        *then we get the file name by concatenating the char* containing the cell and a char* name file
        *we open the file and check that it isn't empty
        *we scan the file with the given struct
        *we store whats scanned in the linked list, first creating a new node and then putting it at the end of the list
        *we print the stored info
        *we ask if we want to acces another cell
        *If we enter ctrl-d we go back to the main menu
        *we check what the user enter to check if it match the options
        *if not we ask again until it does
        *we keep implementing the function until the user tell us they don't want to anymore
    ****/


    printf("\n  What cell do you want to collect?: ");

    do{
      res = scanf("%s", cell);
      n = atoi(cell);
      if(res==EOF){
        printf("\n");
        return 0;}
      if ( n < 1 || n > 21 ){printf("Please introduce a number between 1-21\n");}
    }while(( n < 1 || n > 21 ));

    strcpy(file,"./cells/info_cell_");
    strncat(file,cell,12);
    strncat(file,".txt",12);

    FILE* pointer = fopen(file,"r");
    if (pointer == NULL) {
      printf("No file found.");
    }

    int cellv;
    char addressv[200];
    char essidv[200];
    char modev[200];
    int channelv;
    char ekv[200];
    char qualityv[200];
    char frequencyv[200];
    char signal_levelv[200];
    Node *new_node;

    while(fscanf( pointer, " Cell %d\nAddress: %s\nESSID:%s\nMode:%s\nChannel:%d\nEncryption key:%s\nQuality=%s\nFrequency:%s GHz\nSignal level=%s dBm",&cellv, addressv, essidv, modev, &channelv, ekv, qualityv, frequencyv, signal_levelv) != EOF){

      new_node = create_node(cellv, addressv, essidv, modev, channelv, ekv, qualityv, frequencyv, signal_levelv);
      append(&head, new_node);
      i++;

      addressv =="";
      essidv =="";
      modev =="";
      ekv =="";
      qualityv=="";
      frequencyv=="";
      signal_levelv=="";

      numwifis += 1;
    }

    print_list(head, cellv);

    printf("\n   \nDo you want to add another access point? [y/n]");

    do{
      res = scanf(" %s", exit_2);
      if(res==EOF){
        printf("\n");
        return 0;}
      if(strcmp(exit_2,"y") && strcmp(exit_2,"n")){
        printf("\nInvalid character! Please introduce y for accesing another point and n for going back to the main menu\n");}
    }while(strcmp(exit_2,"y") && strcmp(exit_2,"n"));

  }while(strcmp(exit_2,"n"));
  return 0;

}

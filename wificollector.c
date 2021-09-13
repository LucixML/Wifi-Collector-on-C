
/**CFile***********************************************************************

  FileName    wificollector.c

  Synopsis    It implements the wificollector app

  Authors     Lucía Moreno López y Lucía Galvez

  Copyright   [Copyright (c) 2012 Carlos III University of Madrid
  All rights reserved.

  Permission is hereby granted, without written agreement and without license
  or royalty fees, to use, copy, modify, and distribute this software and its
  documentation for any purpose, provided that the above copyright notice and
  the following two paragraphs appear in all copies of this software.

  IN NO EVENT SHALL THE CARLOS III UNIVERSITY OF MADRID BE LIABLE TO ANY PARTY
  FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING
  OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE CARLOS III
  UNIVERSITY OF MADRID HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

  THE CARLOS III UNIVERSITY OF MADRID SPECIFICALLY DISCLAIMS ANY WARRANTIES,
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
  FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS ON AN
  "AS IS" BASIS, AND CARLOS III UNIVERSITY OF MADRID HAS NO OBLIGATION TO
  PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.]

******************************************************************************/


#include "./Functions/printmenu.h"
#include "./Variables/optionchar.h"
#include "./Variables/option.h"
#include "./Variables/exit_1.h"
#include "./Functions/sort.h"

Node *head;
int main(int argc, char*argv[]){
  /****We print the menu
      *ask for the option we want to implement as a type char to avoid errors when a character that is not a number is introduced
      *convert the option to int
      *If we enter ctrl-d we go back to the main menu
      *check that the number is one of the possible options an if its not ask again until it is
      *implement the option
      *do so until the user confirms he/she wants to exit the app
  ****/
  initializehead(head);
  do
    {
      printmenu();

        printf("\n  Option: ");

      do{
        res = scanf("%s", optionchar);
        option = atoi(optionchar);
        if(res==EOF){
          printf("\n");
          exit(0);}
        if ( option < 1 || option > 8 ){printf("Please introduce a number between 1-8\n");}
      }while( option < 1 || option > 8 );

      switch (option) {
        case 1:

        /****When we chose option 1 we ask the user if they are sure they want to exit the app
            *If they enter ctrl-d we go back to the main menu
            *if they are we free the linked list and say Goodbye!
            *if they introduce something different from the given options (y/n) we ask again until they introduce one of the options
        ****/

          printf("Are you sure you want to exit? [y/N]:" );
          do{
            res=scanf(" %c", &exit_1);
            if(res==EOF){
              printf("\n");
              break;
            }
            if(exit_1=='y'){
              free(head);
              printf("\nData from the linked list freed \nGoodbye!\n");
            }
            if(exit_1!='y' && exit_1!='n'){
              printf("Invalid character! Please introduce y for exit and n for continuing in the program\n");
            }
          }while(exit_1!='y' && exit_1!='n');
        break;
        case 2:

        /****When option 2 is choosen we implement the collect function explained in its own file
            *When option 3 is choosen we implement the showdataonenetwork function explained in its own file
            *When option 2 is choosen we implement the sort function explained in its own file
            *When any other option is choosen we tell the user that this function is not avaliable yet and go back to the menu
        ***/
          collect();
          break;

        case 3:
          showdataonenetwork();
          break;
        case 4:
          printf(
            "\n This function is not avaliable yet, try another one \n"
          );
          break;
        case 5:
          printf(
            "\n This function is not avaliable yet, try another one \n"
          );
          break;
        case 6:
          sort();
          break;
        case 7:
          printf(
            "\n This function is not avaliable yet, try another one \n"
          );
          break;
        case 8:
          printf(
            "\n This function is not avaliable yet, try another one \n"
          );
          break;
        default:
          printf("error ");
      }

  }while(exit_1!='y');

  return 0;
  }

/************************************************************************
 * main.c
 * main() function of CD database program.
 ************************************************************************/

#include <stdio.h>
#include "database.h"


int main(void)
{
    int option;

    // Display the list of options, read and process options the user wants 
    // until user wants to QUIT.
    do
    {
        option = get_option();
        switch (option) {
            
            case 0:
                puts(LEAD_WS "Quitting the program.");
                break;
            case 1:
                create_record();   // create new list of CDs
                break;
            case 2:
                view_entry();      // view Nth CD of a record
                break;
            case 3:
                view_record();     // view all CDs of a record
                break;
            case 4:
                append_record();   // add CDs to end of a record
                break;
            case 5:
                save_record_as();  // save record in a diffrent name
                break;
            case 6:
                delete_record();   // delete a record
                break;

            default:
                fprintf(stderr, "Unrecognized option: %d\n", option);
                break;
        }

    } while (option);

    return (0);
}

/* TODO: This is just temporary - Delete when all functions are coded.  */
void not_implemented(void)
{
    puts("  ########################");
    puts("      NOT_IMPLEMENTED");
    puts("  ########################");
}

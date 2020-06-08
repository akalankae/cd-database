/***********************************************************************
 * option_menu.c
 * Display user menu and get user option.
 *
 ************************************************************************/
#include "database.h"

#define LEADING_SPACE "  "

/************************************************************************
 *                      get_option()                                    *
 *                                                                      *
 * Display a menu with the list of options to select from. User has to  *
 * enter numerical value for the option, and that integer value is      *
 * returned by this function to the caller.                             *
 ************************************************************************/
int get_option(void)
{
    int option;                 // Preferred option
    int num_options;            // Number of options available to user
    static char *options[] = {
        "Quit Program",
        "Create New Record",
        "View Entry",
        "View Record",
        "Append to Record",
        "Save Record As",
        "Delete Record"
    };

    num_options = sizeof (options) / sizeof (options[0]);

    // Print out an introductory message & the menu
    puts("\n" LEADING_SPACE "CD database program.");
    puts(LEADING_SPACE "====================\n");
    puts("Select an option to proceed.");
    for (int i = 0; i < num_options; i++)
        printf(LEADING_SPACE "%d. %s\n", i, options[i]);

    option = read_option("\n" LEADING_SPACE "Select option [0 - 6]: ",
            0, num_options);

    printf(LEADING_SPACE "You selected: %s\n", options[option]);
    return option;
}

/************************************************************************
 * base_utils.c                                                         *
 * Basic utility functions required by the program.                     *
 ************************************************************************/

#include <ctype.h>
#include "database.h"

/************************************************************************
 *                      pause()                                         *
 *                                                                      *
 * Puts the prompt msg on screen and waits until the user hits <Enter>  *
 * (←) key or <Ctrl-D> (EOF) combination to continue.                   *
 * Parameters: string prompt                                            *
 * Returns: 1 or 0                                                      *
 ************************************************************************/
int enter(char prompt[])
{
    char junk;

    fputs(prompt, stdout);
    while ((junk = getchar()) != '\n' && junk != EOF)
        ; // do-nothing loop: pause until <Enter> or <Ctrl-D> pressed

    return (junk != EOF) ? EXIT_SUCCESS : EXIT_FAILURE;
}

/************************************************************************
 *                          agreed()                                    *
 *                                                                      *
 * Ask a yes/no question.                                               *
 * Only the stem of the question has to be given.                       *
 * If reply is Y/y returns true, N/n returns false.                     *
 * Parameters: string prompt (stem-only, function will add "y/n")       *
 * NOTE: prompt should not have EXTRA WHITESPACE or QUESTION MARKS!     *
 ************************************************************************/
bool agreed(char prompt[])
{
    char reply, junk[32];

    for (;;)
    {
        fputs(prompt, stdout);
        fputs(" (y/n)? ", stdout);
        // Read-in a single character.
        // 'Y' or 'y' taken as 'yes'; 'N' or 'n' taken as 'no'
        // Any string of characters (e.g. 'Yes', 'yeah', ...) is taken
        // to mean 'y', and same goes for 'n'.
        // '\n' character at the end of the input is read-in from buffer.
        scanf("%c%[^\n]", &reply, junk);
        getchar();

        switch (tolower(reply))
        {
            case 'y':
                return true;
            case 'n':
                return false;

            default:
                fputs(LEAD_WS "ERROR - Enter 'y' or 'n'!\n\n", stderr);
        }
    }
}

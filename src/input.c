/************************************************************************
 * input.c
 * Utility functions related to reading KEYBOARD INPUT from the user.
 ************************************************************************/

#include "database.h"
#include <bsd/string.h>

/**********************************************************************
 *                      read_cd()
 *
 *  Parameters: ptr to a CD structure
 *  Return value: void
 *  Uses: read_str(), readint(), read_float(), yes(), rstrip()
 *
 *  This function reads in data from the keyboard, and stores them in
 *  fields of the CD structure pointed to by ptr.
 *  Fields of CD structure:
 *      - CD title (string)
 *      - Artist (string)
 *      - Number of tracks (int)
 *      - Album/Single? (char)
 *      - Price (float)
 * Validity of CD ptr is assumed, and NOT verified.
 * Title and artist fields, are both ptrs to strings in dynamic memory.
 * REMEMBER to free this memory before CD or ptr to CD is destroyed, or 
 * goes out of scope.
 **********************************************************************/
void read_cd(cd_t *const cd_ptr)
{
    fputs(LEAD_WS "TITLE of the CD? ", stdout);
    fgets(cd_ptr->title, sizeof cd_ptr->title, stdin);
    rstrip(cd_ptr->title);

    fputs(LEAD_WS "Name of the ARTIST? ", stdout);
    fgets(cd_ptr->artist, sizeof cd_ptr->artist, stdin);
    rstrip(cd_ptr->artist);

    cd_ptr->tracks = readint(LEAD_WS "Number of TRACKS? ");
    cd_ptr->album  = agreed(LEAD_WS "Is it an ALBUM");
    cd_ptr->price  = read_float(LEAD_WS "PRICE of CD? $ ");
}



/************************************************************************
 *                      read_int()                                      *
 *                                                                      *
 *   Parameters: string (array of chars)                                *
 *   Return value: int                                                  *
 *                                                                      *
 *   This is a utility function, that prints given string (prompt) on   *
 *   the screen, and reads in and returns an integer. Uses scanf(). So  *
 *   this crashes for non numeric input. Terminal newline char, however,*
 *   is cleared from standard input stream.                             *
 ************************************************************************/
int read_int(char prompt[])
{
    int x;

    fputs(prompt, stdout);
    scanf("%i", &x);                // read int, scavenge extra chars
    getchar();                      // scavenge '\n'
    return x;
}

/************************************************************************
 *                      readint()                                       *
 *                                                                      *
 * This is a utility function, that prints given string (prompt) on the *
 * screen, and reads in and returns an integer.                         *
 *   Parameters: string (array of chars)                                *
 *   Return value: int                                                  *
 * When a floating point value is entered integer value that comes      *
 * before the decimal point is returned. Non-numeric input makes the    *
 * function exit with ERROR_CODE=1                                      *
 ************************************************************************/
int readint(char *prompt)
{
    int d;
    char buf[BUFSIZ];

    fputs(prompt, stdout);
    fgets(buf, sizeof buf, stdin);

    // sscanf returns number of successful matches with template string.
    // If all went well, it must be 1.
    if ((sscanf(buf, "%d\n", &d)) != 1)
    {
        fputs("Not an number\n", stderr);
        exit(EXIT_FAILURE);
    }

    return d;
}
/************************************************************************
 *                      read_float()                                    *
 *                                                                      *
 *   Parameters: string (array of chars)                                *
 *   Return value: float                                                *
 *   This is a utility function, that prints given string (prompt) on   *
 *   the screen, and reads in and returns a float. Uses scanf(). So     *
 *   this crashes for non numeric input. Terminal newline char, however,*
 *   is cleared from standard input stream.                             *
 ************************************************************************/
float read_float(char prompt[])
{
    float x;

    fputs(prompt, stdout);
    scanf("%f", &x);                // read float, scavenge extra chars
    getchar();                      // scavenge '\n'
    return x;
}

/************************************************************************
 *                      read_char()                                     *
 *                                                                      *
 *   Parameters: string (array of chars)                                *
 *   Return value: char                                                 *
 *                                                                      *
 *   This is a utility function, that prints given string (prompt) on   *
 *   the screen, and reads in and returns a char. Uses scanf().         *
 *   If a string of chars is entered, only first char is read and retu- *
 *   -rned rest of the chars (upto 30 chars including the newline at    *
 *   the end of input) are discarded and cleared from standard input    *
 *   stream.                                                            *
 ************************************************************************/
char read_char(char prompt[])
{
    char s[32];

    fputs(prompt, stdout);
    fgets(s, 32, stdin);
    return s[0];
}
/************************************************************************
 *                      read_str()                                      *
 *                                                                      *
 * Read into and get a dynamically allocated string.                    *
 *                                                                      *
 * Parameters: string (array of chars)                                  *
 * Return value: Success: ptr to char (in dynamic memory)               *
 *               Failure: NULL                                          *
 *                                                                      *
 * NOTE: BUFSIZ defined in "stdio.h" [default: 8192 bytes]              *
 * [This BUFSIZ is too much. I'm going to re-define it smaller in the   *
 * project header file.]                                                *
 *                                                                      *
 * This is a utility function, that prints given string (prompt) on the *
 * screen and reads in a string of BUFSIZ bytes from standard input and *
 * returns a ptr, to a copy of that string in dynamic memory.           *
 * Function returns NULL, if dynamic memory allocation failed.          *
 *                                                                      *
 * CAUTION: CALLER IS RESPONSIBLE FOR DEALLOCATING RESERVED DYNAMIC     *
 * MEMORY AFTER USING THE STRING.                                       *
 * This function uses strdup() function, which is not compatible with   *
 * C99 standard library.                                                *
 ************************************************************************/

char *read_str(char prompt[])
{
    char buffer[BUFSIZ];

    fputs(prompt, stdout);
    // first read string to a buffer in stack memory
    fgets(buffer, sizeof buffer, stdin);

    return strdup(rstrip(buffer));
}

/************************************************************************
 *                      read_option()                                   *
 *                                                                      *
 * Reads in a NUMERICAL option from user in a given range (from min to  *
 * max) and return it. If user enters an option value outside the range *
 * prompt until a value within the valid range is given.                *
 *                                                                      *
 * Parameters: NUL-terminated string prompt                             *
 *             minimum & maximum legal values for option (ints)         *
 * Returns: Option number (int)                                         *
 ************************************************************************/
int read_option(char * prompt, int min, int max)
{
    int option;

    option = readint(prompt);
    while (option < min || option > max)
    {
        fprintf(stderr, 
                "Enter a value between %d and %d (inclusive)\n", 
                min, max);
        option = readint(prompt);
    }
    return option;
}

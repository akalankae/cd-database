/************************************************************************
 * output.c                                                             *
 * Utility functions related to writing to SCREEN.                      *
 ************************************************************************/
#include "database.h"

#define  DISPLAY_WDTH   32      /* Width of output fields               */

/************************************************************************
 *                      print_cd()                                      *
 *                                                                      *
 * Reads data at the end of CD ptr and prints them out to stdout.       *
 * Parameters: ptr to CD                                                *
 * Return value: NONE                                                   *
 * NOTE: Does not check for validity of CD ptr. Assumes that there is a *
 * CD structure at the end of the ptr.                                  *
 ************************************************************************/

void print_cd(cd_t * const cd_ptr)
{
    puts(LEAD_WS "\n================================");
    center_text(cd_ptr->title, DISPLAY_WDTH);
    printf("\n" LEAD_WS "* %-8s: %s\n", "Artist", cd_ptr->artist);
    printf(LEAD_WS "* %-8s: %i\n", "Tracks", cd_ptr->tracks);
    printf(LEAD_WS "* %s\n", (cd_ptr->album) ? "Album" : "Single");
    printf(LEAD_WS "* %-8s: $%.2f\n", "Price", cd_ptr->price);
    puts(LEAD_WS "\n================================");
}


/************************************************************************
 *                  print_cd_titles()                                   *
 *                                                                      *
 * Print the titles of CDs in the given open file stream.               *
 * Parameters: ptr to FILE (opened for reading)                         *
 * Returns: Number of CDs read from file on success; -1 on failure      *
 ************************************************************************/

int print_cd_titles(FILE *record)
{
    cd_t *cdptr;
    int num_cds = 0;

    if (record == NULL)
    {
        perror("Empty file");
        return -1;
    }

    while (fread(cdptr, sizeof *cdptr, 1, record) == 1)
    {
        puts(cdptr->title);
        num_cds++;
    }

    return num_cds;
}

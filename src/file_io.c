/************************************************************************
 * file_io.c                                                            *
 * Utility functions related to reading from and writing to files.      *
 ************************************************************************/
#include <dirent.h>
#include <unistd.h>
#include "database.h"

/************************************************************************
 *                  read_cd_from_file()                                 *
 *                                                                      *
 * Reads a CD size block of data from a file into a CD.                 *
 * Parameters: ptr to CD, ptr to file                                   *
 * Returns   : int (number of CDs read from file)                       *
 *             IF successful :- returns 1                               *
 *             IF failed :- returns 0                                   *
 * File must be readable in binary mode. If function fails for some     *
 * reason, no reading will be done and 0 is returned.                   *
 ************************************************************************/
int read_cd_from_file(cd_t * const cd, FILE * restrict rec)
{
    int ncds = 0;           // Number of CDs read from the file

    if (cd != NULL && rec != NULL)
        ncds = fread(cd, sizeof *cd, 1, rec);

    return ncds;
}

/************************************************************************
 *                  write_cd_to_file()                                  *
 *                                                                      *
 * Writes data in CD into a file.                                       *
 * Parameters: ptr to CD, ptr to file                                   *
 * Returns   : int (number of CDs written to file)                      *
 *             IF successful :- returns 1                               *
 *             IF failed :- returns 0                                   *
 * File must be writable in binary mode. If function fails for some     *
 * reason, no writing will be done and 0 is returned.                   *
 ************************************************************************/
int write_cd_to_file(cd_t * restrict cd, FILE * restrict rec)
{
    int ncds;   // Number of CDs written to the file

    if (cd != NULL && rec != NULL)
        ncds = fwrite(cd, sizeof *cd, 1, rec);

    return ncds;
}

/************************************************************************
 *                      copy_cd()                                       *
 *                                                                      *
 * Copies a CD sized block of data from one file to another file, using *
 * given ptr to CD structure.                                           *
 * NOTE: Function just starts reading from current file position in     *
 * read file, to current file position in written file. Both of these   *
 * actions move the cursor position of respective files CD size amount  *
 * of bytes.                                                            *
 * Parameters: ptr to CD,                                               *
 *              ptr to file (binary/read),                              *
 *              ptr to file (binary/write)                              *
 * Returns: int (0 on success, 1 on failure)                            *
 ************************************************************************/
int copy_cd(cd_t *cd, FILE *from, FILE *to)
{
    return (cd != NULL 
            && read_cd_from_file(cd, from) == 1
            && write_cd_to_file(cd, to) == 1) ?  

        EXIT_SUCCESS : EXIT_FAILURE;
}

/************************************************************************
 *                  read_nth_cd_from_file()                             *
 *                                                                      *
 * Read the Nth CD from a file.                                         *
 * Parameters: ptr to CD,                                               *
 *              ptr to file (binary/read),                              *
 *              int (n: number of the CD to read)                       *
 * Returns: int (0 on success, 1 on failure)                            *
 ************************************************************************/
int read_nth_cd_from_file(cd_t *cd, FILE *file, int n)
{
    if (cd == NULL)
        return (EXIT_FAILURE);

    if (fseek(file, SEEK_SET, (n - 1) * sizeof (cd_t)) != 0)
        return (EXIT_FAILURE);

    return !read_cd_from_file(cd, file);
}

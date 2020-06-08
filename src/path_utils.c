/************************************************************************
 * path_utils.c                                                         *
 * file/path related utility functions.                                 *
 ************************************************************************/
#include "database.h"

/************************************************************************
 *                      record_exists()                                 *
 *                                                                      *
 * Predicate, determines whether the given path exists.                 *
 * Parameter: NUL-terminated string (file path)                         *
 * Return value: true/false                                             *
 * This function would first determine whether the given path is an     *
 * absolute path or a relative path, then if there is a file there.     *
 ************************************************************************/

bool record_exists(const char * const record_path)
{
    char *abspath;
    bool exists;

    abspath = realpath(record_path, NULL);
    exists = (!(abspath == NULL));
    free(abspath);

    return exists;
}

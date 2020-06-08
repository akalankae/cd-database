#include "database.h"
#include <ctype.h>

/************************************************************************
 *                      rstrip()                                        *
 *                                                                      *
 * Parameter: ptr to NUL-terminated target string                       *
 * Returns  : ptr to NUL-terminated target string                       *
 *                                                                      *
 * Strips off trailing whitespace character(s) from a string.           *
 * Useful for stripping strings read-in from keyboard using fgets().    *
 ************************************************************************/

char * const rstrip(char * const str)
{
    int length = strlen(str);
    
    // traverse string from the end to start, and replace all encountered 
    // whitespace characters, until first non-whitespace character.
    while (length > 0 && isspace(str[--length]))
    {
        str[length] = '\0';
    }

    return str;
}

/************************************************************************
 *                      center_text()                                   *
 *                                                                      *
 * Center given text, in N field length.                                *
 * Parameters: ptr to NUL-terminated string, field length (int)         *
 * Return value: NONE                                                   *
 ************************************************************************/

void center_text(const char * const text, int field_length)
{
    int padding_length = (field_length - strlen(text)) / 2;
    printf("%*s%s%*s\n", padding_length, "", text, padding_length, "");
}

/************************************************************************
 *                          lower()                                     *
 *                                                                      *
 * Parameters: ptr to a string                                          *
 * Return value: void                                                   *
 *                                                                      *
 * This function TRANSFORMS all uppercase chars in string to lowercase. *
 * String is assumed to be a valid NUL-terminated C string.             *
 * CAUTION: Characters are not tested to see if they are alphanumerical *
 * Pre-ISO compilers may not return original char unchanged in case of  *
 * non-alphanumerical input; therefore this may fail.
 ************************************************************************/

char * lower(char * s)
{
    for (char *p = s; *p != '\0'; p++)
        *p = tolower(*p);

    return s;
}

/************************************************************************
 *                          upper()                                     *
 *                                                                      *
 * Parameters: ptr to a string                                          *
 * Return value: void                                                   *
 *                                                                      *
 * This function TRANSFORMS all lowercase chars in string to uppercase. *
 * String is assumed to be a valid NUL-terminated C string.             *
 * CAUTION: Characters are not tested to see if they are alphanumerical *
 * Pre-ISO compilers may not return original char unchanged in case of  *
 * non-alphanumerical input; therefore this may fail.
 ************************************************************************/

char * upper(char * s)
{
    for (char *p = s; *p != '\0'; p++)
        *p = toupper(*p);

    return s;
}
/************************************************************************
 *                          title()                                     *
 *                                                                      *
 * Parameters: ptr to a string                                          *
 * Return value: void                                                   *
 *                                                                      *
 * This function TRANSFORMS all given string to titlecase. i.e. First   *
 * letter of all the words are capitalized.                             *
 ************************************************************************/

char * title(char *str)
{
    bool word_boundary = true;      /* First char is at a word boundary */

    // Keep track of current letter. If it is a space char, we are at a 
    // WORD BOUNDARY, so the next letter needs to be capitalized.
    // All the other letters need to be turned into lowercase.
    for (char *p = str; *p != '\0'; p++)
    {
        *p = (word_boundary) ? toupper(*p) : tolower(*p);
        word_boundary = isspace(*p);
    }
    return str;
}

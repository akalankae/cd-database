#include "database.h"
#include <dirent.h>
#include <unistd.h>

/************************************************************************
 *                      view_record.c                                   *
 *                                                                      *
 * View all CD entries in any given record.                             *
 ************************************************************************/

// 1. get the name of curr working dir
// 2. enumerate and display names of all records
// 3. request for a name OR number
// 4. verify validity of user input (aka. name or number)
// 5. go through and display all entries in record OR until user wants to
//    exit.
//
void view_record(void)
{
    int i = 0;
    int num_records;        // number of records found in dir
    int rec_num;            // user entered record number
    char *cwd;              // ptr to PWD, (NUL terminated str)
    DIR *dptr;              // directory stream ptr
    struct dirent *entry;
    FILE *fptr;
    cd_t cd;

    cwd = getcwd(NULL, 0);
    if (cwd != NULL)
    {
        dptr = opendir(cwd);
        puts("\nRecords found:");
        while ((entry = readdir(dptr)) != NULL)
            printf("(%2d) %s\n", ++i, entry->d_name);
        num_records = i;
        for (;;)
        {
            rec_num = readint("What's the number of the record you need? ");
            if (rec_num > 0 && rec_num <= num_records)
                break;
            fprintf(stderr, "Invalid record number: %d [Enter 1-%d]\n",
                    rec_num, num_records);
        }

        rewinddir(dptr);
        for (i = 0; i < rec_num; i++)
            entry = readdir(dptr);

        fptr = fopen(entry->d_name, "rb");
        if (fptr != NULL)
            while (fread(&cd, sizeof cd, 1, fptr) == 1)
                print_cd(&cd);
        else
        {
            perror("Couldn't open record");
            exit(1);
        }
    }
    else
    {
        perror("Couldn't get the name of current working directory.");
        exit(2);
    }
}

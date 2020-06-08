#include <dirent.h>
#include <unistd.h>
#include "database.h"

/************************************************************************
 *                      create_record()                                 *
 *                                                                      *
 * Create a new record of CDs.                                          *
 * Prompt for a name for new record.                                    *
 * Check whether record with supplied name, does not already exist.     *
 * Get the number of CDs there is going to be in the record.            *
 * Read CD entries, from keyboard and write them to a file.             *
 ************************************************************************/
void create_record(void)
{
    int count = 0;      // Number of CDs user wants to enter
    int num_cds;        // Index of current CD
    char *record_name;  // File name to save record as
    static cd_t cd;     // struct CD
    FILE *rec_ptr;      // Ptr to record

    record_name = read_str("Name for record: ");
    // It must not already exist in target directory.
    while (record_exists(record_name))
    {
        fprintf(stderr, 
                "'%s' is not valid. Please re-enter name.\n", record_name);
        free(record_name);
        record_name = read_str("Name for record: ");
    }
    
    // Open file for writing the record, in binary mode.
    rec_ptr = fopen(record_name, "wb");

    // No longer need record_name.
    free(record_name);

    if (rec_ptr == NULL)
    {
        perror("Couldn't open file for writing");
        exit(1);
    }

    // How many CDs are there going to be in the record?
    num_cds = readint("How many CDs do you want to enter? ");

    while (count < num_cds) 
    { 
        printf(LEAD_WS "\nDetails of CD%-3d...\n\n", count + 1); 

        read_cd(&cd);                   // Read next CD
        write_cd_to_file(&cd, rec_ptr); // Write CD to file staightaway
        count += 1;                     // Increment CD count

        // Prompt for next CD  after every round EXCEPT the last.
        if ((count < num_cds) && !agreed("\nReady to enter next CD?"))
            break;
    }
    num_cds = count;          /* num_cds = number of CDs entered    */
    fclose(rec_ptr);

}

/*
 * database.h
 * Header file for Course Project.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define bufsize 128             /* re-define stdio.h defined constant   */
#define LEAD_WS "  "            /* Leading whitespace to display        */
#define MAX_TITLE_LENGTH 50     /* maximum length of title + '\0'       */
#define MAX_ARTIST_LENGTH 50    /* maximum length of artist + '\0'      */
#define NOT_IMPLEMENTED not_implemented();

typedef struct cd_type {
    char    title[MAX_TITLE_LENGTH];
    char    artist[MAX_ARTIST_LENGTH];
    int     tracks;
    bool    album;
    float   price;
} cd_t;


/* Set of functions called directly by main program.                    */
int get_option(void);
void create_record(void);
void view_record(void);
void view_entry(void);
void append_record(void);
void delete_record(void);
void save_record_as(void);

/* input.c: Input related functions                                     */
int read_int(char p[]);
int readint(char * prompt);
char read_char(char p[]);
float read_float(char p[]);
char *read_str(char prompt[]);
void read_cd(cd_t * const cd_ptr);
int read_option(char * prompt, int min, int max);

/* output.c: Output related functions                                   */
void print_cd(cd_t * const cd_ptr);
int print_cd_titles(FILE *record);

/* base_utils.c: Basic utility functions                                */
int enter(char prompt[]);
bool agreed(char prompt[]);

/* str_utils.c: String transformation functions                         */
char * lower(char *str);
char * upper(char *str);
char * title(char *str);
char * const rstrip(char * const str);
void center_text(const char * const text, int field_length);

/* file_io.c: File I/O related functions for CDs                        */
int read_cd_from_file(cd_t * const cd, FILE * restrict rec);
int write_cd_to_file(cd_t * restrict cd, FILE * restrict rec);
int read_nth_cd_from_file(cd_t *cd, FILE *file, int n);
int copy_cd(cd_t *cd, FILE *from, FILE *to);

/* path_utils.c: File/path related utility functions                    */
bool record_exists(const char * const record_path);

/* Placeholder for not implemented functions                            */
void not_implemented(void);

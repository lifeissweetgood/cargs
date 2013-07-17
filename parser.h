#define ERR_IF(x) if(x) { \
    rc2 = __LINE__; \
    printf("Error (%s: %d)! Exiting\n", \
           __FUNCTION__, rc2); exit(-1); }

typedef struct ArgsList_def {
    int l;     // Logging, can only be 0 or 1
    int p;      // Port
    char *d;    // Directory

    /* Will deal with these later */
    //char **g;   // List of strings
    //int **n;    // List of integers
} ArgsList;

int argslist_parse(char *schema, ArgsList **argslist,
                   char **stdinArgs, int numArgs);
void argslist_print(ArgsList *argslist);
void argslist_free(ArgsList *argslist);

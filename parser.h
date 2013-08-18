#define ERR_IF(x) if(x) { \
    rc2 = __LINE__; \
    printf("Error (%s: %d)! Exiting\n", \
           __FUNCTION__, rc2); exit(-1); }

typedef struct SCHEMA_ARGS {
    int l;          // Logging, can only be 0 or 1
    int p;          // Port
    char *d;        // Directory

    /* TODO: enhance program to make these lists dynamic */
    char *s[10];    // List of strings
    char g[10];     // List of chars
    int n[10];      // List of ints
} ArgsList;

int argslist_parse(ArgsList **argslist, char **stdinArgs, int numArgs);
void argslist_print(ArgsList *argslist);
void argslist_free(ArgsList *argslist);

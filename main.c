#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

int main(int argc, char **argv)
{
    int rc = 0;
    char *schema = "l p# d* g** n##";
    ArgsList *args = NULL;

    printf("Args = %s, # of Args = %d\n", argv[1], argc);
    
    /* Call parser function that uses schema to assign values to args. */
    rc = argslist_parse(schema, &args, argv, argc);

    argslist_print(args);

    argslist_free(args);

    return rc;
}

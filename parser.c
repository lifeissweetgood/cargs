#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

int argslist_parse(char *schema, ArgsList **argslist,
                   char **stdinArgs, int numArgs)
{
    int i, rc, rc2 = 0;
    ArgsList *tmp_argslist = NULL;
    
    ERR_IF(*argslist != NULL);
    ERR_IF(argslist == NULL);
    
    printf("Hey, world! %s\n", stdinArgs[1]);

    // Initialize argslist struct by allocating space and assgning values.

    tmp_argslist = malloc(sizeof(ArgsList));
    ERR_IF( !tmp_argslist );

    tmp_argslist->l = 0;    // Initialize this to false as default.

    for(i=0; i < numArgs; i++)
    {
        char *currArg = stdinArgs[i];
        if( strcmp(currArg, "-l") == 0 )
        {
            tmp_argslist->l = 1;
            printf("Tmp_args->l = %d\n", tmp_argslist->l);
        }
        else if( strcmp(currArg, "-p") == 0 )
        {
            printf("stdinArgs[%d] = %s\n", i+1, stdinArgs[i+1]);
            i++;
            tmp_argslist->p = atoi(stdinArgs[i]);
            printf("Tmp_args->p = %d\n", tmp_argslist->p);
        }
        else if( strcmp(currArg, "-d") == 0 )
        {
            printf("stdinArgs[%d] = %s\n", i+1, stdinArgs[i+1]);
            i++;
            tmp_argslist->d = strdup(stdinArgs[i]);
            printf("Tmp_args->d = %s\n", tmp_argslist->d);
        }
        continue;
    }

    // Pass back
    *argslist = tmp_argslist;

    return rc;
}

void argslist_print(ArgsList *argslist)
{
    int rc, rc2 = 0;
    char *logBool = NULL;

    ERR_IF(argslist == NULL);

    logBool = (argslist->l == 1) ? "true":"false";
    printf("Logging: %s\n", logBool);
    printf("Port: %d\n", argslist->p);
    printf("Directory: %s\n", argslist->d);

    // Print list of strings and list of ints
}

void argslist_free(ArgsList *argslist)
{
    // Free all allocated space
    free(argslist->d);
    argslist->d = NULL;
    free(argslist);
}


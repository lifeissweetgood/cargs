#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

int argslist_parse(ArgsList **argslist, char **stdinArgs, int numArgs)
{
    int i = 0, rc = 0, rc2 = 0;
    ArgsList *tmp_argslist = NULL;

    ERR_IF(*argslist != NULL);
    ERR_IF(argslist == NULL);
    
    // Allocate space and assign values to argslist.
    tmp_argslist = malloc(sizeof(ArgsList));
    ERR_IF( !tmp_argslist );
    
    // Initialize this to false as default.
    tmp_argslist->l = 0;
    tmp_argslist->p = -1;

    // Assign values according to schema
    for(i=0; i < numArgs; i++)
    {
        char *currArg = stdinArgs[i];
        if( strcmp(currArg, "-l") == 0 )
        {
            if(tmp_argslist->l == 0)
                tmp_argslist->l = 1;
        }
        else if( strcmp(currArg, "-p") == 0 )
        {
            if( tmp_argslist->p != -1 )
            {
                printf("ERROR: Already set port!\n");
                rc = -1;
                break;
            }
            i++;
            tmp_argslist->p = atoi(stdinArgs[i]);
        }
        else if( strcmp(currArg, "-d") == 0 )
        {
            if(tmp_argslist->d != NULL)
            {
                printf("ERROR: Already set directory!\n");
                rc = -1;
                break;
            }
            i++;
            tmp_argslist->d = strdup(stdinArgs[i]);
        }
        continue;
    }

    // Error handling
    if( rc != 0 )
    {
        argslist_free(tmp_argslist);
    }
    else
    {
        if(tmp_argslist->d == NULL)
            tmp_argslist->d = "Not Given";

        // Pass back
        //  -Don't need to free tmp_argslist explicitly:
        //      freeing argslist will take care of it.
        *argslist = tmp_argslist;
    }

    return rc;
}

void argslist_print(ArgsList *argslist)
{
    int rc = 0, rc2 = 0;
    char *logBool = NULL;

    ERR_IF(argslist == NULL);

    logBool = (argslist->l == 1) ? "true":"false";
    printf("Logging: %s\n", logBool);
    printf("Port: %d\n", argslist->p);
    printf("Directory: %s\n", argslist->d);
    // TODO: Print list of strings and list of ints
}

void argslist_free(ArgsList *argslist)
{
    // Free all allocated space
    if(argslist->d != "Not Given")
        free(argslist->d);
    argslist->d = NULL;
    free(argslist);
}


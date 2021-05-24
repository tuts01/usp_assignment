/********************************************************************
* File:             fileio.c                                        *
* Author:           Tristan S. Tutungis                             *
* Date Created:     21/5/21                                         *
* Last Modified:    24/5/21 15:47                                   *
* Description:      Contains functions for file input and output    *
********************************************************************/

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include "macros.h"

/************************************************************
* FUNCTION: openFile                                        *
* IMPORT:   name (String), mode (String)                    *
* EXPORT:   file (FILE POINTER)                             *
* PURPOSE:  Open the file for reading and check for errors  *
************************************************************/
static int openFile(char* name, int flag)
{
    int fd = open(name, flag);//Open a file descriptor

    //If file could not be read, NULL is returned - output error message
    if(fd == -1) fputs("Error opening file", stderr);

    return fd; //Return the open file stream
}//End open()

/************************************************************************
* FUNCTION: readFile                                                    *
* IMPORT:   fileName (String), count (Integer POINTER)                  *
* EXPORT:                                                               *
* PURPOSE:  Open and read the file, outputting the results in an array  *
************************************************************************/
LinkedList* readFile(char* fileName)
{
    int fd = openFile(fileName, O_RDONLY);
    int ret, i = 0;
    LinkedList* processes = createList();
    Process* process;
    char buf, prev;
    char* line;
    char* token;

    line = (char*)calloc(1, sizeof(char));
    ret = read(fd, &buf, sizeof(char));

    do
    {
        ret = read(fd, &buf, sizeof(char));

        if(buf == '\n' && ret == 0);
        else if(buf == '\n' || ret == 0)
        {
            process = (Process*)malloc(sizeof(Process));
            
            token = strtok(line, " ");

            process.argv[0] = token;

            token = strtok(line, " ");
            process.argc = 0;

            while(token != NULL)
            {
                process.argv[process.argc] = token;
                process.argc++;
                strtok(line, NULL);
            }

            insertLast(processes, process);
            i = 0;
        }
        else
        {
            line = realloc(line, i+2 * sizeof(char));
            line[i] = buf
            line[i+1] = 0;
        }
    }while(ret > 0)

    free(line);

    ret = close(fd);
    return processes;
}



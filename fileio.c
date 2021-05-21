/********************************************************************
* File:             fileio.c                                        *
* Author:           Tristan S. Tutungis                             *
* Date Created:     21/5/21                                         *
* Last Modified:                                                    *
* Description:      Contains functions for file input and output    *
********************************************************************/

#include <fcntl.h>

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
Process* readFile(int* count, char* fileName)
{
    int fd = openFile(fileName, O_RDONLY);
    int ret;
    Process* processes = (Process*)malloc(sizeof(Process));
    
    *count = 0
    do
    {
        processes = realloc(processes, *count+1 * sizeof(Process));

        ret = read(fd, processes[*count]->command;
    }while(ret > 0)

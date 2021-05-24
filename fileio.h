/********************************************************************
* File:             fileio.h                                        *
* Author:           Tristan S. Tutungis                             *
* Date Created:     24/5/21                                         *
* Last Modified:    24/5/21 15:31                                   *
* Description:      Contains functions for file input and output    *
********************************************************************/

#ifndef FILEIO_H
#define FILEIO_H
/************************************************************************
* FUNCTION: readFile                                                    *
* IMPORT:   fileName (String), count (Integer POINTER)                  *
* EXPORT:                                                               *
* PURPOSE:  Open and read the file, outputting the results in an array  *
************************************************************************/
LinkedList* readFile(char* fileName);

#endif

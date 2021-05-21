/****************************************************************
* File:             macros.h                                    *
* Author:           Tristan S. Tutungis                         *
* Date Created:     21/5/21                                     *
* Last Modified:                                                *
* Description:      Structures and macros for Pipesim program   *
****************************************************************/
#ifndef MACROS_H
#define MACROS_H

typedef struct
{
    char[81] command; //Command to be executed
    char* output; //Output of the specified command
} Process;

#endif

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
    int argc; //Number of arguments of the command
    char** argv; //Arguments of the command - args[0] is the program name
} Process;

#endif

/****************************************
* File:             pipesim.c           *
* Author:           Tristan S. Tutungis *
* Date Created:     21/5/21             *
* Last Modified:    21/5/21             *
* Description:      Pipe simulator      *
****************************************/

#include "fileio.c"
#include "linkedlist.h"

/* Main Function */
int main(int argc, char** argv)
{
    int rtn; //Value to return at exit of main()
    char* usage = "Usage: ./pipesim <input_file> [<output_file>]";


    if(argc == 2 || argc == 3)
    {
        
    }
    else
    {
        fprintf(stderr, "Error: Invalid number of arguments.\n%s\n", usage);
        rtn = 1;
    }

    return rtn;
}//End main()

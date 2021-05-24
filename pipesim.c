/****************************************
* File:             pipesim.c           *
* Author:           Tristan S. Tutungis *
* Date Created:     21/5/21             *
* Last Modified:    21/5/21             *
* Description:      Pipe simulator      *
****************************************/

#include "fileio.c"
#include "linkedlist.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* Main Function */
int main(int argc, char** argv)
{
    int rtn; //Value to return at exit of main()
    int ret;
    int original_stdout;
    int outpipe[2];
    int inpipe[2];
    int count;
    char buf;
    char* usage = "Usage: ./pipesim <input_file> [<output_file>]";
    int i;
    Process* curProcess;
    pid_t child_pid;
    LinkedList* processes;

    if(argc == 2 || argc == 3)
    {
        processes = readFile(argv[1]);
        ret = pipe(inpipe);

        original_stdout = dup(1);

        count = processes.count;

        for(i=0; i < count-1; i++)
        {
            curProcess = removeFirst(processes);
            ret = pipe(outpipe);

            child_pid = fork();

            if(child_pid == 0)
            {
                close(outpipe[0]);
                dup2(outpipe[1], 1);
                close(outpipe[1]);

                close(inpipe[1]);
                dup2(inpipe[0], 0);
                close(inpipe[0]);

                ret = execv(curProcess.argv[0], curProcess.argv);
            }
            else if(child_pid > 0)
            {
                close(inpipe[0]);
                close(outpipe[1]);

                wait(NULL);

                close(inpipe[1]);
                ret = pipe(inpipe);

                while(read(outpipe[0], &buf, sizeof(char)) > 0)
                {
                    write(inpipe[1], &buf, sizeof(char));
                }
                
                close(outpipe[0]);
            }
        }

        curProcess = removeFirst(processes);

        if(argc == 2)
        {
            ret = dup2(original_stdout, 1);
            close(original_stdout);
        }
        else if(argc == 3)
        {
            close(original_stdout);
            ret = open(argv[2], O_WRONLY);
            dup2(ret, 1);
            close(ret);
        }
            
        child_pid = fork();

        if(child_pid == 0)
        {
            close(inpipe[1]);
            dup2(inpipe[0], 0);
            close(inpipe[0]);

            ret = execv(curProcess.argv[0], curProcess.argv);
        }
        else
        {
            close(inpipe[0]);
            wait(NULL);
            close(inpipe[1]);
            close(ret);
        }
    }
    else
    {
        fprintf(stderr, "Error: Invalid number of arguments.\n%s\n", usage);
        rtn = 1;
    }

    return rtn;
}//End main()

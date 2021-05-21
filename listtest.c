/****************************************************************************
* File:             listtest.c                                              *
* Author:           Tristan S. Tutungis                                     *
* Date Created:     20/5/21                                                 *
* Last Modified:    20/5/21                                                 *
* Purpose:          Test harness for a generic linked list implementation   *
****************************************************************************/

/* Include Statements */
#include "linkedlist.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Test function type definition */
typedef bool(*Test)(LinkedList* list);

bool testHead(LinkedList* list, char* val)
{
    bool rtn = false;
    
    if(list->head != NULL)
    {
        if(strcmp(list->head->value, val) == 0) rtn = true;
        if(list->head->prev != NULL) rtn = false; //head->prev is not NULL
    }

    return rtn;
}

bool testTail(LinkedList* list, char* val)
{
    bool rtn = false;
    
    if(list->tail != NULL)
    {
        if(strcmp(list->tail->value, val) == 0) rtn = true;
        if(list->tail->next != NULL) rtn = false; //tail->next is not NULL
    }

    return rtn;
}

LinkedList* testCreateList()
{
    LinkedList* list = NULL;

    #ifndef QUIET
    fputs("Test 1 - Create List:\t\t", stdout);
    #endif

    list = createList();
    if(list == NULL)
    {
        puts("Failed to create list!");
    }
    else if(list->head != NULL || list->tail != NULL || list->count != 0)
    {
        freeList(list, &free);
        puts("Failed to create list correctly!");
    }

    return list;
}

bool testInsFirst1(LinkedList* list)
{
    char* str;

    str = (char*)calloc(10, sizeof(char));
    strcpy(str, "InsFirst1");

    #ifndef QUIET
    fputs("Test 2 - Insert First 1:\t", stdout);
    #endif

    insertFirst(list, str);

    return (testHead(list, "InsFirst1") && testTail(list, "InsFirst1") && list->count == 1);
}
    
bool testInsLast1(LinkedList* list)
{
    char* str;

    str = (char*)calloc(10, sizeof(char));
    strcpy(str, "InsLast1");

    #ifndef QUIET
    fputs("Test 3 - Insert Last 1:\t\t", stdout);
    #endif

    insertLast(list, str);

    return (testHead(list, "InsFirst1") && testTail(list, "InsLast1") && list->count == 2);
}

bool testInsFirst2(LinkedList* list)
{
    char* str;

    str = (char*)calloc(10, sizeof(char));
    strcpy(str, "InsFirst2");

    #ifndef QUIET
    fputs("Test 4 - Insert First 2:\t", stdout);
    #endif

    insertFirst(list, str);

    return (testHead(list, "InsFirst2") && testTail(list, "InsLast1") && list->count == 3);
}

bool testInsLast2(LinkedList* list)
{
    char* str;

    str = (char*)calloc(10, sizeof(char));
    strcpy(str, "InsLast2");

    #ifndef QUIET
    fputs("Test 5 - Insert Last 2:\t\t", stdout);
    #endif

    insertLast(list, str);

    return (testHead(list, "InsFirst2") && testTail(list, "InsLast2") && list->count == 4);
}

bool testRmFirst(LinkedList* list)
{
    char* str;
    bool success;

    #ifndef QUIET
    fputs("Test 6 - Remove First:\t\t", stdout);
    #endif

    str = removeFirst(list);

    success = (strcmp(str, "InsFirst2") == 0 && testHead(list, "InsFirst1") && testTail(list, "InsLast2") && list->count == 3);
    free(str);
    
    return success;
}

bool testRmLast(LinkedList* list)
{
    char* str;
    bool success;

    #ifndef QUIET
    fputs("Test 7 - Remove Last:\t\t", stdout);
    #endif

    str = removeLast(list);

    success = (strcmp(str, "InsLast2") == 0 && testHead(list, "InsFirst1") && testTail(list, "InsLast1") && list->count == 2);
    free(str);
    
    return success;
}

bool testInsFirst3(LinkedList* list)
{
    char* str;

    str = (char*)calloc(10, sizeof(char));
    strcpy(str, "InsFirst3");

    #ifndef QUIET
    fputs("Test 8 - Insert First 3:\t", stdout);
    #endif

    insertFirst(list, str);

    return (testHead(list, "InsFirst3") && testTail(list, "InsLast1") && list->count == 3);
}

bool testFreeList(LinkedList* list)
{
    #ifndef QUIET
    fputs("Test 9 - Free Linked List:\t", stdout);
    #endif

    freeList(list, &free);
    return true;
}

/* Main Function */
int main()
{
    int rtn = 0, i = 0, passed = 0;
    bool success = true;

    //Create a container for the tests
    Test tests[8] = {&testInsFirst1, &testInsLast1, &testInsFirst2,
    &testInsLast2, &testRmFirst, &testRmLast, &testInsFirst3, &testFreeList};

    //Create a linked list to be tested
    LinkedList* list = NULL;

    list = testCreateList();

    if(list == NULL)
    {
        rtn = 1;
        #ifndef QUIET
        puts("Failed to create list!\n");
        #endif

    }
    else
    {
        #ifndef QUIET
        puts("Success");
        #endif

        while(i < 8 && success)
        {
            success = (tests[i])(list);

            if(success)
            {
                #ifndef QUIET
                puts("Success");
                #endif

                passed++;
            }
            else
            {
                #ifndef QUIET
                puts("Failure");
                #endif

                rtn = i+2;
            }
            i++;
        }
    }

    #ifndef QUIET
    printf("\nNumber of tests passed:\t%d\n", i+1);
    #endif


    return rtn;
}

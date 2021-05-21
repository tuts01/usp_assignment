/****************************************************************************
* File:             linkedlist.c                                            *
* Author:           Tristan S. Tutungis                                     *
* Date Created:     14/5/21                                                 *
* Last Modified:    16/5/21 13:17                                           *
* Purpose:          Linked list implementation in C - contains functions    *
*                   for creating and destroying the list, in addition to    *
*                   inserting, viewing and removing nodes from the list     *
****************************************************************************/

/* Include Statements */
#include "linkedlist.h"
#include <stdlib.h>

/********************************************
* FUNCTION: createList                      *
* IMPORT:   none                            *
* EXPORT:   list (LinkedList POINTER)       *
* PURPOSE:  Create a new empty linked list  *
********************************************/
LinkedList* createList()
{
    //Allocate memory for the list
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));

    //Set head and tail to NULL and count to zero
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;

    return list;
}//End createList()

/****************************************************
* FUNCTION: insertFirst                             *
* IMPORT:   list (LinkedList POINTER)               *
*           data (VOID POINTER)                     *
* EXPORT:   none                                    *
* PURPOSE:  Add a new node at the start of the list *
****************************************************/
void insertFirst(LinkedList* list, void* value)
{
    //Allocate memory for a new node
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));

    //Set value of the node
    node->value = value;
    node->prev = NULL; //Set prev to NULL since theres no node before it

    //If the list is empty make the tail point to the new node
    if(list->head == NULL) list->tail = node;
    else //Otherwise...
    {
        node->next = list->head; //Make next point to the old head
        list->head->prev = node; //Set the prev of the old head to the new head
    }//End if

    list->head = node; //Set the head to the new node
    list->count++;
}//End insertFirst()

/****************************************************
* FUNCTION: insertLast                              *
* IMPORT:   list (LinkedList POINTER)               *
*           data (VOID POINTER)                     *
* EXPORT:   none                                    *
* PURPOSE:  Add a new node at the end of the list   *
****************************************************/
void insertLast(LinkedList* list, void* value)
{
    //Allocate memory for a new node
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));

    //Set value of the node
    node->value = value;
    node->next = NULL; //Set next to NULL since theres no node after it

    //If the list is empty make the head point to the new node
    if(list->tail == NULL) list->head = node;
    else //Otherwise...
    {
        node->prev = list->tail; //Make prev point to the old tail
        list->tail->next = node; //Set the next of the old tail to the new tail
    }//End if

    list->tail = node; //Set the tail to the new node
    list->count++;
}//End insertLast()

/************************************************
* FUNCTION: removeFirst                         *
* IMPORT:   list (LinkedList POINTER)           *
* EXPORT:   (VOID POINTER)                      *
* PURPOSE:  Remove the first node of the list   *
************************************************/
void* removeFirst(LinkedList* list)
{
    void* ptr = list->head->value;

    if(list->head->next == NULL) //If the last node is being removed
    {
        //Set head and tail to NULL
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->head = list->head->next;
        free(list->head->prev);
        list->head->prev = NULL;
    }

    list->count--;

    return ptr;
}

/************************************************
* FUNCTION: removeLast                          *
* IMPORT:   list (LinkedList POINTER)           *
* EXPORT:   (VOID POINTER)                      *
* PURPOSE:  Remove the last node of the list    *
************************************************/
void* removeLast(LinkedList* list)
{
    void* ptr = list->tail->value;

    if(list->tail->prev == NULL)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->tail = list->tail->prev;
        free(list->tail->next);
        list->tail->next = NULL;
    }

    list->count--;

    return ptr;
}

/****************************************
* FUNCTION: freeList                    *
* IMPORT:   list (LinkedList POINTER)   *
*           func (void(void*) POINTER)  *
* EXPORT:   none                        *
* PURPOSE:  Free the entire list        *
****************************************/
void freeList(LinkedList* list, void(*func)(void*))
{
    freeNode(list->head, func);
    free(list);
}

/****************************************
* FUNCTION: freeNode                    *
* IMPORT:   node (ListNode POINTER)     *
*           func (void(void*) POINTER)  *
* EXPORT:   none                        *
* PURPOSE:  Free a node in the list     *
****************************************/
void freeNode(ListNode* node, void(*func)(void*))
{
    if(node != NULL)
    {
        freeNode(node->next, func);
        func(node->value);
        free(node);
    }
}

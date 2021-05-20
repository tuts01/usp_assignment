/************************************************************************
* File:             linkedlist.h                                        *
* Author:           Tristan S. Tutungis                                 *
* Date Created:     14/5/21                                             *
* Last Modified:    16/5/21 10:36                                       *
* Purpose:          Header for linked list implementation - contains    *
*                   structures for the list and its nodes, as well as   *
*                   function declarations for manipulating the list     *
************************************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/****************************************
* Structure:    ListNode                *
* Fields:       value (VOID POINTER)    *
*               next (ListNode POINTER) *
*               prev (ListNode POINTER) *
* Purpose:      Structure for list node *
****************************************/
typedef struct ListNode {
    void* value; //Pointer to information to store in the list
    struct ListNode* next; //Points to next node
    struct ListNode* prev; //Points to previous node
} ListNode;

/****************************************
* Structure:    LinkedList              *
* Fields:       count (Integer)         *
*               head (ListNode POINTER) *
*               tail (ListNode POINTER) *
* Purpose:      Structure for list      *
****************************************/
typedef struct LinkedList {
    int count; //Number of nodes in the list
    ListNode* head; //Points to first node in the list
    ListNode* tail; //Points to last node in the list
} LinkedList;

/********************************************
* FUNCTION: createList                      *
* IMPORT:   none                            *
* EXPORT:   list (LinkedList POINTER)       *
* PURPOSE:  Create a new empty linked list  *
********************************************/
LinkedList* createList();

/****************************************************
* FUNCTION: insertFirst                             *
* IMPORT:   list (LinkedList POINTER)               *
*           value (VOID POINTER)                    *
* EXPORT:   none                                    *
* PURPOSE:  Add a new node at the start of the list *
****************************************************/
void insertFirst(LinkedList* list, void* value);

/****************************************************
* FUNCTION: insertLast                              *
* IMPORT:   list (LinkedList POINTER)               *
*           value (VOID POINTER)                    *
* EXPORT:   none                                    *
* PURPOSE:  Add a new node at the end of the list   *
****************************************************/
void insertLast(LinkedList* list, void* value);

/************************************************
* FUNCTION: removeFirst                         *
* IMPORT:   list (LinkedList POINTER)           *
* EXPORT:   (VOID POINTER)                      *
* PURPOSE:  Remove the first node of the list   *
************************************************/
void* removeFirst(LinkedList* list);

/************************************************
* FUNCTION: removeLast                          *
* IMPORT:   list (LinkedList POINTER)           *
* EXPORT:   (VOID POINTER)                      *
* PURPOSE:  Remove the last node of the list    *
************************************************/
void* removeLast(LinkedList* list);

/****************************************
* FUNCTION: freeList                    *
* IMPORT:   list (LinkedList POINTER)   *
*           func (void(void*) POINTER)  *
* EXPORT:   none                        *
* PURPOSE:  Free the entire list        *
****************************************/
void freeList(LinkedList* list, void(*func)(void*));

/****************************************
* FUNCTION: freeNode                    *
* IMPORT:   node (ListNode POINTER)     *
*           func (void(void*) POINTER)  *
* EXPORT:   none                        *
* PURPOSE:  Free a node in the list     *
****************************************/
void freeNode(ListNode* node, void(*func)(void*));

#endif

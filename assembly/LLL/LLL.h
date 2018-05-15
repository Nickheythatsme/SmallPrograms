#include <stdlib.h>
#include <stdio.h>

#ifndef LLL_
#define LLL

/* 
 * Defining our struct
 */
struct node
{
    int data;
    struct node *next;
};

/*
 * These functions insert/remove.
 * Return -1 if failure, anything else if success
 */
int insert(struct node **head, int new_data);
int _insert(struct node *head, int new_data);
int remove_LLL(struct node **head, int to_remove);
int _remove_LLL(struct node *head, int to_remove);


#endif

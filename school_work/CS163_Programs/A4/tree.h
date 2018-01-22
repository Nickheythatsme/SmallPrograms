/* Nicholas Grout
 * Professor: Karla Fant
 * Assignment 4
 *
 * File name: tree.h
 *
 * Description: This file contains the definition of the tree class, and the
 * node struct the tree uses. It includes the declarations of any functions
 * and object names used by the tree class.
 *
 *
 * INPUT:  Takes in a list of formatted events in a text file. Also takes
 *         the name or keyword of target events from the user.
 * OUTPUT: The program outputs all events in alphabetical order, and the
 *         desired events as indicated by the user.
 *
 *
 */
#include <cctype>
#include <cstring>
#include <ctime>
#include <iostream>
#include "event.h"

#ifndef TREE_
#define TREE_
struct node
{
    node();
    ~node();
    event * data;
    node  * right;
    node  * left;
    //Removes left and right nodes all the way to the leaves of the tree.
    int remove_all();
};

class tree
{
    public:
        tree();
        ~tree();
        //Insert a new event into the BST
        int insert(event & to_insert);
        //Remove all events with this matching name
        int remove_name(char * name);
        //Remove all events with this matching keyword
        int remove_keyword(char * keyword);
        //Retrieve an event with this matching name.
        int retrieve(char * name, event *& to_retrieve);
        //Display all events in BST in sorted order
        int display_all();
        //Return the maximum height of the tree
        int return_height();
    private:
        //Find the in order successor from a starting node's right node. Return
        //0 if there isn't one.
        int in_order_successor(node * start, node *& IOS);
        //Recursively search for corrent location and insert node into tree.
        int insert(node * to_insert, node *& root);
        //Recursively search the tree and find a matching event
        int retrieve(char * name, node * root, event *& to_return);
        //Search for matching event name and call remove_node function
        int remove_name(char * name, node *& root);
        //Search for matching event keyword and call remove_node function
        int remove_keyword(char * keyword, node *& root);
        //Remove a node, accounting for 4 different cases and using the 
        //target node's in order successor.
        int remove_node( node *& root );
        //Recursively go through tree and display events in alphabetical order.
        int display_all( node * root);
        //Recursively go through tree, comparing left height to right height
        //and returing the highest.
        int return_height(node * root);
        //Root of our tree.
        node * root;
};
#endif

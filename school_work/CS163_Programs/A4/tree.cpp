/* Nicholas Grout
 * Professor Karla Fant
 * Assignment 4
 *
 * File name: tree.cpp
 *
 * Description: This file contains the implementation of the tree class 
 * functions. It has functions for inserting data, removing, and retrieving/
 * displaying data.
 */
#include "tree.h"
#include "event.h"


//This calls the tree's recursive insert
int tree::insert(event & to_insert)
{
    //Here we make a new node to hold the event.
    node * new_node = new node;
    new_node -> data = new event;
    if( new_node -> data -> copy( to_insert ) < 0 )
    {
        delete new_node;
        return -1;
    }
    return insert( new_node, root);
}

//This inserts a new event into the tree. A new node is made, then the event
//is copied into that node's event and the new node is added to the tree.
int tree::insert(node * to_insert, node *& root)
{
    //If root is null, we know we're at appending onto the correct leaf or
    //starting a new tree.
    if( !root )
    {
        //This is okay because we've already made a new node in the wrapper
        //function.
        root = to_insert;
        return 1;
    }

    //Determine if this node is to be inserted left or right of here.
    int diff = strcmp(to_insert -> data -> name, root -> data -> name);
    if( diff < 0 )
        return insert( to_insert, root -> right);
    return insert( to_insert, root -> left);
}

//This calls the tree's recursive display all function.
int tree::display_all()
{
    return display_all(root);
}

//Display all events in the tree in alphabetical order. This function does the
//work of traversing the tree recursively, displaying as we go.
int tree::display_all(node * root)
{
    if( !root ) return 0;
    //Call right first
    int count = display_all( root -> right );

    root -> data -> display();
    //Call left after, to display in alphabetical order.
    count += display_all(root -> left);

    return count + 1;
}

//This calls the tree's recursive return_height function.
int tree::return_height()
{
    return return_height(root);
}

//This returns the tallest path in the tree.
int tree::return_height(node * root)
{
    //Used in the book and lab. Complicated but short way to return the height.
    if( !root ) return 0;
    return std::max(return_height(root -> right) + 1, 
                    return_height(root -> left) + 1);
}

//Retrieve an event with this matching name.
int tree::retrieve(char * name, event *& to_retrieve)
{
    if(!name) return -1;
    if( to_retrieve ) delete to_retrieve;
    to_retrieve = new event;
    return retrieve(name, root, to_retrieve);
}

//This recursively search the tree and copy the target event to to_return.
//This eturns 0 if not found.
int tree::retrieve(char * name, node * root, event *& to_return)
{
    if(!root) return 0;
    if( !strcmp(name, root -> data -> name) ) 
    {
        to_return -> copy( *root -> data );
        return 1;
    }
    return retrieve(name, root -> right, to_return) + 
           retrieve(name, root -> left, to_return);
}
//Remove all events with this matching name
int tree::remove_keyword(char * keyword)
{
    if(!keyword) return 0;
    return remove_keyword(keyword, root);
}

//Remove all events with this matching name
int tree::remove_keyword(char * keyword, node *& root)
{
    if( !root ) return 0;
    //Test all the keywords
    for(int i = 0; i < 5 && root -> data -> keyword[i]; ++i)
        if(!strcmp(keyword, root -> data -> keyword[i]))
            return remove_node(root);

    //Continue through the tree
    return remove_keyword(keyword, root -> left) +
           remove_keyword(keyword, root -> right);
}

//Remove all events with this matching name
int tree::remove_name(char * name)
{
    if(!name) return 0;
    return remove_name(name, root);
}

//Remove all events with this matching name
int tree::remove_name(char * name, node *& root)
{
    if( !root ) return 0;
    //Test event name with target name
    if(!strcmp(name, root -> data -> name))
        return remove_node(root);
    //Continue on in case there's more events with that name
    return remove_name(name, root -> left) +
           remove_name(name, root -> right);
}

//Remove a target node. This function uses the in order successor and the
//target node to reshape the tree as necessary.
int tree::remove_node( node *& root )
{
    if(!root) return -1;
    //Case 1: target node is a leaf
    if( !root -> left && !root -> right)
    {
        delete root;
        root = NULL;
        return 1;
    }
    //Case 2: target node is internal node with one child
    if( root -> left && !root -> right )
    {
        node * temp = root -> left;
        delete root;
        root = temp;
        return 1;
    }
    //Case 2: target node is internale node with one child (other side)
    if( root -> right && !root -> left)
    {
        node * temp = root -> right;
        delete root;
        root = temp;
        return 1;
    }
    //Case 3: internal node with 2 children
    else
    {
        node * temp = NULL;
        if(!root -> right -> left)
            temp = root -> right;
        else
            in_order_successor(root -> right, temp);
        delete root;
        root = temp;
        return 1;
    }
}

//Find the in order successor from a starting node. Return 0 if there
//isn't one.
int tree::in_order_successor(node * root, node *& IOS)
{
    if(!root) return 0;
    if( !root -> left ) 
    {
        IOS = root;
        return 1;
    }
    return in_order_successor(root -> left, IOS);
}

node::node()
{
    data = NULL;
    right = left = NULL;
}

node::~node()
{
    delete data;
    right = left = NULL;
}

//Here we traverse all the way to the left and the right, removing all as we 
//return.
int node::remove_all()
{
    if( right )
    {
        right -> remove_all();
        delete right;
        right = NULL;
    }
    if( left )
    {
        left -> remove_all();
        delete left;
        left = NULL;
    }
    return 1;
}

tree::tree()
{
    root = NULL;
}

tree::~tree()
{
    //This calls root's remove all function.
    if( root )
        root -> remove_all();
    delete root;
    root = NULL;
}

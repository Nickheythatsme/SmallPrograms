/* Nicholas Grout
 * Professor: Karla Fant
 * Assignment: 5
 *
 * Filename: vertex_edge.cpp
 */
#include "vertex_edge.h"

int vertex::insert_edge(edge *& to_insert)
{
    if(!to_insert) return -1;
    return insert_edge(to_insert, head);
}


int vertex::insert_edge(edge *& to_insert, edge *& head)
{
    if(!head)
    {
        head = to_insert;
        return 1;
    }
    return insert_edge(to_insert, head -> next);
}

int vertex::copy(vertex * to_copy)
{
    if(!to_copy) return -1;
    if(trail)
        delete [] trail;
    if( to_copy -> trail )
    {
        trail = new char[strlen(to_copy -> trail) + 1];
        strcpy(trail, to_copy -> trail);
    }
    head = to_copy -> head;
    visited = to_copy -> visited;
    return 1;
}

vertex::vertex()
{
    head = NULL;
    trail = NULL;
    visited = false;
}

vertex::~vertex()
{
    if(trail)
    {
        delete [] trail;
        trail = NULL;
    }
    remove_all(head);
}

int vertex::remove_all(edge *& head)
{
    if(!head) return 0;
    remove_all(head -> next);
    delete head;
    head = NULL;
    return 1;
}

int edge::display(void)
{
    if(!trail || !source) return -1;
    cout << "Connected to: " << source -> trail << endl
         << "Length:       " << length << endl
         << "Dog friendly: " << dog_friendly << endl
         << "Walking:      " << walking << endl
         << "Running:      " << running << endl
         << "Biking:       " << biking << endl
         << "Birding:      " << birding << endl;

    return 1;
}

int edge::copy(const edge *& to_copy)
{
    if(!to_copy) return -1;

    if(trail) delete [] trail;
    trail = new char[strlen(to_copy -> trail) + 1];
    strcpy(trail, to_copy -> trail);

    length       = to_copy -> length;
    walking      = to_copy -> walking;
    running      = to_copy -> running;
    biking       = to_copy -> biking;
    birding      = to_copy -> birding;
    dog_friendly = to_copy -> dog_friendly;

    return 1;
}

edge::edge(const edge & to_copy)
{
    if(trail) delete [] trail;

    trail = new char[strlen(to_copy.trail) + 1];
    strcpy(trail, to_copy.trail);

    length = to_copy.length;
    dog_friendly = to_copy.dog_friendly;
    walking = to_copy.walking;
    running = to_copy.running;
    biking = to_copy.biking;
    birding = to_copy.birding;
}

edge::edge()
{
    next = NULL;
    source = NULL;
    length = 0.0;
    dog_friendly = walking = running = biking = birding = false;
}

edge::~edge()
{
    if(trail) 
        delete [] trail;
    trail = NULL;
}


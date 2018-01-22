/* Nicholas Grout
 * Professor: Karla Fant
 * Assignment: 5
 *
 * Filename: graph.cpp
 */
#include "graph.h"

int graph::display_paths(char * start)
{
    int index = 0;
    if(find(start, index) < 0 )
        return -1;
    if(vertex_array[index])
        display_paths(vertex_array[index] -> head, vertex_array[index]);
    return 1;
}

int graph::display_paths(edge * head, vertex * start)
{
    if(!head) return 0;
    head -> display();
    if( head -> source != start )
        display_paths(head -> source -> head, start);
    return display_paths(head -> next, start);
}

int graph::display_connections(char * start)
{
    int index = 0;
    if( find(start, index) < 0 )
        return -1;
    return display_connections(vertex_array[index] -> head);
}

int graph::display_connections(edge * head)
{
    if(!head) return 0;
    head -> display();
    return display_connections(head -> next);
}

int graph::return_names(char **& array)
{
    if(array) delete [] array;
    array = new char *[vertex_size];
    for(int i = 0; i < vertex_size; ++i)
    {
        if(vertex_array[i])
        {
            array[i] = new char[strlen(vertex_array[i] -> trail) + 1];
            strcpy(array[i], vertex_array[i] -> trail);
        }
        else
            array[i] = NULL;
    }
    return vertex_size;
}

int graph::insert_edge(char * start_name, const edge * to_insert)
{
    if(!start_name || !to_insert) return -1;
    int start_index = 0;
    int end_index = 0;

    //Find the index where the target vertices are.
    if( find(start_name, start_index) < 0 || 
        find(to_insert -> trail, end_index) < 0 )
        return -1;
    edge * new_edge = new edge;
    new_edge -> copy(to_insert);

    //Assigned edge source
    new_edge -> source = vertex_array[end_index];

    return vertex_array[start_index] -> insert_edge(new_edge);
}

int graph::find(char * find, int & index)
{
    index = 0;
    int i = 0;
    for(; i < vertex_size; ++i)
    {
        if( !strcmp(vertex_array[i] -> trail, find) )
        {
            index = i;
            return index;
        }
    }
    return -1;
}

bool graph::insert_vertex(vertex *& to_insert)
{
    if(!to_insert) return -1;
    int i = false;
    int copied = 0;
    vertex * new_vertex = new vertex;
    new_vertex -> copy(to_insert);
    vertex ** current = vertex_array;

    for(; i < vertex_size && !copied; ++i, ++current)
    {
        if(!*current)
        {
            *current = new_vertex;
            copied = true;
        }
    }
    return copied;
}

graph::graph(int size)
{
    vertex_size = size;
    vertex_array = new vertex * [size]; 
    vertex ** current = vertex_array;
    for(int i = 0; i < size; ++i, ++current)
        *current = NULL;
}

graph::~graph()
{
    vertex ** current = vertex_array;
    for(int i = 0; i < vertex_size; ++i, ++(current))
    {
        if(*current)
        {
            delete *current;
            *current = NULL;
        }
    }
    delete [] vertex_array;
    vertex_array = NULL;
}


/* Nicholas Grout
 * Professor: Karla Fant
 * Assignment: 5
 *
 * Filename: graph.h
 *
 * INPUT: trail heads and vertices
 * OUTPUT: trail headas and vertices and edges between them.
 */
#include <cctype>
#include <cstring>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "vertex_edge.h"

#ifdef VERTEX_EDGE_
#ifndef GRAPH_
#define GRAPH_
class graph
{
    public:
        graph(int vertices);
        ~graph();
        bool insert_vertex(vertex *& to_insert);
        int insert_edge(char * start_name, const edge * to_insert);
        int return_names(char **& array);
        //Display all possible paths from a vertex
        int display_paths(char * start);
        //Display all directly connecting connections to a vertex
        int display_connections(char * start);
    private:
        int display_connections(edge * head);
        int display_paths(edge * head, vertex * start);
        int find(char * to_find, int & index);
        int vertex_size; //This represents how big our vertex array is.
        vertex ** vertex_array;
};
#endif
#endif

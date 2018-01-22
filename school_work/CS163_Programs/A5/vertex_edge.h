/* Nicholas Grout
 * Professor: Karla Fant
 * Assignment: 5
 *
 * Filename: vertex_edge.h
 */
#include <cctype>
#include <cstring>
#include <stdlib.h>
#include <iostream>
using namespace std;

#ifndef VERTEX_EDGE_
#define VERTEX_EDGE_
struct edge;

struct vertex
{
    vertex();
    ~vertex();
    edge * head;
    //Trail information:
    char * trail; //This is the name of trail or trailhead.
    bool visited;
    bool trail_head; //Is this vertex a trail head or intersection?

    int copy(vertex * to_copy);
    int insert_edge(edge *& to_insert);
    int insert_edge(edge *& to_insert, edge *& head);
    int remove_all(edge *& head);
};

struct edge
{
    edge();
    edge(const edge & to_copy);
    ~edge();
    edge * next;
    vertex * source;
    //Trail segment information:
    char * trail;
    float length;
    bool dog_friendly;
    bool walking;
    bool running;
    bool biking;
    bool birding;

    int copy(const edge *& to_copy);
    int display(void);
};
#endif

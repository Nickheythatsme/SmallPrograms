/* Nicholas Grout
 * Professor: Karla Fant
 * Assignment: 5
 *
 * Filename: main.cpp
 */
#include <iostream>
#include <fstream>
#include "graph.h"
#define TEMP 2000
#define DELIM ','
using namespace std;

int read_in_edge(graph & a_graph);
int load_vertices(char * infile, graph & a_graph);
int display_vertices(graph & a_graph);
int display_connections(graph & a_graph);
int display_paths(graph & a_graph);
int add_edge(graph & a_graph);

int main(int argc, char * argv[])
{
    char * file_name = new char[strlen("trails.txt") + 1];
    strcpy(file_name, "trails.txt");
    graph test_graph(56);
    cout << "Vertecies read: " << load_vertices(file_name,test_graph) << endl;
    if( display_vertices(test_graph) < 0 )
        cout << "Error displaying all vertices\n";
    if( add_edge(test_graph) < 0 )
        cout << "Error adding edge\n";
    if( display_connections(test_graph) < 0 )
        cout << "Error displaying connections\n";
    if( display_paths(test_graph) < 0 )
        cout << "Error displaying paths\n";
    return 0;
}

int add_edge(graph & a_graph)
{
    char answer = ' ';
    do{
        if( read_in_edge(a_graph) < 0 )
            return -1;
        cout << "Again? (Y or n): ";
        cin >> answer;
        cin.ignore(100,'\n');
    }while(toupper(answer) == 'Y');
    return 1;
}

int read_in_edge(graph & a_graph)
{
    char start[TEMP];
    char end[TEMP];
    char temp;
    float distance = 0.0;
    edge * new_edge = new edge;

    cout << "\nNow entering edge between two intersections: \n";
    cout << "Enter first trail: ";
    cin.get(start, TEMP,'\n');
    cin.ignore(100,'\n');

    cout << "Enter connecting trail: ";
    cin.get(end,TEMP,'\n');
    cin.ignore(100,'\n');

    cout << "Enter distance to trail (ex: 2.3): ";
    cin >> distance;
    cin.ignore(100,'\n');

    cout << "Dog friendly? (Y or N): ";
    cin >> temp;
    cin.ignore(100,'\n');
    if(toupper(temp) == 'Y')
        new_edge -> dog_friendly = true;

    cout << "Walking friendly? (Y or N): ";
    cin >> temp;
    cin.ignore(100,'\n');
    if(toupper(temp) == 'Y')
        new_edge -> walking = true;

    cout << "Running friendly? (Y or N): ";
    cin >> temp;
    cin.ignore(100,'\n');
    if(toupper(temp) == 'Y')
        new_edge -> running = true;

    cout << "Biking friendly? (Y or N): ";
    cin >> temp;
    cin.ignore(100,'\n');
    if(toupper(temp) == 'Y')
        new_edge -> biking = true;
    
    cout << "Birding friendly? (Y or N): ";
    cin >> temp;
    cin.ignore(100,'\n');
    if(toupper(temp) == 'Y')
        new_edge -> birding = true;

    //Add edge from start to end
    new_edge -> trail = new char[strlen(end) + 1];
    strcpy(new_edge -> trail, end);
    if(a_graph.insert_edge(start, new_edge) < 0 )
    {
        cout << "Error adding edge for: " << start << endl;
        return -1;
    }
    
    //Add edge from end to start
    if( new_edge -> trail )
        delete [] new_edge -> trail;
    new_edge -> trail = new char[strlen(start) + 1];
    strcpy(new_edge -> trail, start);
    if(a_graph.insert_edge(end, new_edge) < 0 )
    {
        cout << "Error adding edge for: " << end << endl;
        return -1;
    }

    if(new_edge)
        delete new_edge;
    new_edge = NULL;

    return 1;
}

int load_vertices(char * infile, graph & a_graph)
{
    int count = 0;
    char temp[TEMP];
    vertex * temp_vert = new vertex;
    ifstream fin;
    fin.open(infile);
    if(!fin) return -1;

    fin.get(temp,TEMP,DELIM);
    fin.ignore(TEMP,DELIM);
    temp_vert -> trail = new char[strlen(temp) + 1];
    strcpy(temp_vert -> trail, temp);

    while( !fin.eof() )
    {
        fin >> temp[0];
        fin.ignore(TEMP,'\n');
        if(temp[0] == '1')
            temp_vert -> trail_head = true;
        
        a_graph.insert_vertex(temp_vert);
        ++count;
        delete temp_vert;
        temp_vert = new vertex;

        fin.get(temp,TEMP,DELIM);
        fin.ignore(TEMP,DELIM);
        temp_vert -> trail = new char[strlen(temp) + 1];
        strcpy(temp_vert -> trail, temp);
    }
    if(temp_vert)
        delete temp_vert;
    temp_vert = NULL;
    return count;
}

int display_vertices(graph & a_graph)
{
    char ** names = NULL;
    int size = a_graph.return_names(names);
    cout << "Displaying all names: " << endl;
    for(int i = 0; i < size /*&& names[i]*/; ++i)
    {
        if(names[i])
        {
            cout << "Trail/intersection name: " << names[i] << endl;
            delete [] names[i];
            names[i] = NULL;
        }
    }
    delete [] names;
    names = NULL;
    return size;
}

int display_connections(graph & a_graph)
{
    char temp[TEMP];
    cout << "\nNow displaying all direct connections from a vertex...\n";
    cout << "Enter trail intersection or head: ";
    cin.get(temp,TEMP,'\n');
    cin.ignore(100,'\n');

    return a_graph.display_connections(temp);
}

int display_paths(graph & a_graph)
{
    char temp[TEMP];
    cout << "\nNow displaying all paths from a vertex...\n";
    cout << "Enter trail intersection or head: ";
    cin.get(temp,TEMP,'\n');
    cin.ignore(100,'\n');

    return a_graph.display_paths(temp);
}

/* Nicholas Grout
 * HW1
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <assert.h>

/* These are for solving/displaying the maze. It's easier to keep track of what
 * is open and closed when we can just write OPEN or OPENED */
#define CLOSED 'X'
#define OPENED ' '
#define OPEN '0'

/* THESE are for the direction functions. It's much easier to think of 1 as
 * RIGHT than remember and recalculate what each value represents.
 * Values are assigned in a clockwise order */
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

/* This is for reading/writing to the file */
#define MAX 1000
#define FILE_OUT "solved.txt"

/* Struct to hold coordinates for a location */
struct coord
{
    int row;
    int column;
};

/* Struct to hold maze info */
struct maze_info
{
    struct coord dimensions;
    struct coord entrance;
    struct coord exit;
    char** maze;
};


/* Supporting functions */
/* Displays the maze */
void display_maze(struct maze_info* obj);
/* Gets the maze, simply makes a new pointer to where the maze starts */
char** get_maze(char** text);
/* Get the coords. Used for dimensions, entrance, exit */
int get_coords(char* text, struct coord* dest);
/* Loads the maze into a maze_info object*/
int load_maze(const char * file_name, struct maze_info* obj);
/* Writes the completed maze to a file */
int write_maze(const char* file_name, struct maze_info* obj);

/* Active functions */
/* Test if a move is valid. Returns 0 if not, and 1 if it is valid.*/
int valid_move(struct maze_info* , struct coord* test);
/* Returns 1 if we're at the exit, 0 if we're not */
int finished(struct maze_info* obj, struct coord* test);
/* Calls make_move() function with different moves */
int make_move(struct maze_info* obj, struct coord* previous, struct coord* current);
/* Makes the move and tests it! Returns 1 if success, 0 if failure*/
int test_move(struct maze_info* obj, struct coord* current, int direction, int move);

/* Direction functions */
/* Returns the direction we're headed based off current and prev coordinates */
int find_direction(struct coord* current_coords, struct coord* prev_coords);
/* Go right based on past move context */
int go_right(struct coord* current, int direction);
/* Go forward based on past move context */
int go_forward(struct coord* current, int direction);
/* Go left based on past move context */
int go_left(struct coord* current, int direction);
/* Go backward based on past move context */
int go_backward(struct coord* current, int direction);

/* String functions */
/* For some reason strnlen() doesn't show up on this machine */
int strnlen(const char* text, size_t max);

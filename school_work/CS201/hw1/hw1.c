/* Nicholas Grout
 * HW1
 *
 * This file contains all the movement deciding functions, and all the 
 * supporting functions such as reading/parsing coordinates.
 */
#include "hw1.h"

int main(int argc, char* argv[])
{
    int i;

    /* Make the previous and current coordinates */
    struct coord current_coords;
    struct coord previous_coords;

    /* Make the maze object */
    struct maze_info maze_obj;

    /* Check if we got arguments */
    if( argc <= 1 )
    {
        printf("Usage: ./hw1 [maze_file_name]\n");
        return 1;
    }

    /* Load the maze */
    if( !load_maze(argv[1], &maze_obj) )
    {
        printf("Maze file \"%s\" not found\n",argv[1]);
        return 1;
    }

    /*Set the current and previous coordinates to the entrance */
    current_coords = maze_obj.entrance;
    previous_coords = maze_obj.entrance;

    /* Set the entrance of the maze to the opened state */
    maze_obj.maze[current_coords.row][current_coords.column] = OPENED;

    /* Make the moves! */
    while( !finished(&maze_obj, &current_coords) )
        make_move(&maze_obj, &previous_coords, &current_coords);

    /* Display the maze after completion */
    display_maze(&maze_obj);

    /* Write the solved maze to a text file */
    write_maze(FILE_OUT, &maze_obj);

    /* Free memory */
    for(i = 0; i < maze_obj.dimensions.row; ++i)
        free(maze_obj.maze[i]);
    free(maze_obj.maze);

    return 0;
}

/* Test if a move is valid. Returns 0 if not, and 1 if it is valid.*/
int valid_move(struct maze_info* obj, struct coord* current)
{
    if( obj -> dimensions.row <= current -> row || 0 > current -> row ||
        obj -> dimensions.column <= current -> column || 0 > current -> column )
        return 0;
    if( obj -> maze[current -> row][current -> column] == CLOSED )
        return 0;
    return 1;
}

int make_move(struct maze_info* obj, struct coord* previous, struct coord* current)
{
    int i;
    int direction = find_direction(current,previous);

    /* Save the current coords into the previous coords for next time */
    previous -> row = current -> row;
    previous -> column = current -> column;

    /* Make moves */
    i=0;
    while( !test_move(obj, current, direction, i) && i < 4)
        ++i;
    /* Check if we didn't make a successful turn */
    if( i >= 4 ) return -1;

    return direction;
}

/* Makes the actual moves. Returns 1 if success, 0 if failure. -1 if error.*/
int test_move(struct maze_info* obj, struct coord* current, int direction, int move)
{
    struct coord temp_coords = *current;
    switch(move)
    {
        case 0:
            go_right(&temp_coords, direction);
            break;
        case 1:
            go_forward(&temp_coords, direction);
            break;
        case 2:
            go_left(&temp_coords, direction);
            break;
        case 3:
            go_backward(&temp_coords, direction);
            break;
        default:
            return -1;
    }

    if( valid_move(obj, &temp_coords) )
    {
        *current = temp_coords;

        /* OPEN up the space we've been into */
        obj -> maze[temp_coords.row][temp_coords.column] = OPENED;
        return 1;
    }
    return 0;
}

/* Returns 1 if we're at the exit, 0 if we're not */
int finished(struct maze_info* obj, struct coord* current)
{
    if( current -> row == obj -> exit.row &&
        current -> column == obj -> exit.column)
        return 1;
    return 0;
}

/*Just displays the maze before solving and after solving. Returns nothing.*/
void display_maze(struct maze_info* obj)
{
    int i;
    /* Each line of the maze has its own new line char so we don't add one here */
    for(i=0; i < obj -> dimensions.row; ++i)
        printf("%s",obj -> maze[i]);

    return;
}

/*Simply returns a pointer to the char** array where the maze actually starts.*/
char** get_maze(char** text)
{
    char** maze = text;
    while( maze[0][0] != CLOSED && maze[0][0] != OPEN )
        ++maze;
    return maze;
}

/*Gets the coordinates for dimension, entrance, exit. Returns an array of two 
ints.*/
int get_coords(char* text, struct coord* dest)
{
    /* Coordinates are given in x,y but we need to think in terms of row,column
     * so we need to switch them since 2D arrays are closer to maze[y][x].
     */
    if( text[0] == CLOSED || text[0] == OPEN ) return 0;
    sscanf(text,"%d,%d\n", &dest -> column, &dest -> row);

    return 1;
}

int load_maze(const char * file_name, struct maze_info* obj)
{
    char temp[1000];
    FILE * fin;
    int i = 0;
    int temp_len;

    /* Open and check for the file */
    fin = fopen(file_name, "r");
    if( !fin ) return 0;

    /* Get the dimensions */
    fgets(temp, 1000, fin);
    if( !get_coords(temp, &obj -> dimensions) )
        return 0;

    /* Get the entrance */
    fgets(temp, 1000, fin);
    if( !get_coords(temp, &obj -> entrance) )
        return 0;

    /* Get the exit */
    fgets(temp, 1000, fin);
    if( !get_coords(temp, &obj -> exit) )
        return 0;

    /* Make room for the maze */
    obj -> maze = (char**) malloc(sizeof(char*) * obj -> dimensions.row);

    /* Copy each line of the maze */
    /* We use i as a stopping point as well because some maze files have an
     * extra new line character, doing this prevents memory leaks */
    while( i < obj -> dimensions.row && !feof(fin) )
    {
        fgets(temp, 1000, fin);
        temp_len = strnlen(temp, MAX);
        obj -> maze[i] = (char*) malloc(sizeof(char) * temp_len);
        strncpy(obj -> maze[i], temp, temp_len);
        ++i;
    }

    fclose(fin);
    return 1;
}

/* Writes the completed maze to a file */
int write_maze(const char* file_name, struct maze_info* obj)
{
    FILE * fout;
    int i;

    /* Open and check for the file */
    fout = fopen(file_name, "w");
    if(!fout) return 0;

    /* Write the dimensions again */
    fprintf(fout, "%d,%d\n", obj -> dimensions.column, obj -> dimensions.row);

    /* Write the entrance */
    fprintf(fout, "%d,%d\n", obj -> entrance.column, obj -> entrance.row);

    /* Write the exit */
    fprintf(fout, "%d,%d\n", obj -> exit.column, obj -> exit.row);

    /* Write the maze */
    for(i=0; i < obj -> dimensions.row; ++i)
        fprintf(fout, "%s\n", obj -> maze[i] );

    fclose(fout);
    return 1;
}

/* strnlen() doesn't show up on this machine so I made one */
int strnlen(const char* text, size_t max)
{
    int i=0;
    while( *text && i < max )
    {
        ++text;
        ++i;
    }
    return i;
}

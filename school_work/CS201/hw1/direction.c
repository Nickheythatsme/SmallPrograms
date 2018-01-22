/* Nicholas Grout
 * HW1
 *
 *
 * This file contains all the functions for managing and finding our direction.
 * The find_direction returns our direction as an integer, and the other
 * functions make moves based on our current direction
 */

#include "hw1.h"

/* This function figures out which direction we're facing.
 * (Clockwise)
 *
 * 0 is facing UP
 * 1 is facing RIGHT
 * 2 is facing DOWN
 * 3 is facing LEFT
 *
 */
int find_direction(struct coord* current, struct coord* prev)
{
    int row_diff = current -> row - prev -> row;
    int column_diff = current -> column - prev -> column;

    /* If both row and column have changed then something is wrong */
    if( row_diff != 0 && column_diff != 0 ) return 0;

    /* If we're just starting and previous == current then we just need 
     * to choose a direction */
    if( row_diff == 0 && column_diff == 0 ) return DOWN;


    /* figure out which direction we're facing */
    /* UP */
    if( row_diff < 0 )
        return UP;
    /* DOWN */
    if( row_diff > 0 )
        return DOWN;
    /* LEFT */
    if( column_diff < 0 )
        return LEFT;
    /* RIGHT */
    if( column_diff > 0 )
        return RIGHT;
    return -1;
}

int go_right(struct coord* obj, int direction)
{
    switch(direction)
    {
        case UP:
            obj -> column++;
            break;
        case RIGHT:
            obj -> row++;
            break; 
        case DOWN:
            obj -> column--;
            break;
        case LEFT:
            obj -> row--;
            break;
    }
    return 1;
}

int go_forward(struct coord* obj, int direction)
{
    switch(direction)
    {
        case UP:
            obj -> row--;
            break;
        case RIGHT:
            obj -> column++;
            break;
        case DOWN:
            obj -> row++;
            break;
        case LEFT:
            obj -> column--;
            break;
    }
    return 1;
}

int go_left(struct coord* obj, int direction)
{
    switch(direction)
    {
        case UP:
            obj -> column--;
            break;
        case RIGHT:
            obj -> row--;
            break;
        case DOWN:
            obj -> column++;
            break;
        case LEFT:
            obj -> row++;
            break;
    }
    return 1;
}

int go_backward(struct coord* obj, int direction)
{
    switch(direction)
    {
        case UP:
            obj -> row++;
            break;
        case RIGHT:
            obj -> column--;
            break;
        case DOWN:
            obj -> row--;
            break;
        case LEFT:
            obj -> column++;
            break;
    }
    return 1;
}

#include "grid.h"

// CONSTRUCTOR
Grid::Grid(unsigned long nheight, unsigned long nwidth) : dimensions(nheight, nwidth)
{
    grid = NULL;
}

// CONSTRUCTOR
Grid::Grid(Vec v) : dimensions(v)
{
    grid = NULL;
}

// COPY CONSTRUCTOR
Grid::Grid(const Grid &obj) : dimensions(obj.dimensions)
{
    // Copy the obj's grid if it exists
    if(obj.grid)
    {
        Draw();

        for(auto i = 0u; i < dimensions.h; ++i)
            grid[i] = obj.grid[i];
    }
    else
        grid = NULL;
}

// DESTRUCTOR 
Grid::~Grid()
{
    delete [] grid;
}

/* Automated constructor. Will create a completely closed grid based on the 
 * stored dimensions */
void Grid::Draw()
{
    if(grid)
        delete [] grid;

    char filler[dimensions.w + 1];
    for(char &c : filler)
        c = CLOSED;
    filler[dimensions.w] = '\0';

    grid = new string[dimensions.h];
    for(auto x = 0u; x < dimensions.h; ++x)
        grid[x] = filler;
}

/* Output to a stream (we don't use an operator to because of inheritance */
std::ostream& Grid::display(std::ostream &out) const
{
    if(!grid)
    {
        out << "NOPE" << std::endl;
        return out;
    }

    for(auto x = 0u; x < dimensions.h; ++x)
    {
        for(auto j = 0u; j < dimensions.w; ++j)
            out << grid[x][j] << ' ';
        out << std::endl;
    }
    return out;
}

/* Assignment operator */
Grid& Grid::operator=(const Grid &obj)
{
    delete [] grid;
    grid = NULL;
    dimensions = obj.dimensions;

    /* Only draw if we need to draw */
    if(obj.grid)
    {
        Draw();

        for(auto i = 0u; i < dimensions.h; ++i)
            grid[i] = obj.grid[i];
    }
    return *this;
}

/* Resize the grid CREATING A NEW GRID */
void Grid::Resize(Vec v)
{
    dimensions = v;
    Draw();
}

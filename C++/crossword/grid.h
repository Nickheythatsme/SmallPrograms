#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

#ifndef GRID_
#define GRID_

#define CLOSED '@'
#define OPEN   ' '
#define GRID_MAX 1000

struct Vec
{
    Vec() = default;
    Vec(const Vec &obj) = default;
    Vec(unsigned long nheight, unsigned long nwidth) {h = nheight; w = nwidth;}
    Vec(unsigned long x) {h = x; w = x;}
    ~Vec() = default;
    unsigned long h;
    unsigned long w;
};

/* Handle and make the initial Grid */
class Grid
{
    public:
        Grid(unsigned long height = 25, unsigned long width = 25);
        Grid(Vec v);
        Grid(const Grid &obj);
        virtual ~Grid();

        /* Assignment operator */
        Grid& operator=(const Grid &obj);

        /* Output to an ostream */
        std::ostream& display(std::ostream &out) const;

        /* Return the dimensions of the grid */
        Vec Dimensions() const {return dimensions;}

        /* Test if a space is open */
        bool IsOpen(Vec v) const {return grid[v.h][v.w] == OPEN;}

        /* Open or close spaces on the grid */
        void Open(Vec v)  {grid[v.h][v.w] = OPEN;}
        void Close(Vec v) {grid[v.h][v.w] = OPEN;}

        /* Make an empty grid with the dimensions stored */
        void Draw();
    protected:
        /* Resize the grid CREATING A NEW GRID */
        void Resize(Vec v);

        /* Store the dimensions of the grid */
        Vec dimensions;
        string* grid;
    private:
};

#endif //GRID_

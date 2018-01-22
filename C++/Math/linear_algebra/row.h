#include <stdlib.h>
#include <iostream>

#ifndef ROW_
#define ROW_

/*
namespace linear_algebra{
namespace row{
*/
template <class DATA>
class row;

template <class DATA>
std::ostream& operator<<(std::ostream& out, const row<DATA>& obj);

/* Addition operators */
template <class DATA>
row<DATA>& operator+=(row<DATA>& add_to, const row<DATA>& add_from);
template <class DATA>
row<DATA> operator+(const row<DATA>& add_to, const row<DATA>& add_from);

/* Subtraction operators */
template <class DATA>
row<DATA>& operator-=(row<DATA>& sub_to, const row<DATA>& sub_from);
template <class DATA>
row<DATA> operator-(const row<DATA>& sub_to, const row<DATA>& sub_from);

template <class DATA>
class row
{
    public:
        row();
        //TODO make list-initializer constructor
        row(const DATA* new_array, int len);
        row(const row<DATA>& obj);
        ~row();
        /* Sets the row to the DATA array. Returns the current row object */
        row<DATA>& set(const DATA* new_array, int len);
        row<DATA>& set(const row<DATA>& obj);
        /* Retrieve the data array if it exists. 
         * Returns the length of the array */
        int get(DATA*& array) const;
        /* Clears the array if it exists. Returns the current row object */
        row<DATA>& clear(void);
        /* Returns the object at index from our array. DOES NOT check for 
         * bounds! */
        DATA& operator[](int index);
        /* Formats output of the row. This is meant to be a visual program
         * anyway */
        friend std::ostream& operator<< <>(std::ostream& out, const row& obj);
        std::ostream& display(std::ostream& out) const;
        /* Dot product. Returns the dot product by value*/
        DATA dot(const row& obj) const;
        /* Magnitude squared of our vector */
        DATA magnitude_sqr(void) const;
        /* Length of the vector */
        int length(void) const;

        /* Addition operators (use +=) */
        friend row<DATA>& operator+= <>(row<DATA>& add_to, const row<DATA>& add_from);
        friend row<DATA> operator+ <>(const row<DATA>& add_1, const row<DATA>& add_2);

        /* Subraction operators (use -=) */
        friend row<DATA>& operator-= <>(row<DATA>& sub_to, const row<DATA>& sub_from);
        friend row<DATA> operator- <>(const row<DATA>& sub_to, const row<DATA>& sub_from);

        /* Scalar multiplication operators (use *=) */
        row<DATA> operator*(const DATA& scalar);
        row<DATA>& operator*=(const DATA& scalar);

        /* Sets the row to be equivelent to another row */
        row<DATA>& operator=(const row<DATA>& obj);
    private:
        DATA* array;
        int len;
};


//}/*row*/
//}/*linear_algebra*/

#include "row.cpp"

#endif

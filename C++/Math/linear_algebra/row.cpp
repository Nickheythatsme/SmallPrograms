#include "row.h"

/* Dot product. Returns the dot product by value*/
template<class DATA>
DATA row<DATA>::dot(const row& obj) const
{
    /* PERFORMANCE: 
     * we're making three copies of result I think? Fix that. */
    /* Initialize result variable */
    DATA result = array[0] * obj.array[0];

    /* PERFORMANCE: we're making many DATA objects here as well */
    for(int i = 1; i < len; ++i)
        result += array[i] * obj.array[i];

    return DATA(result);
}

/* Magnitude squared of our vector */
template<class DATA>
DATA row<DATA>::magnitude_sqr(void) const
{
    /* Initialize result variable */
    DATA result = array[0];

    for(int i = 1; i < len; ++i)
        result += array[i];

    return result;
}

/* Returns the length of our object */
template<class DATA>
int row<DATA>::length(void) const
{
    return len;
}

/* Sets the row to the DATA array. Returns the current row object */
template<class DATA>
row<DATA>& row<DATA>::set(const DATA* new_array, int new_len)
{
    clear();
    array = new DATA[new_len];
    for(int i = 0; i < len; ++i)
        array[i] = new_array[i];
    return *this;
}

template<class DATA>
row<DATA>& row<DATA>::set(const row<DATA>& obj)
{
    /* Clear our array if we have one */
    clear();
    /* Check if we have an array in the new object */
    if( obj.array )
    {
        len = obj.len;
        array = new DATA[obj.len];

        /* Copy over each index of new object */
        for(int i = 0; i < len; ++i)
            array[i] = obj.array[i];
    }
    else
    {
        array = NULL;
        len = 0;
    }
    return *this;
}

/* Retrieve the data array if it exists. 
 * Returns the length of the array */
template<class DATA>
int row<DATA>::get(DATA*& r_array) const
{
    if( !array ) return 0;

    r_array = new DATA[len];
    for(int i = 0; i < len; ++i)
        r_array[i] = array[i];

    return len;
}

/* Clears the array if it exists. Returns the current row object */
template<class DATA>
row<DATA>& row<DATA>::clear(void)
{
    delete [] array;
    array = NULL;
    return *this;
}

/* Sets the row to be equivelent to another row */
template<class DATA>
row<DATA>& row<DATA>::operator=(const row<DATA>& obj)
{
    return set(obj);
}

/* Returns the object at index from our array. DOES NOT check for 
 * bounds! */
template<class DATA>
DATA& row<DATA>::operator[](int index)
{
    return array[index];
}

/* Addition operators (use +=) */
template<class DATA>
row<DATA>& operator+=(row<DATA>& add_to, const row<DATA>& add_from)
{
    for(int i = 0; i < add_to.len; ++i)
        add_to.array[i] += add_from.array[i];
    return add_to;
}

/* Addition operator. This creates and returns another row object */
template<class DATA>
row<DATA> operator+(const row<DATA>& add_1, const row<DATA>& add_2)
{
    row<DATA> result(add_1.array, add_1.len);
    result += add_2;
    return result;
}

/* Subtraction operators */
template<class DATA>
row<DATA>& operator-=(row<DATA>& sub_to, const row<DATA>& sub_from)
{
    for(int i = 0; i < sub_to.len; ++i)
        sub_to.array[i] -= sub_from.array[i];
    return sub_to;
}

template<class DATA>
row<DATA> operator-(const row<DATA>& sub_1, const row<DATA>& sub_2)
{
    row<DATA> result(sub_1.array, sub_1.len);
    result -= sub_2;
    return result;
}

/* Scalar multiplies each member of our row to the scalar */
template<class DATA>
row<DATA> row<DATA>::operator*(const DATA& scalar)
{
    row<DATA> result = *this;
    if(!array) return *this;
    for(int i = 0; i < len; ++i)
        result[i] *= scalar;
    return result;
}

/* Scale the original object */
template<class DATA>
row<DATA>& row<DATA>::operator*=(const DATA& scalar)
{
    if(!array) return *this;
    for(int i = 0; i < len; ++i)
        (*this)[i] *= scalar;
    return *this;
}

/* Formats output of the row. This is meant to be a visual program
 * anyway */
template<class DATA>
std::ostream& operator<<(std::ostream& out, const row<DATA>& obj)
{
    return obj.display(out);
}

template<class DATA>
std::ostream& row<DATA>::display(std::ostream& out) const
{
    if( !array ) return out;
    out << '[';
    for(int i = 0; i < len; ++i)
    {
        out << array[i];
        if( i < len - 1 )
            out << ", ";
    }
    out << ']';
    return out;
}

/* Standard constructor */
template<class DATA>
row<DATA>::row()
{
    array = NULL;
    len = 0;
}

/* Constructor with new array/len arguments */
template<class DATA>
row<DATA>::row(const DATA* new_array, int new_len)
{
    len = new_len;
    array = new DATA[len];

    /* Copy over each index of new array */
    for(int i = 0; i < len; ++i)
        array[i] = new_array[i];
}

/* COPY CONSTRUCTOR */
template<class DATA>
row<DATA>::row(const row<DATA>& obj)
{
    /* Check if we have an array in the new object */
    if( obj.array )
    {
        len = obj.len;
        array = new DATA[obj.len];

        /* Copy over each index of new object */
        for(int i = 0; i < len; ++i)
            array[i] = obj.array[i];
    }
    else
    {
        array = NULL;
        len = 0;
    }
}

/* DESTRUCTOR */
template<class DATA>
row<DATA>::~row()
{
    if( array )
        clear();
}

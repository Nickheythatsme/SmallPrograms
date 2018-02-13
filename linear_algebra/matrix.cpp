#include "matrix.h"

/* Scalar by a vector. Returns the modified matrix */
template<class DATA>
matrix<DATA>& matrix<DATA>::operator*(row<DATA>& obj)
{
    if(!rows) return *this;
    for(int i = 0; i < len; ++i)
        rows[i] *= obj;
    return *this;
}

/* Formatted output. Returns the ostream object used */
template<class DATA>
std::ostream& operator<<(std::ostream& out, const matrix<DATA>& obj)
{
    return obj.display(out);
}

/* Formatted output. Returns ostream object we used */
template<class DATA>
std::ostream& matrix<DATA>::display(std::ostream& out) const
{
    if(!rows) return out;
    for(int i = 0; i < len; ++i)
        out << rows[i] << std::endl;
    return out;
}

/* CONSTRUCTOR */
template<class DATA>
matrix<DATA>::matrix()
{
    rows = NULL;
    len = 0;
}

/* COPY CONSTRUCTOR */
template<class DATA>
matrix<DATA>::matrix(const matrix<DATA>& obj)
{
    if(obj.rows)
    {
        len = obj.len;
        rows = new row<DATA>[obj.len];
        for(int i = 0; i < len; ++i)
            rows[i] = obj.rows[i];
    }
    else
    {
        rows = NULL;
        len = 0;
    }
}

/* CONSTRUCTOR WITH ARGUMENTS */
template<class DATA>
matrix<DATA>::matrix(const row<DATA>* new_objs, int new_len)
{
    len = new_len;
    rows = new row<DATA>[new_len];

    for(int i = 0; i < len; ++i)
        rows[i] = new_objs[i];
}

/* DESTRUCTOR */
template<class DATA>
matrix<DATA>::~matrix()
{
    if( rows ) delete [] rows;
    rows = NULL;
}

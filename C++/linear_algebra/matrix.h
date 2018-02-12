#include "row.h"

#ifndef MATRIX_
#define MATRIX_

template<class DATA>
class matrix;

template<class DATA>
std::ostream& operator<<(std::ostream& out, const matrix<DATA>& obj);


template<class DATA>
class matrix
{
    public:
        matrix();
        matrix(const matrix<DATA>& obj);
        matrix(const row<DATA>* objs, int len);
        ~matrix();
        /* Scalar by a vector. Returns the modified matrix */
        matrix<DATA>& operator*(row<DATA>& obj);
        /* Ostream integration */
        friend std::ostream& operator<< <>(std::ostream& out, const matrix<DATA>& obj);
        std::ostream& display(std::ostream& out) const;
    private:
        row<DATA>* rows;
        int len;
};

#include "matrix.cpp"

#endif

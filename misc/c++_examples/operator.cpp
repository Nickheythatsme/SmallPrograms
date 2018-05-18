#include "operator.h"

std::ostream& operator<<(std::ostream &out, const list &obj)
{
    out << obj.x << endl;
    return out;
}

list operator+(const list &lhs, const list &rhs)
{
    list temp = lhs;
    return lhs+= rhs;
}

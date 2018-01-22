#include "matrix.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    int int_array[] = {1,2,3,4,5};


    row<int> ref_row[3];
    for(int i = 0; i < 3; ++i)
        ref_row[i] = row<int>(int_array,5);
    ref_row[2] *= 2;

    matrix<int> test_matrix(ref_row,3);
    cout << test_matrix << endl;

}

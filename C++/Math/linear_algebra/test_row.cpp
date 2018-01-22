#include "row.h"

using std::cout;
using std::endl;

int test_perpendicular(void);
int test_functions(void);
int test_create_destroy(void);

int main(int argc, char* argv[])
{
    //test_functions();
    //test_perpendicular();
    test_create_destroy();
    return 1;
}

/* Test the support functions, copy constructors, destructors, etc */
int test_create_destroy(void)
{
    row<int> test_row({1,2,3},3);
    return;
}

/* Test each function of the row */
int test_functions(void)
{
    float reference_row[] = {1.0,2.0,3.2,4.5};
    float* result_row = NULL;
    int result_len;
    row<float> test_row(reference_row, 4);
    row<float> test2(reference_row, 4);

    /* Test ostream */
    cout << ">Testing ostream" << endl;
    cout << test_row << endl << endl;

    /* Test scalar */
    cout << ">Testing scalar (2.9)" << endl;
    test_row *= 2.9;
    cout << test_row << endl << endl;

    cout << ">Testing scalar (By value)" << endl;
    cout << test_row * 2.9 << endl << endl;

    /* Test indexing */
    cout << ">Testing indexing [0]" << endl;
    cout << test_row[0] << endl << endl;

    /* Test getting */
    cout << ">Testing get function" << endl;
    result_len = test_row.get(result_row);
    for(int i = 0; i < result_len; ++i)
        cout << result_row[i] << ' ';
    cout << endl << endl;

    /* Test clearing */
    cout << ">Testing clearing" << endl;
    test_row.clear();
    cout << test_row << endl << endl;

    /* Test setter */
    cout << ">Testing setter" << endl;
    test_row.set(result_row, result_len);
    cout << test_row << endl << endl;

    /* Test DOT product */
    cout << ">Testing DOT product"
         << "Row 1 dot Row 2" << endl
         << test_row << " dot " << test2 << endl;
    cout << test_row.dot(test2) << endl << endl;

    /* Test length */
    cout << ">Testing length" << endl;
    cout << test_row.length() << endl << endl;

    /* Test magnitude */
    cout << ">Testing magnitude squared" << endl;
    cout << test_row.magnitude_sqr() << endl;

    /* Testing subraction */
    cout << ">Testing subtraction" << endl
         << test_row << " - " << test2 << endl;
    test_row -= test2;
    cout << test_row << endl
         << (test_row - test2) << endl;

    /* Testing addition */
    cout << ">Testing addition" << endl
         << test_row << " + " << test2 << endl;
    test_row += test2;
    cout << test_row << endl
         << (test_row + test2) << endl;

    test_perpendicular();

    delete [] result_row;
}

int test_perpendicular(void)
{
    int u_int[] = {2,1,-1};
    int v_int[] = {1,3,5};
    row<int> u(u_int,3);
    row<int> v(v_int,3);

    cout << "Testing dot product. Should equal zero (perpendicular)" << endl
         << u.dot(v) << endl;
    return 1;
}

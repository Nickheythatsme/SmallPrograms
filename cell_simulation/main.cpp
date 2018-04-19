#include <cstdlib>
#include "seed.h"
#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;


int main(int argc, char **argv)
{
    char_seed s1(1);
    char_seed s2(1);
    s1.display(cout) << endl;

    s2.mutate();
    for(int i = 0; i < 1000; ++i)
    {
        s2 = s2 * s1;
        s2.mutate();
    }

    s2.display(cout) << endl;
}

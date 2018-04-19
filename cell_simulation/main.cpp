#include <cstdlib>
#include "seed.h"
#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;


int main(int argc, char **argv)
{
    auto s = char_seed::make_random_seed();
    printf("%s\n",s);
}

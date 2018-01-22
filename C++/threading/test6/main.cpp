#include <thread>
#include <iostream>

using std::cout;
using std::endl;
using std::thread;


int main(int argc, char* argv[])
{
    cout << std::thread::hardware_concurrency() << endl;
    return 0;
}

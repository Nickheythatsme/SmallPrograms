#include <thread>
#include <iostream>

using std::cout;
using std::endl;
using std::thread;

void arguments(int argc, char* args)
{
    for(int i = 0; i < argc; ++i)
        cout << args << endl;
    return;
}


int main(int argc, char* argv[])
{
    thread t(arguments,argc,argv[0]);
    t.join();
    return 0;
}

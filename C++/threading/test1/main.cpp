#include <thread>
#include <iostream>

using std::cout;
using std::endl;
using std::thread;

void hello(void)
{
    cout << "Hello world!" << endl;
    return;
}

int main(int agc, char* argv[])
{
    thread t(hello);
    t.join();
}

#include <thread>
#include <iostream>

using std::cout;
using std::endl;
using std::thread;

class worker
{
    public:
        void work_it(void)
        {
            cout << "this is a word" << endl;
            return;
        }
};

int main(int argc, char* argv[])
{
    worker w;
    thread t(&worker::work_it, &w);
    t.join();
    return 0;
}

#include <thread>
#include <iostream>

using std::cout;
using std::endl;
using std::thread;

class worker
{
    public:
        explicit worker(thread& new_t) : t(new_t)
        {
        }
        ~worker()
        {
            if(t.joinable())
                t.join();
            cout << "Joined!" << endl;
        }
        worker(worker const&)=delete;
        worker& operator=(worker const&)=delete;
    private:
        thread& t;
};

void test_worker(void)
{
    for(int i = 0; i < 10; ++i)
        cout << "Testing!" << endl;
}

int main(int agc, char* argv[])
{
    thread t(test_worker);
    worker a_worker(t);
    return 0;
}

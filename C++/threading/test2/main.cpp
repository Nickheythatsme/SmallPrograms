#include <thread>
#include <iostream>

using std::cout;
using std::endl;
using std::thread;

struct function
{
    function(int new_value){value = new_value;}
    int value;
    void operator()()
    {
        for(int i = 0; i < value; ++i)
            cout << "hello world!" << endl;
    }
};

int main(int agc, char* argv[])
{
    int local_state = 1;
    function my_func(local_state);
    thread t(my_func);
    t.detach();
}

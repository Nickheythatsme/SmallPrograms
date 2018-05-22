#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "test_case.h"

using namespace std;

extern "C" {
    size_t char_len(signed char f);
    size_t delims_str(const char *str, const char *delims);
    int delims_char(const char *c, const char *delims);
}

bool t_char_len(string &str, nullptr_t &data)
{
    for (int i=0; i < 1000; ++i)
    {
        for (const auto c : str)
            char_len(c);
    }
    return true;
}

bool t_delims_char(string &str, nullptr_t &data)
{
    return true;
}

int main(int argc, char *argv[])
{
    base_config main_config("char_len", true, false, 10000);
    string test_str("this is a test");

    unit_test<string, nullptr_t> test_char_len(t_char_len, std::move(test_str), std::move(nullptr));
    test_char_len.set_base_config(main_config);
    test_char_len.start();
    cout << test_char_len.get_result() << endl;

    return 0;
}


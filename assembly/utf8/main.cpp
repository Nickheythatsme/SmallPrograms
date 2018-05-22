#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "test_case.h"

using namespace std;

//extern "C" {
    size_t char_len(signed char f);
    size_t delims_str(const char *str, const char *delims);
    int delims_char(const char *c, const char *delims);
//}

// Get the contents of the test file 
string get_fcontents(const char *filename)
{
    ifstream fin(filename);
    if (!fin) return string();
    fin.seekg(0, fin.end);
    size_t len = fin.tellg();
    fin.seekg(0, fin.beg);

    char *buff = new char[len + 1];
    fin.read(buff,len);
    fin.close();

    string temp(buff);
    delete [] buff;
    return temp;
}

// Test character length speed
bool t_char_len(string &str, nullptr_t &data)
{
    for (int i=0; i < 1000; ++i)
    {
        for (const auto c : str)
            char_len(c);
    }
    return true;
}

// Test delim testing speed
bool t_delims_char(string &str, string &delims)
{
    return delims_char(str.c_str(), delims.c_str());
}

int main(int argc, char *argv[])
{
    base_config main_config("char_len", true, false, 10000);
    string test_str("this is a test");

    unit_test<string, nullptr_t> test_char_len(t_char_len, std::move(test_str), std::move(nullptr));
    test_char_len.set_base_config(main_config);
    test_char_len.start();
    cout << test_char_len.get_result() << endl;

    string &&fcontents = get_fcontents("sample.txt");
    string delims = "†";
    unit_test<string, string> test_delims_char(t_delims_char, std::move(fcontents), std::move(delims));
    test_delims_char.set_base_config(main_config).set_name("delims_char");
    cout << test_delims_char.get_result() << endl;
    cout << "Name: " << test_delims_char.get_name() << endl;

    return 0;
}

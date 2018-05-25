#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <typeindex>
using std::cout;
using std::endl;

template<typename T>
class base
{
    public:
        void addAndCout(T &&name);
    private:
        std::vector<T> names;
        T my_name;

};

/*
 * Here name is a rvalue reference. rvalue references can bind to:
 *  rvalues
 *
 * The reason why name is NOT a universal reference is that T's type 
 * has been deduced when the class was created. If T was instead T2,
 * then T2's type would need to be deduced and name would be universal
 * reference.
 */
template<typename T>
void base<T>::addAndCout(T &&name)
{
    cout << name << endl;
    my_name = std::forward<T>(name);
    names.emplace_back(std::forward<T>(name));
}

/*
 * Here name's type is deduced when the function is called, so name is a
 * universal reference. Universal references can bind to:
 */
template<typename T>
void addAndCout(T &&name)
{
    cout << name << endl;
}

/*
 * Here name is an rvalue reference, since the type has already been declared and 
 * no type deduction needs to take place.
 */
void addAndCoutString(std::string &&name)
{
    std::string name1 = std::forward<std::string>(name);
}


int main(int argc, char **argv)
{
    std::string name {"test1"};

    /*
     * Calling addAndCout from a class of type std::string
     */
    base<std::string> b;
    // b.addAndCout(name); // NO name is a lvalue, and rvalues cannot bind to lvalues.
    b.addAndCout(std::move(name));  // YES name is cast unconditionally to an rvalue.
    b.addAndCout("test1"); // YES name has not been created yet and so is a temporary rvalue.
    b.addAndCout(std::string("test2")); // YES name does not have a location in memory and so is an rvalue


    /*
     * Call templated addAndCout NOT in a class, so the param will be a universal reference
     */
    addAndCout(name); // YES name here is an lvalue and universal references can bind to an lvalue
    addAndCout("test2"); // YES name here is an temporary object, rvalue, and universal references can bind to rvalues
    addAndCout(std::string("test3")); // YES rvalue
    addAndCout(std::move(name)); // YES rvalue. BUT name DOES NOT move, is only cast to an rvalue and a copy is made.
    // The reason why the above call does not bind to a universal reference is that only rvalue references can bind
    // to temporary rvalues, otherwise a copy will be made or the param will be cast to const


    /*
     * Call addAndCoutString which is not templated and is not part of a class
     */
    addAndCoutString(std::string(name)); // YES param is an rvalue
    // addAdnCoutString(name);         // NO name is an lvalue and rvalue references cannot bind to lvalues
    addAndCoutString(std::move(name)); // YES param is an rvalue AND is actually moved
    cout << "name: " << name << endl;  // nothing displays
}


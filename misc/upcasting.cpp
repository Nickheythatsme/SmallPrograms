#include <iostream>
using namespace std;

class base
{
    public:
        base() {}
        base(const base &obj) {}
        ~base() {}
        virtual const char* message() const {return "this is base";}
};

class deriv : public base
{
    public:
        deriv() : base() {}
        deriv(const deriv &obj) : base(obj) {}
        ~deriv() {}
        const char* message() const {return "this is deriv";}
};

void test(const base &rhs)
{
    base *ptr;
    cout << rhs.message() << endl;

    if (const base *d = dynamic_cast<const base *>(&rhs))
    {
        cout << "base" << endl;
        ptr = new base(*d);
    }
    if (const deriv *d = dynamic_cast<const deriv *>(&rhs))
    {
        cout << "deriv" << endl;
        ptr = new deriv(*d);
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    base b;
    deriv d;

    test(b);
    test(d);
}


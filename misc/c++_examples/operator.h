#include <ostream>

class list
{
    public:
        friend std::ostream& operator<<(std::ostream &out, const list &obj);
    private:
        int x;
};


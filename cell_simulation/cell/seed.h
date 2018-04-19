#include <ctime>
#include <iostream>
#include <random>
#include <cstring>

#ifndef CELL_SEED_
#define CELL_SEED_

#define SEED_LEN 64
#define MAIN_SEED 0xabcdef

class char_seed
{
    public:
        char_seed();
        char_seed(char *s);
        char_seed(unsigned int s);
        char_seed(const char_seed &obj);
        char_seed(char_seed &&rhs);
        std::ostream& display(std::ostream &out) const;
        friend char_seed operator*(const char_seed &lhs, const char_seed &rhs);

        // Assignment
        char_seed& operator=(char_seed &&rhs);
        char_seed& operator=(const char_seed &rhs);

        int mutate();

        /* Static functions */
        static char* make_random_seed();
        static char* make_seed(unsigned int);
    protected:
        char_seed cross(const char_seed &rhs) const;
        static std::normal_distribution<> normal_dist;
    private:
        char *data;
};

#endif // CELL_SEED_

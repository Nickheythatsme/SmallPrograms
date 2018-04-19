#include "seed.h"

#define MEAN 10
#define STDDEV 5
std::normal_distribution<> char_seed::normal_dist(SEED_LEN/2, SEED_LEN/4);

char_seed::char_seed()
{
    data = nullptr;
}

char_seed::char_seed(char *s)
{
    data = new char[SEED_LEN];
    strncpy(data, s, SEED_LEN);
}

char_seed::char_seed(const char_seed &obj)
{
    data = new char[SEED_LEN];
    strcpy(data, obj.data);
}

// Move constructor
char_seed::char_seed(char_seed &&rhs)
{
    data = rhs.data;
    rhs.data = nullptr;
}

// Assignment operator (move)
char_seed& char_seed::operator=(char_seed &&rhs)
{
    if(data) delete [] data;
    data = rhs.data;
    rhs.data = nullptr;
    return *this;
}

// Assignment operator (not move)
char_seed& char_seed::operator=(const char_seed &rhs)
{
    if(data) delete [] data;
    data = new char[SEED_LEN];
    strcpy(data, rhs.data);
    return *this;
}

std::ostream& char_seed::display(std::ostream &out) const
{
}

char_seed operator*(const char_seed &lhs, const char_seed &rhs)
{
}

/* Static functions */
char* char_seed::make_random_seed()
{
    std::random_device r{};
    std::mt19937 gen{r()};
    char* new_s = new char[SEED_LEN];

    for(int i = 0; i < SEED_LEN; ++i)
        new_s[i] = ' ';
    for(int i = 0; i < 5952; ++i)
        ++new_s[int(normal_dist(gen)) % SEED_LEN];
    for(int i = 0; i < SEED_LEN; ++i)
    {
        if((unsigned char)new_s[i] > 127){
            new_s[i] = (unsigned char) new_s[i] % 93;
            std::cout << "TOO LONG: " << new_s[i] << std::endl;
        }
    }

    return new_s;
}

char* char_seed::make_seed(char *text)
{
}

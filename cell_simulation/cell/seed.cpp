#include "seed.h"

#define MEAN 23
#define STDDEV 11
std::normal_distribution<> char_seed::normal_dist(SEED_LEN/2, SEED_LEN/4);

char_seed::char_seed()
{
    data = char_seed::make_random_seed();
}

char_seed::char_seed(char *s)
{
    data = new char[SEED_LEN];
    strncpy(data, s, SEED_LEN);
    data[SEED_LEN - 1] = '\0'; // Make sure to set it in case s is too long
}

char_seed::char_seed(unsigned int s)
{
    data = char_seed::make_seed(s);
}

char_seed::char_seed(const char_seed &obj)
{
    data = new char[SEED_LEN];
    strcpy(data, obj.data);
}

int char_seed::mutate()
{
    if(!data) return -1;
    std::random_device r;
    std::default_random_engine gen{r()};
    std::uniform_int_distribution<int> dist_index(0, SEED_LEN);
    std::uniform_int_distribution<char> dist_char(32, 127);
    int index = dist_index(gen);
    char new_char = dist_char(gen);

    data[index] = new_char;
    return index;
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
    if (data)
        out << data;
    return out;
}

char_seed operator*(const char_seed &lhs, const char_seed &rhs)
{
    char_seed new_seed(lhs);
    for(int i = 0; i < SEED_LEN; ++i)
    {
        new_seed.data[i] |= rhs.data[i];
    }
    return new_seed;
}

/* Static functions */
char* char_seed::make_random_seed()
{
    std::random_device r{};
    std::mt19937 gen{r()};
    char* new_s = new char[SEED_LEN];

    for(int i = 0; i < SEED_LEN; ++i)
    {
        auto r_value = (int(normal_dist(gen)) % 93) + 32;
        new_s[i] = r_value;
    }

    return new_s;
}

char* char_seed::make_seed(unsigned int int_seed)
{
    std::mt19937 gen{int_seed};
    char* new_s = new char[SEED_LEN];

    for(int i = 0; i < SEED_LEN; ++i)
    {
        auto r_value = (int(normal_dist(gen)) % 93) + 32;
        new_s[i] = r_value;
    }

    return new_s;
}

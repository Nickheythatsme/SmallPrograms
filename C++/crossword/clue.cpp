#include "clue.h"

// CONSTRUCTOR 
Clue::Clue()
{
    location.h = 0;
    location.w = 0;
    vertical = false;
}

// CONSTRUCTOR
Clue::Clue(const string &nclue, const string &nanswer)
{
    clue       = nclue;
    answer     = nanswer;
    location.h = 0;
    location.w = 0;
    vertical = false;
}

// COPY CONSTRUCTOR
Clue::Clue(const Clue &obj)
{
    clue       = obj.clue;
    answer     = obj.answer;
    location   = obj.location;
    vertical   = obj.vertical;
}

/* Read the clue in from a file */
std::ifstream& operator>>(std::ifstream& in, Clue &obj)
{
    char buff[1024];

    // Get the clue
    in.get(buff, 1024, ',');
    in.ignore(1024,',');
    obj.clue = buff;

    // Get the answer
    in.get(buff, 1024, ',');
    in.ignore(1024,',');
    obj.answer = buff;

    return in;
}

/* Formatted output */
std::ostream& operator<<(std::ostream& out, const Clue &obj)
{
    out << obj.clue << ": " << obj.answer;
    return out;
}

/* Return true if obj < obj2. Return false if otherwise */
bool Clue::Compare(const Clue &obj, const Clue &obj2)
{
    return obj.Length() < obj2.Length();
}

void Clue::Place(const Vec &nlocation, bool isVertical) 
{
    location = nlocation; 
    vertical = isVertical;
}

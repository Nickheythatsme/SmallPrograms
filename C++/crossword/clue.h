#include "grid.h"
#include <fstream>

#ifndef CLUE_
#define CLUE_

#define CLUE_VERTICAL   true
#define CLUE_HORIZONTAL false

class Clue
{
    public:
        Clue();
        Clue(const string &clue, const string &answer);
        Clue(const Clue &obj);
        ~Clue() = default;

        /* Extraction/insertion operators */
        friend std::ifstream& operator>>(std::ifstream& in, Clue &obj);
        friend std::ostream&  operator<<(std::ostream& out, const Clue &obj);

        /* Set/get the location of the clue in the grid */
        void Place(const Vec &nlocation, bool vertical);
        Vec Placement() const {return location;}
        bool isVertical() {return vertical;}

        /* Return the length of the answer */
        unsigned long Length() const   {return answer.length();}

        /* Return the clue/answer */
        string getClue() const         {return clue;}
        string getAnswer() const       {return answer;}

        /* Return true if obj < obj2. Return false if otherwise */
        static bool Compare(const Clue &obj, const Clue &obj2);
    protected:
    private:
        string clue;
        string answer;
        Vec location;
        bool vertical;
};

#endif //CLUE_

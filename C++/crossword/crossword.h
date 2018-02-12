#include "grid.h"
#include "clue.h"
#include <random>
#include <algorithm>
#include <map>

using std::map;

#ifndef CROSSWORD_
#define CROSSWORD_

class Crossword : public Grid
{
    public:
        Crossword() = delete;
        Crossword(const vector<Clue> &nclues);
        Crossword(const Crossword &obj);
        ~Crossword();

        /* Make the puzzle with the current clues */
        int MakePuzzle();

        /* Add clues to the current list of clues */
        void AddClues(const vector<Clue> &nclues);

        /* Formatted output to a stream */
        friend std::ostream& operator<<(std::ostream &out, const Crossword &obj);
    protected:
        vector<Vec> FindUsedSpots();
        int PlaceWord(const string &new_word);
    private:
        /* Place the largest word first, at random */
        void PlaceFirst();
        /* Place a word starting at the start. Will be placed either vertical or 
         * horizontal.
         * Returns
         * True for success
         * False for failure (the word won't fit) */
        bool InsertWord(Vec start, const string &word, bool vertical);
        bool InsertHorizontal(Vec &start, const string &word);
        bool InsertVertical(Vec &start, const string &word);
        vector<Clue> clues;
};

#endif //CROSSWORD_

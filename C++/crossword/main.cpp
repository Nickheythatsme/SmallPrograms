#include "crossword.h"
#include <algorithm>
#include "clue.h"

using namespace std;

/* Read clues in from a file */
auto ReadClues(char *fname)
{
    vector<Clue> clues;
    Clue temp_clue;
    ifstream fin(fname);

    if(!fin) return clues;

    fin >> temp_clue;
        fin.ignore(1024,'\n');
    while( fin.good() )
    {
        clues.push_back(temp_clue);
        fin >> temp_clue;
        fin.ignore(1024,'\n');
    }

    /* Sort the clues from lowest length to highest */
    std::sort(clues.begin(), clues.end(), Clue::Compare);
    return clues;
}

int main(int argc, char **argv)
{
    if( argc != 2 )
    {
        cout << "Usage: ./crossword [clues.csv file]" << endl;
        exit(EXIT_FAILURE);
    }
    auto clues = ReadClues(argv[1]);
    Crossword crossword(clues);

    cout << clues.size() << endl;
    cout << crossword.Dimensions().w << endl;
    cout << crossword.Dimensions().h << endl;

    crossword.MakePuzzle();
    cout << crossword << endl;

    return 0;
}

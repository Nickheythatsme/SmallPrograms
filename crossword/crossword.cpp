#include "crossword.h"

// CONSTRUCTOR
Crossword::Crossword(const vector<Clue> &nclues) : 
    Grid(),
    clues(nclues)
{
    /* Sort the clues from lowest length to highest */
    std::sort(clues.begin(), clues.end(), Clue::Compare);

    /* Resize the graph to fit the answers */
    Grid::Resize(Vec(clues[clues.size() - 1].Length() * 1.5));
}

// COPY CONSTRUCTOR
Crossword::Crossword(const Crossword &obj) : 
    Grid(obj),
    clues(obj.clues)
{
}

// DESTRUCTOR
Crossword::~Crossword()
{
}

// TODO finish making puzzle
/* Make the puzzle with the current clues */
int Crossword::MakePuzzle()
{
    Draw();
    PlaceFirst();
    // TODO give the right words to PlaceWord
    PlaceWord("THIS");
    return 0;
}

/* Find all of the spots that have been used in the grid */
vector<Vec> Crossword::FindUsedSpots()
{
    vector<Vec> locations;
    for(auto i = 0u; i < dimensions.h; ++i)
    {
        for(auto j = 0u; j < dimensions.w; ++j)
            if(grid[i][j] != CLOSED)
                locations.push_back(Vec(i,j));
    }

    return locations;
}

/* Place a word into the grid.
 * Returns:
 * 1 if success
 * 0 if no spots are available
 */
int Crossword::PlaceWord(const string &new_word)
{
    srand(clock());
    auto locations = FindUsedSpots();

    for(auto loc : locations)
    {
        for(auto c : new_word)
        {
            std::cout << loc.w << '\t' << loc.h << std::endl;
            std::cout << c << '\t' << grid[loc.h][loc.w] << std::endl;

            if(grid[loc.h][loc.w] == c)
            {
                if(InsertWord(loc, new_word, CLUE_VERTICAL))
                    return 1;
            }
        }
    }

    return 1;
}

/* Since the first word doesn't rely on anything, it has to be placed at random.
 * We use the largest word to start */
void Crossword::PlaceFirst()
{
    srand(clock());
    Clue first_clue = clues.back();
    string answer = first_clue.getAnswer();

    // Determine the new random location 
    unsigned max_width = dimensions.w - first_clue.Length() + 1;
    Vec location(
        rand() % dimensions.h, // height
        rand() % max_width     // width
        );

    first_clue.Place(location, CLUE_HORIZONTAL);

    // Insert the word into the grid
    InsertWord(location, answer, CLUE_HORIZONTAL);


    //TODO we need some way to indicate when a word has been added.
}

/* Add clues to the current list of clues */
void Crossword::AddClues(const vector<Clue> &nclues)
{
    for(auto x : nclues)
        clues.push_back(x);

    /* Sort the clues from lowest length to highest */
    std::sort(clues.begin(), clues.end(), Clue::Compare);
}

/* Formatted output to a stream */
std::ostream& operator<<(std::ostream &out, const Crossword &obj)
{
    obj.display(out);
    for(auto x : obj.clues)
        out << x << std::endl;
    return out;
}

/* Insert a word. Will either insert horizontally or vertically.
 * Returns 
 * True for success
 * False for failure (if a word won't fit) */
bool Crossword::InsertWord(Vec start, const string &word, bool vertical)
{
    if(vertical)
        return InsertVertical(start, word);
    else
        return InsertHorizontal(start, word);
}

/* Insert word horizontally
 * True for success
 * False for failure (if a word won't fit) */
bool Crossword::InsertHorizontal(Vec &start, const string &word)
{
    // Test if a word fits 
    if(start.w + word.length() > dimensions.w)
        return false;

    // Check if there's already a word there 
    for(auto i = 0u; i < word.length(); ++i)
        if(grid[start.h][start.w + i] != CLOSED &&
                grid[start.h][start.w + i] != word[i])
            return false;

    // Draw the word onto the grid
    for(auto i = 0u; i < word.length(); ++i)
        grid[start.h][start.w + i] = word[i];

    return true;
}

/* Insert word vertically
 * True for success
 * False for failure (if a word won't fit) */
bool Crossword::InsertVertical(Vec &start, const string &word)
{
    // Test if a word fits 
    if(start.h + word.length() >= dimensions.h)
        return false;

    // Check if there's already a word there 
    for(auto i = 0u; i < word.length(); ++i)
        if(grid[start.h + i][start.w] != CLOSED &&
                grid[start.h + i][start.w] != word[i])
            return false;

    // Draw the word onto the grid
    for(auto i = 0u; i < word.length(); ++i)
        grid[start.h + i][start.w] = word[i];

    return true;
}
